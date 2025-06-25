module DataStructures.Queue
  ( QueuePointer
  , QueueVector
  , enqueueP
  , dequeueP
  , enqueueV
  , dequeueV
  ) where

import qualified Data.Vector as V

type QueuePointer a = [a]
type QueueVector a = V.Vector a

enqueueP :: a -> QueuePointer a -> QueuePointer a
enqueueP = (:)

dequeueP :: QueuePointer a -> (Maybe a, QueuePointer a)
dequeueP [] = (Nothing, [])
dequeueP xs = (Just $ last xs, init xs)

enqueueV :: a -> QueueVector a -> QueueVector a
enqueueV x queue = V.cons x queue

dequeueV :: QueueVector a -> (Maybe a, QueueVector a)
dequeueV queue
  | V.null queue = (Nothing, V.empty)
  | otherwise = (Just $ V.last queue, V.init queue)