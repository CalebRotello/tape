import System.Environment

main :: IO()
main = getArgs >>= print . tape . head

tape s = "Tape! " ++ s
