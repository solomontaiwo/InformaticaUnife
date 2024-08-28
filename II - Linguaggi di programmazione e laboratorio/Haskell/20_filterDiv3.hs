import Data.List
import System.IO

div3 :: Int -> Bool
div3 n = (mod n 3)==0 
filterDiv3 xs = filter div3 xs