import Data.List
import System.IO

eliminaPrimi xs 0 = xs
eliminaPrimi (x:xs) n = eliminaPrimi xs (n-1)