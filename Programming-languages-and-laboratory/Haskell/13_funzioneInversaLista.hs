import Data.List
import System.IO

inversa [] = []
inversa (x:xs) = (inversa xs) ++ [x]