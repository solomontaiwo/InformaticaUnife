import Data.List
import System.IO

merge (x:xs) (y:ys)
    | x>y = y:merge (x:xs) ys
    | otherwise = x:merge xs (y:ys)
merge [] ys = ys 
merge xs [] = xs