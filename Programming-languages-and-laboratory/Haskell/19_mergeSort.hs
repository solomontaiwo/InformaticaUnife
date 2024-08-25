import Data.List
import System.IO

msort [] = [] 
msort [x] = [x]
msort xs = merge (msort (take (div (length xs) 2) xs))(msort (drop (div (length xs) 2) xs))