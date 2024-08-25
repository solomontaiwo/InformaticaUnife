import Data.List
import System.IO

replica 0 x = []
replica n x = x:replicate (n-1) x