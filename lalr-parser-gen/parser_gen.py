''' parsen_gen
    Caleb Rotello, February 2023

    A python module which will, given a context-free grammar, create the parsing table structures.

    A seperate file will generate the code

'''


import sys


class Grammar:
    def __init__(self):
        self.rules = [] #readGrammarFile
        self.nonterminal_to_rule = {} #readGrammarFile       
        self.terminal_symbols = set() #readGrammarFile
        self.nonterminal_symbols = set() #readGrammarFile
        self.rules_to_enumeration = {} #readGrammarFile

        self.start_rule = None #readGrammarFile
        # augment the grammar in readGrammarFile  with info below
        self.start_symbol = Symbol('PARSER_START', False)
        self.nonterminal_symbols.add(self.start_symbol)
        self.end_symbol = Symbol('FINISH', True) # NOTE does this need to be terminal or nonterminal?
        self.terminal_symbols.add(self.end_symbol)

        self.first_sets = {} #makeFirstSets
        self.follow_sets = {} #makeFollowSets

        self.first_item = None #makeLR1Items
        self.set_of_item_sets = {} #makeLR1Items set of item sets
        self.goto_lr1_table = {} #makeLR1Items goto table for LR(1) items

        self.item_cores_to_item_sets = {} #makeLR1Cores map cores -> list(item set)
        self.item_sets_to_item_cores = {} #makeLR1Cores map item set -> cores
        self.item_cores_to_enumeration = {} #enuemrateLALRTables
        self.enumeration_to_item_cores = {} #enuemrateLALRTables

        self.action_lalr_table = {} #makeLALRActionTable
        self.goto_lalr_table = {} #makeLALRActionTable


    def makeLALRActionTable(self):
        ''' make the action and goto table for our item sets
        '''
        #item_sets = self.set_of_item_cores if len(self.set_of_item_cores) == 0 else self.set_of_item_sets
        for item_cores, item_sets in self.item_cores_to_item_sets.items():
            self.action_lalr_table[item_cores] = {}
            self.goto_lalr_table[item_cores] = {}
            # each core points to a list of item sets
            for item_set in item_sets:
                # each item in item set, add rules depending on the item type
                for item in item_set.getItems():
                    # TODO: error catching, currently we just overwrite the conflict
                    if item.getNextSymbol() is None and item.rule.getLeftSide() != self.start_symbol:
                        self.action_lalr_table[item_cores][item.getLookaheadTerminal()] = ('reduce', item.rule)
                    elif item.getNextSymbol() is not None and item.getNextSymbol().is_terminal and item.getNextSymbol() in self.goto_lr1_table[item_set].keys(): 
                        shift_to = self.item_sets_to_item_cores[self.goto_lr1_table[item_set][item.getNextSymbol()]]
                        self.action_lalr_table[item_cores][item.getNextSymbol()] = ('shift', shift_to)
                    elif item == self.first_item:
                        self.action_lalr_table[item_cores][self.end_symbol] = ('accept', None)
                    elif item.getNextSymbol() is not None and not item.getNextSymbol().is_terminal:
                        goto_to = self.item_sets_to_item_cores[self.goto_lr1_table[item_set][item.getNextSymbol()]]
                        self.goto_lalr_table[item_cores][item.getNextSymbol()] = goto_to

    def enumerateLALRTables(self): 
        ''' with the action and goto tables completed, enumerate item set cores and write enumerated tables
        '''
        # enumerate the items
        for i,item_cores in enumerate(self.item_cores_to_item_sets.keys()):
            self.item_cores_to_enumeration[item_cores] = i

        # print an enumerated action table
        for item_cores,actions in self.action_lalr_table.items():
            s = str(self.item_cores_to_enumeration[item_cores]) + ' -->> '
            for symbol,action in actions.items():
                if action[0] == 'shift':
                    a = self.item_cores_to_enumeration[action[1]]
                elif action[0] == 'reduce':
                    a = self.rules_to_enumeration[action[1]]
                else:
                    a = 'null'
                s += '[' + str(symbol) + ', (' + action[0] + ', ' + str(a) + ')] '
            print(s)

    def makeLR1Cores(self):
        ''' get the core of the LR(1) items '''
        # form maps between cores and items
        for item_set in self.set_of_item_sets:
            item_cores = item_set.getItemCores()
            if item_cores not in self.item_cores_to_item_sets.keys():
                self.item_cores_to_item_sets[item_cores] = []
            self.item_sets_to_item_cores[item_set] = item_cores
            self.item_cores_to_item_sets[item_cores].append(item_set)

    def makeLR1Items(self):
        ''' Get the set of LR(1) items, for inefficient LALR construction
        '''
        self.first_item = Item(self.start_rule, 0, self.end_symbol)
        closed_first_item = self.closure(ItemSet(set([self.first_item])))
        self.set_of_item_sets = set([closed_first_item])
        Q = [closed_first_item]
        while len(Q) != 0:
            item_set = Q.pop(0)
            self.goto_lr1_table[item_set] = {} # goto table for as we go
            for symbol in self.nonterminal_symbols|self.terminal_symbols:
                if symbol in [self.start_symbol, self.end_symbol]: continue
                g = self.goto(item_set, symbol)
                if g is not None:
                    # TODO: this needs an error check
                    self.goto_lr1_table[item_set][symbol] = g
                    # next-up items to search goto
                    if len(g.getItems()) != 0 and g not in self.set_of_item_sets:
                        self.set_of_item_sets.add(g)
                        Q.append(g)                 

    
    def closure(self, item_set):
        ''' close an item set '''
        Q = []
        [Q.append(item) for item in item_set.getItems()] # NOTE we assume that no terminal derives lambda
        while len(Q) != 0:
            item = Q.pop(0)
            next_symbol = item.getNextSymbol() # nonterminal immediately right of marker 
            next_next_symbol = item.getNextNextSymbol()
            next_next_symbol = next_next_symbol if next_next_symbol is not None else item.getLookaheadTerminal()
            if next_symbol is None or next_symbol.is_terminal:
                continue
            for rule in self.nonterminal_to_rule[next_symbol]:
                for terminal in self.first_sets[next_next_symbol]:
                    new_item = Item(rule, 0, terminal)
                    if new_item  not in item_set.getItems():
                        item_set.addItem(new_item) # add items to set before queue, prevents double-adding
                        if not new_item.getNextSymbol().is_terminal: # if the new item has nonterminal we can close it
                            Q.append(new_item)
        return item_set
    
    def goto(self, item_set, symbol):
        ''' over the item_set, return the closed item set accessible from transitions on symbol 
            if no item accessible from symbol, return None
        '''
        next_item_set = ItemSet(set())
        for item in item_set.getItems():
            next_symbol = item.getNextSymbol()
            if next_symbol is not None and next_symbol == symbol:
                next_item_set.addItem(Item(item.rule, item.marker + 1, item.getLookaheadTerminal())) # get item, progressed over symbol
        # if there are not items in Goto, we should return nothing
        if len(next_item_set.getItems()) == 0:
            return None
        return self.closure(next_item_set)



    def readGrammarFile(self, fname):
        ''' read grammar from fname
            all rules MUST be Nonterminal = Rule
            lowercase -> terminal
        '''
        print('Reading grammar from {}'.format(fname))
        with open(fname, 'r') as f:
            for line in f:
                itemized_line = line.split()
                if len(itemized_line) == 0: 
                    continue
                # TODO check for errors in parsing, logical consistency
                # get the left side of the rule
                left_side = Symbol(itemized_line[0], False)
                self.nonterminal_symbols.add(left_side)

                # get the right side
                right_side = []
                for symbol in itemized_line[2:]:
                    is_terminal =  not symbol[0].isupper() #isupper bc nonterminals are uppercase
                    right_side_symbol = Symbol(symbol, is_terminal)                    
                    right_side.append(right_side_symbol)

                    if is_terminal:
                        self.terminal_symbols.add(right_side_symbol)
                    # NOTE because nonterminals already handled above

                # make the rule and add it to the grammar
                rule = Rule(left_side, right_side)
                self.rules.append(rule)
                self.rules_to_enumeration[rule] = len(self.rules) - 1 # index of the rule

                # this is useful for some of the algorithms
                if left_side not in self.nonterminal_to_rule.keys():
                    self.nonterminal_to_rule[left_side] = [rule]
                else:
                    self.nonterminal_to_rule[left_side].append(rule)
        
        # NOTE rule[0] is the first rule, error check for multiple parent symbols
        # augment the grammar
        self.start_rule = Rule(self.start_symbol, [self.rules[0].getLeftSide()])#, self.end_symbol])
        self.nonterminal_to_rule[self.start_symbol] = [self.start_rule]
        self.rules.insert(0,self.start_rule)


    def makeFirstSets(self):
        ''' call getFirst on each nonterminal '''
        ###
        def getFirst(symbol):
            ''' recursive function to highlight which symbols need a first set computed "first" 
                fills in the first_sets table
            '''
            # if we already got first set, dont do again
            if symbol in self.first_sets.keys():
                return
            elif symbol.is_terminal:
                self.first_sets[symbol] = set([symbol])            
            else:
                # current symbols first set
                symbol_first_set = set() 
                self.first_sets[symbol] = set()
                # get first sets
                for rule in self.nonterminal_to_rule[symbol]:
                    first_in_rule = rule.getRightSide()[0]
                    # if first not calculated, calculate lower depth first
                    if first_in_rule not in self.first_sets.keys():
                        getFirst(first_in_rule) # recurse
                    # union
                    [symbol_first_set.add(s) for s in self.first_sets[first_in_rule]]

                self.first_sets[symbol] = symbol_first_set
        ###
        for symbol in self.nonterminal_symbols:
            getFirst(symbol)
        
        for symbol in self.terminal_symbols:
            getFirst(symbol)

    def makeFollowSets(self):
        ''' call getFollow on every nonterminal '''
        ###
        def getFollow(symbol):
            if symbol in self.follow_sets.keys(): # we already computed, dont recompute
                return
            else:
                symbol_follow_set = set()
                self.follow_sets[symbol] = set()
                # all symbols in the right hand side in all rules
                for rule in self.rules:
                    for i,_ in enumerate(rule.getRightSide()):
                        if rule.right_side[i] == symbol: 
                            # follow is the left-side of the rule
                            if i==len(rule.getRightSide())-1: 
                                if rule.left_side not in self.follow_sets.keys():
                                    getFollow(rule.getLeftSide()) # recurse
                                [symbol_follow_set.add(s) for s in self.follow_sets[rule.getLeftSide()]]
                            else: 
                                [symbol_follow_set.add(s) for s in self.first_sets[rule.getRightSide()[i+1]]]
                
                self.follow_sets[symbol] = symbol_follow_set
        ###
        for symbol in self.nonterminal_symbols:
            getFollow(symbol)


    def __str__(self):
        ''' Grammar print cast string '''
        s = 'Rules:\n'
        for rule in self.rules:
            s += str(rule) + '\n'
        return s

    def printGrammar(self):
        s = 'Rules:\n'
        for rule in self.rules:
            s += str(rule) + '\n'
        print(s)

    def printFirstSets(self):
        s = 'First Sets:\n'
        for key,value in self.first_sets.items():
            s += str(key) + ' : ' + str(value) +'\n'
        print(s)

    def printFollowSets(self):
        s = 'Follow Sets:\n'
        for key,value in self.follow_sets.items():
            s += str(key) + ' : ' + str(value) +'\n'
        print(s)

    def printGotoLR1Table(self):
        s = 'Goto Table:\n'
        for key,value in self.goto_lr1_table.items():
            s += '='*30 + '\n'
            s += str(key)
            s += '-'*30 + '\n'
            for sym,item in value.items():
                s += '\t'+str(sym)
                s += '----->' +str(item) +'\n'
            s += '-'*30 + '\n'
            s += '='*30 + '\n'
            s += '\n'
        print(s)





