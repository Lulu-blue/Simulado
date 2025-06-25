module Benchmark
  ( MeasureResult(..)
  , generateTestData
  , testQueuePointer
  , testQueueVector
  , testStackPointer
  , testStackVector
  , testListPointer
  , testListVector
  ) where

import DataStructures.Queue
import DataStructures.Stack
import DataStructures.List
import Types
import Utils
import Data.Time.Clock
import System.Process
import Control.Exception
import qualified Data.Vector as V
import System.Random (randomRIO)

data MeasureResult = MeasureResult
  { time :: Double
  , memory :: Double
  , structureName :: String
  }

generateTestData :: Int -> IO [Int]
generateTestData n = sequence $ replicate n (randomRIO (1, 100000))

measurePerformance :: String -> IO a -> IO MeasureResult
measurePerformance name action = do
    memStart <- getMemoryUsage
    start <- getCurrentTime
    result <- action
    evaluate result 
    end <- getCurrentTime
    memEnd <- getMemoryUsage
    let timeDiff = realToFrac (diffUTCTime end start) :: Double
    return MeasureResult
      { time = timeDiff
      , memory = memEnd - memStart
      , structureName = name
      }

testQueuePointer :: [Int] -> IO MeasureResult
testQueuePointer data = measurePerformance "Fila Ponteiro" $ do
    let queue = foldr Q.enqueueP Q.emptyQueueP data
    let (_, queue') = foldl (\(_, q) _ -> Q.dequeueP q) (Nothing, queue) [1..length data]
    return queue'

testQueueVector :: [Int] -> IO MeasureResult
testQueueVector data = measurePerformance "Fila Vetor" $ do
    let queue = foldr Q.enqueueV Q.emptyQueueV (V.fromList data)
    let (_, queue') = foldl (\(_, q) _ -> Q.dequeueV q) (Nothing, queue) [1..length data]
    return queue'

testStackPointer :: [Int] -> IO MeasureResult
testStackPointer data = measurePerformance "Pilha Ponteiro" $ do
    let stack = foldr S.pushP S.emptyStackP data
    let (_, stack') = foldl (\(_, s) _ -> S.popP s) (Nothing, stack) [1..length data]
    return stack'

testStackVector :: [Int] -> IO MeasureResult
testStackVector data = measurePerformance "Pilha Vetor" $ do
    let stack = foldr S.pushV S.emptyStackV (V.fromList data)
    let (_, stack') = foldl (\(_, s) _ -> S.popV s) (Nothing, stack) [1..length data]
    return stack'

testListPointer :: [Int] -> IO MeasureResult
testListPointer data = measurePerformance "Lista Ponteiro" $ do
    let list = L.fromListP data
    return $ L.mapP (+1) list

testListVector :: [Int] -> IO MeasureResult
testListVector data = measurePerformance "Lista Vetor" $ do
    let list = L.fromListV data
    return $ L.mapV (+1) list