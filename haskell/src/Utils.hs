module Utils
  ( getMemoryUsage
  , getProcessID
  , printResults
  ) where

import System.Process (readProcess)
import Text.Printf (printf)

-- Obtém uso de memória em KB
getMemoryUsage :: IO Double
getMemoryUsage = do
    pid <- getProcessID
    memInfo <- readProcess "ps" ["-o", "rss=", "-p", show pid] ""
    return (read memInfo / 1024)

-- Obtém ID do processo
getProcessID :: IO Int
getProcessID = read <$> readProcess "bash" ["-c", "echo $PPID"] ""

-- Formata resultados para exibição
printResults :: [(String, Double, Double)] -> IO ()
printResults results = do
    putStrLn "\nResultados:"
    putStrLn $ replicate 60 '-'
    mapM_ (\(name, t, m) -> 
        printf "%-15s | Tempo: %8.5f s | Memória: %8.2f KB\n" name t m) results