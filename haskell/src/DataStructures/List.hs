module DataStructures.List
  ( ListPointer
  , ListVector
  , mapP
  , mapV
  , emptyListP
  , emptyListV
  , fromListP
  , fromListV
  ) where

import qualified Data.Vector as V

type ListPointer a = [a]

emptyListP :: ListPointer a
emptyListP = []

fromListP :: [a] -> ListPointer a
fromListP = id

mapP :: (a -> b) -> ListPointer a -> ListPointer b
mapP = fmap

type ListVector a = V.Vector a

emptyListV :: ListVector a
emptyListV = V.empty

fromListV :: [a] -> ListVector a
fromListV = V.fromList

mapV :: (a -> b) -> ListVector a -> ListVector b
mapV = V.map