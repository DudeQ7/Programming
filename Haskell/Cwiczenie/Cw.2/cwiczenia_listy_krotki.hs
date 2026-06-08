--Done
temperatury :: [Double]
temperatury = [18.5,21.0,19.8,23.4,17.9,22.2,20.1]

produkty :: [(String, Double)]
produkty = [("monitor",899.98),("klawiatura",149.90),("mysz",79.90),("router",249.00)]

punktyLab :: [(String,[Int])]
punktyLab = [("Nowak",[8,9,7]),("Kowalska",[10,10,9]),("Lis",[5,6,4])]

xsy :: [Int]
xsy = [2,4,6,8]

ysy :: [Int]
ysy = [1,3,5,7]

--Zadanie 1 
--liczba pomiarow = Done
liczbaPomiarow :: Int
liczbaPomiarow = length temperatury
-- trzy pierwsze pomiary = Done 
trzyPierwsze :: [Double]
trzyPierwsze = take 3 temperatury 
-- lista bez dwoch pierwszych pomiarow = Done 
bezDwochPierwszych :: [Double]
bezDwochPierwszych = drop 2 temperatury
-- Max i Min temperatury = Done
maxMin :: (Double, Double)
maxMin = (maximum temperatury, minimum temperatury)

--Zadanie 2 
-- Cieple Dni = pozostawia temperatury większe lub równe 20.0 = Done 
ciepleDni :: [Double] -> [Double]
ciepleDni ts = filter (>=20.0) ts
-- zaokraglone = zamienia temperatury na liczby całkowite funkcją round = Done 
zaokraglone :: [Double] -> [Int]
zaokraglone ts = map round ts
--rozniceOd20 = oblicza różnicę każdego pomiaru względem wartości 20.0 = Done 
rozniceOd20 :: [Double] -> [Double]
rozniceOd20 ts = map (\t -> t - 20.0) ts

--Zadanie 3 
--wielokrotnosci3 = zwraca wielokrotności liczby 3 od 3 do podanej granicy = Done 
wielokrotnosci3 :: Int -> [Int]
wielokrotnosci3 n = [x | x <- [3..n], x `mod` 3 == 0]
--kwadratyNieparzystych = zwraca kwadraty liczb nieparzystych z zakresu od 1 do n 
kwadratyNieparzystych :: Int -> [Int]
kwadratyNieparzystych n = [x^2 | x <- [1..n], odd x]
--paryRozne = zwraca kwadraty liczb nieparzystych z zakresu od 1 do n  = Done 
paryRozne ::[Int] -> [Int] -> [(Int,Int)]
paryRozne xs ys = [(x,y) | x <- xs, y <- ys, x /= y]