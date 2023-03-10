
''' parser_gen
    Generate code to use the parser built
'''

import parser_gen as pgen

import sys

class CppGenerator:
    ''' CppGenerator
        Automate parser code generation, we will do this by simply printing code to a file 
    '''
    def __init__(self, grammar, code_fname):
        self.grammar = grammar
        self.code_fname = code_fname
        with open(code_fname, 'w') as f:
            pass

    def _write(self, s):
        with open(self.code_fname, 'a') as f:
            f.write(s)

    def setHeaders(self):
        self._write("/* Generated LALR parser from handwritten parser_gen.py */\n\n")
        self._write("#include<map>\n#include<vector>\n\n")

    def setSymbols(self):
        ''' write the symbols used by tokens and gramar'''

        # terminals first
        self._write("/* TokenType \n    also terminal symbols\n/*\n")
        self._write("enum TokenType {\n")
        for idx,terminal in enumerate(self.grammar.terminal_symbols):
            self._write("\t{}={},\n".format(terminal.symbol,idx))
        self._write("};\n\n\n")

        # nonterminals
        self._write("/* NonterminalSymbol \n    the nonterminal symbols for the grammar\n/*\n")
        offset = len(self.grammar.terminal_symbols) + 10 # set different enum values for the nonterminals
        self._write("enum NonterminalSymbol {\n")
        for idx,nonterminal in enumerate(self.grammar.nonterminal_symbols):
            self._write("\t{}={},\n".format(nonterminal.symbol, idx+offset))
        self._write("};\n\n\n")



def main():
    # this is the inefficient LALR construction 
    grammar = pgen.Grammar()
    grammar.readGrammarFile(sys.argv[1])
    grammar.makeFirstSets()
    grammar.makeFollowSets()
    ## this is the LALR construciton from LR(1) items
    grammar.makeLR1Items()
    grammar.makeLR1Cores()
    grammar.makeLALRActionTable()

    # Now we try to generate the code
    cpp_gen = CppGenerator(grammar, 'LALRTables.h')
    cpp_gen.setHeaders()
    cpp_gen.setSymbols()


if __name__=='__main__':
    main()
