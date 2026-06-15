funkcja1:: Float -> Float
funkcja1 x=(a* (sin b) / (b*b*b - 6*a))
    where
    a=(sqrt x)
    b=2*x+3
--silnia
silnia:: Integer -> Integer
silnia 0 = 1 
silnia n = n*silnia(n-1)

silnia2:: Integer -> Maybe Integer
silnia2 n 
    | n < 0 =Nothing
    | n==0 = Just 1
    | otherwise = Just (n * fromJust (silnia2 (n-1)))

potega:: Integer -> Integer -> Integer
    potega a 0 = 1
    potega a b = a * potega a (b-1)