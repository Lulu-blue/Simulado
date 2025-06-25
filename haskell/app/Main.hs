{-# LANGUAGE RecordWildCards #-}

module Main where

import qualified DataStructures.Queue as Q
import qualified DataStructures.Stack as S
import qualified DataStructures.List as L
import Benchmark
import Types
import Utils
import Text.Printf
import System.Environment (getArgs)

main :: IO ()
main = do
    args <- getArgs
    let sizes = case args of
                  [] -> [100, 1000, 10000, 100000, 1000000] 
                  xs -> map read xs      
    
    putStrLn "=== Benchmark de Estruturas de Dados ==="
    putStrLn "=== Comparação entre implementações com Ponteiros e Vectors ==="
    
    results <- mapM runBenchmarkForSize sizes

    putStrLn "\n=== Resumo Comparativo ==="
    mapM_ printSummary results

runBenchmarkForSize :: Int -> IO [(String, Double, Double)]
runBenchmarkForSize size = do
    putStrLn $ "\nTamanho: " ++ show size ++ " elementos"
    putStrLn $ replicate 60 '-'
    
    data <- generateTestData size

    queuePRes <- testQueuePointer data
    queueVRes <- testQueueVector data
    stackPRes <- testStackPointer data
    stackVRes <- testStackVector data
    listPRes <- testListPointer data
    listVRes <- testListVector data

    let results = [ ("Fila Ponteiro", time queuePRes, memory queuePRes)
                  , ("Fila Vetor", time queueVRes, memory queueVRes)
                  , ("Pilha Ponteiro", time stackPRes, memory stackPRes)
                  , ("Pilha Vetor", time stackVRes, memory stackVRes)
                  , ("Lista Ponteiro", time listPRes, memory listPRes)
                  , ("Lista Vetor", time listVRes, memory listVRes)
                  ]

    mapM_ (\(name, t, m) -> 
        printf "%-15s | Tempo: %8.5f s | Memória: %8.2f KB\n" name t m) results
    
    return results

printSummary :: [(String, Double, Double)] -> IO ()
printSummary results = do
    putStrLn $ "\nMelhores resultados para tamanho:"
    let bestTime = minimumBy (comparing (\(_,t,_) -> t)) results
    let bestMem = minimumBy (comparing (\(_,_,m) -> m)) results
    
    printf "Melhor tempo:  %-15s (%.5f s)\n" (fst3 bestTime) (snd3 bestTime)
    printf "Melhor memória: %-15s (%.2f KB)\n" (fst3 bestMem) (trd3 bestMem)
  where
    fst3 (x,_,_) = x
    snd3 (_,x,_) = x
    trd3 (_,_,x) = x
    comparing f x y = compare (f x) (f y)