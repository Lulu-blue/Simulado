{-# LANGUAGE RecordWildCards #-}

module Main where

import System.Random (randomRIO)
import Data.Time.Clock (getCurrentTime, diffUTCTime)
import qualified Data.Heap as H
import qualified Data.List as L
import qualified Data.Vector as V
import Text.CSV (parseCSVFromFile)
import System.Environment (getArgs)
import Data.Maybe (fromMaybe)

-- Tipos de dados para representar as estruturas e o registro do CSV
data Rating = Rating
    { userId :: Int
    , movieId :: Int
    , rating :: Double
    , timestamp :: Int
    } deriving (Show)

-- Tipos para estruturas de dados
type FilaPonteiro a = [a]
type FilaVetor a = V.Vector a
type ListaPonteiro a = [a]
type PilhaPonteiro a = [a]
type PilhaVetor a = V.Vector a

maxSize :: Int
maxSize = 100000

-- Operações básicas para FilaPonteiro
enfileirarP :: a -> FilaPonteiro a -> FilaPonteiro a
enfileirarP = (:)

desenfileirarP :: FilaPonteiro a -> (Maybe a, FilaPonteiro a)
desenfileirarP [] = (Nothing, [])
desenfileirarP xs = (Just $ L.last xs, L.init xs)

-- Operações básicas para FilaVetor
enfileirarV :: a -> FilaVetor a -> Maybe (FilaVetor a)
enfileirarV x fila
  | V.length fila >= maxSize = Nothing
  | otherwise = Just (V.cons x fila)

desenfileirarV :: FilaVetor a -> (Maybe a, FilaVetor a)
desenfileirarV fila
  | V.null fila = (Nothing, V.empty)
  | otherwise = (Just $ V.last fila, V.init fila)

-- Heap Sort genérico
heapSort :: Ord a => [a] -> [a]
heapSort = H.toList . H.fromList

-- Ler dados do arquivo CSV
lerRatings :: FilePath -> IO [Double]
lerRatings caminho = do
    result <- parseCSVFromFile caminho
    case result of
        Left err -> do
            putStrLn $ "Erro ao ler arquivo: " ++ err
            return []
        Right csv -> do
            let ratings = [read (ratingStr) :: Double | (_:ratingStr:_) <- csv]
            return ratings

-- Funções para testar o desempenho
testarHeapSort :: String -> ([Double] -> [Double]) -> [Double] -> IO ()
testarHeapSort nome funcao dados = do
    inicio <- getCurrentTime
    let resultado = funcao dados
    fim <- getCurrentTime
    let tempo = realToFrac (diffUTCTime fim inicio) :: Double
    putStrLn $ nome ++ " " ++ show (length dados) ++ " elementos: " ++ show tempo ++ "s"
    print (sum resultado `seq` ()) -- Força avaliação

-- Função principal
main :: IO ()
main = do
    args <- getArgs
    let caminhoCSV = fromMaybe "data/ratings.csv" (L.headMay args)
    
    putStrLn $ "Lendo dados de: " ++ caminhoCSV
    ratings <- lerRatings caminhoCSV
    
    let tamanhos = [100, 1000, 10000, min 100000 (length ratings)]
    putStrLn "=== Benchmark Heap Sort (tempos em segundos) ==="
    
    mapM_ (\tamanho -> do
        let dados = take tamanho ratings
        putStrLn $ "\nTestando com " ++ show tamanho ++ " elementos:"
        
        -- Testar com listas padrão (equivalente a vetor)
        testarHeapSort "Lista (vetor)   " heapSort dados
        
        -- Testar com fila baseada em lista
        let filaP = foldr enfileirarP [] dados
        inicio <- getCurrentTime
        let resultadoP = heapSort filaP
        fim <- getCurrentTime
        let tempo = realToFrac (diffUTCTime fim inicio) :: Double
        putStrLn $ "Fila (ponteiro) " ++ show tamanho ++ " elementos: " ++ show tempo ++ "s"
        
        -- Testar com pilha baseada em lista
        let pilhaP = foldr (:) [] dados
        inicioP <- getCurrentTime
        let resultadoPilha = heapSort pilhaP
        fimP <- getCurrentTime
        let tempoP = realToFrac (diffUTCTime fimP inicioP) :: Double
        putStrLn $ "Pilha (ponteiro)" ++ show tamanho ++ " elementos: " ++ show tempoP ++ "s"
        
        ) tamanhos