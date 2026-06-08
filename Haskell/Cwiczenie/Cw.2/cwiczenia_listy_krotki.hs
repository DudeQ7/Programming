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
ciepleDni = filter (>=20.0) 
-- zaokraglone = zamienia temperatury na liczby całkowite funkcją round = Done 
zaokraglone :: [Double] -> [Int]
zaokraglone = map round
--rozniceOd20 = oblicza różnicę każdego pomiaru względem wartości 20.0 = Done 
rozniceOd20 :: [Double] -> [Double]
rozniceOd20 = map (\t -> t - 20.0)

