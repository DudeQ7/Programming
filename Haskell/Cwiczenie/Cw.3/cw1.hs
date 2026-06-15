-- suma na liczbach
zad1::Int -> Int 
zad1 n 
    | n <=0 = 0
    | otherwise  = n*n + zad1 (n-1)
-- liczenie elemnentow spelniajacych warunek
zad2::[Int] -> Int
zad2 [] = 0 
zad2 (x:xs)
    | x > 0 = 1 + zad2 xs 
    | otherwise = zad2 xs
-- Funkcja All 
wszystkie :: (a-> Bool) -> [a] -> Bool
wszystkie _ [] = True
wszystkie p (x:xs)
    | p x = wszystkie p xs 
    | otherwise = False 
-- Usuwanie wartosci
usunWartosc :: Eq a => a -> [a] -> [a]
usunWartosc _ [] = []
usunWartosc v (x:xs)
    | v == x = usunWartosc v xs 
    | otherwise = x:usunWartosc v xs 
--Praca na Krotce
type Wynik = (String,Int)
poprawWynik :: Int -> Wynik -> Wynik 
poprawWynik g (nazwa,punkty) = (nazwa,punkty+g)