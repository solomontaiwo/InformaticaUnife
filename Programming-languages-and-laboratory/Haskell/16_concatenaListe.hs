import System.IO
import Data.List

concatena [] ys = ys
concatena (x:xs) ys = x:(concatena xs ys)