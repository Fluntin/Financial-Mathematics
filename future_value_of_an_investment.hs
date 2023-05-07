{-# LANGUAGE ScopedTypeVariables #-}

module Finance where

data Investment = Investment
  { principal :: Double
  , interestRate :: Double
  , time :: Double
  , compoundingPeriods :: Double
  } deriving (Show)

futureValue :: Investment -> Double
futureValue (Investment p r t n) = p * (1 + r/n) ** (n * t)

main :: IO ()
main = do
  putStrLn "Enter the initial investment principal:"
  principal <- readLn :: IO Double

  putStrLn "Enter the annual interest rate (as a decimal):"
  interestRate <- readLn :: IO Double

  putStrLn "Enter the time (in years) of the investment:"
  time <- readLn :: IO Double

  putStrLn "Enter the number of compounding periods per year:"
  compoundingPeriods <- readLn :: IO Double

  let investment = Investment principal interestRate time compoundingPeriods
      futureVal = futureValue investment

  putStrLn $ "The future value of the investment is: " ++ show futureVal
