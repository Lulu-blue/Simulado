module Types
  ( MeasureResult(..)
  , QueuePointer
  , QueueVector
  , StackPointer
  , StackVector
  , ListPointer
  , ListVector
  ) where

import qualified Data.Vector as V

-- Tipos para resultados de benchmark
data MeasureResult = MeasureResult
  { time :: Double
  , memory :: Double
  , structureName :: String
  }

-- Tipos para estruturas de dados (re-exportados dos módulos específicos)
type QueuePointer a = [a]
type QueueVector a = V.Vector a
type StackPointer a = [a]
type StackVector a = V.Vector a
type ListPointer a = [a]
type ListVector a = V.Vector a