class ItemSet:
    def __init__(self, items):
        self.items = items

    def addItem(self, item):
        if item not in self.items:
            self.items.add(item)
    
    def getItems(self):
        return self.items

    def getItemCores(self):
        return tuple(set([item.getCore() for item in self.items])) 
    
    def __hash__(self):
        return hash(tuple([hash(item) for item in self.items]))

    def __eq__(self, other):
        return self.items == other.items

    def __repr__(self):
        return str(self)

    def __str__(self):
        s = 'ItemSet:\n'
        for item in self.items:
            s += str(item) + '\n'
        return s





class Item:
    def __init__(self, rule, marker, lookahead_terminal):
        self.rule = rule
        self.marker = marker
        self.lookahead_terminal = lookahead_terminal

    def getNextSymbol(self):
        return self.rule.getRightSide()[self.marker] if self.marker < len(self.rule.getRightSide()) else None

    def getNextNextSymbol(self):
        return self.rule.getRightSide()[self.marker+1] if self.marker < len(self.rule.getRightSide()) - 1 else None

    def getLookaheadTerminal(self):
        return self.lookahead_terminal

    def getCore(self):
        return (self.rule, self.marker)

    def __eq__(self, other):
        return self.rule == other.rule and self.marker == other.marker and self.lookahead_terminal == other.lookahead_terminal

    def __hash__(self):
        return hash((self.rule, self.marker, self.lookahead_terminal))

    def __str__(self):
        s = ''
        s += str(self.rule.left_side) + ' := ' 
        s += str(self.rule.getRightSide()[:self.marker])
        s += ' :M: '
        s += str(self.rule.getRightSide()[self.marker:])
        s += ' ; ' + str(self.lookahead_terminal)
        return s




