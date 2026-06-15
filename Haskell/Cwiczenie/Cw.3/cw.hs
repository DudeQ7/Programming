funkcja1:: Float -> Float
funkcja1 x=(a* (sin b) / (b*b*b - 6*a))
    where
    a=(sqrt x)
    b=2*x+3
--silnia
silnia:: Integer -> Integer
silnia 0 = 1 
silnia n = n*silnia(n-1)