module DataStructures.Stack
  ( StackPointer
  , StackVector
  , pushP
  , popP
  , pushV
  , popV
  , emptyStackP
  , emptyStackV
  ) where

import qualified Data.Vector as V

type StackPointer a = [a]

emptyStackP :: StackPointer a
emptyStackP = []

pushP :: a -> StackPointer a -> StackPointer a
pushP = (:)

popP :: StackPointer a -> (Maybe a, StackPointer a)
popP [] = (Nothing, [])
popP (x:xs) = (Just x, xs)


type StackVector a = V.Vector a

emptyStackV :: StackVector a
emptyStackV = V.empty

pushV :: a -> StackVector a -> StackVector a
pushV = V.cons

popV :: StackVector a -> (Maybe a, StackVector a)
popV stack
  | V.null stack = (Nothing, V.empty)
  | otherwise = (Just (V.head stack), V.tail stack)