class Rule:
    def __init__(self, left_side, right_side):
        self.left_side = left_side
        self.right_side = right_side

    def getRightSide(self):
        return self.right_side

    def getLeftSide(self):
        return self.left_side


    def __eq__(self, other):
        return self.left_side == other.left_side and self.right_side == other.right_side

    def __hash__(self):
        return hash((self.left_side, tuple(tuple([r for r in self.right_side]))))

    def __str__(self):
        return str(self.left_side) + ' := ' + str(self.right_side)

    def __repr__(self):
        return str(self)




class Symbol:
    def __init__(self, symbol, is_terminal):
        self.symbol = symbol
        self.is_terminal = is_terminal


    def __eq__(self, other):
        return self.symbol == other.symbol and self.is_terminal == other.is_terminal

    def __hash__(self):
        return hash((self.symbol, self.is_terminal))

    def __str__(self):
        s = 't' if self.is_terminal else 'n'
        return '('+self.symbol+', '+s+')'

    def __repr__(self):
        return str(self)




def main():
    # TODO streamline the 'official' workflows
    # Define the grammar
    grammar = Grammar()
    grammar.readGrammarFile(sys.argv[1])
    grammar.printGrammar()#

    # First and Follow are useful
    grammar.makeFirstSets()
    grammar.printFirstSets()#
    grammar.makeFollowSets()
    grammar.printFollowSets()#

    ### Inefficient LALR construction
    # Make LR(1) items
    grammar.makeLR1Items()
    grammar.printGotoLR1Table()#

    # Form set cores
    grammar.makeLR1Cores()

    # Make LALR actions
    grammar.makeLALRActionTable()
    grammar.enumerateLALRTables()


if __name__=="__main__":
    main()
