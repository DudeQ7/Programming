funkcja1:: Float -> Float
funkcja1 x=(a* (sin b) / (b*b*b - 6*a))
    where
    a=(sqrt x)
    b=2*x+3
--silnia
silnia:: Integer -> Integer
silnia 0 = 1 
silnia n = n*silnia(n-1)


potega:: Integer -> Integer 
potega 0 = 1
potega x = x * potega (x-1)

potega2:: Integer -> Integer -> Integer
potega2 _ 0  = 1
potega2 x n = x * potega2 x (n-1)

