main :: IO ()
main = do
  putStrLn "Hello, World!"
  let result = addNumbers 5 3
  putStrLn ("5 + 3 = " ++ show result)

addNumbers :: Int -> Int -> Int
addNumbers a b = a + b
