import Data.List
import System.IO

zip' (x:xs) (y:ys) = (x,y) : zip' xs ys
zip' __ = []