-- 1.Funkcja zwracajaca dzien tygodnia z if'ami 
dzienif :: Int -> String
dzienif dzien =
    if dzien == 1 then "Poniedzialek"
    else if dzien == 2 then "Wtorek"
    else if dzien == 3 then "Sroda"
    else if dzien == 4 then "Czwartek"
    else if dzien == 5 then "Piatek"
    else if dzien == 6 then "Sobota"
    else if dzien == 7 then "Niedziela"
    else "Nie ma takiego dnia tygodnia"
--2. Funkcja zwracajaca dzien tygodnia z case'ami
dziencase :: Int -> String
dziencase dzien = case dzien of --deklaracja case'a 
    1 -> "Poniedzialek"
    2 -> "Wtorek"
    3 -> "Sroda"
    4 -> "Czwartek"
    5 -> "Piatek"
    6 -> "Sobota"
    7 -> "Niedziela"
    _ -> "Nie ma takiego dnia tygodnia"
--3. Funkcja parzysta wykorzystujaca if'a
parzysta :: Int -> String 
parzysta n = if even n then "Parzysta" else "Nieparzysta"
--4. Rabat z obsluga liczb ujemnych  
rabat :: Float -> String 
rabat cena 
    | cena < 0 = "Kwota jest ujemna"
    | cena <= 100 = "Rabat 10%"
    | cena <= 200 = "Rabat 12%"
    | otherwise = "Rabat 13%"
-- 5. Funkcja sprawdzajaca czy rok jest przystepny
rok :: Int -> String 
rok r = if r `mod` 4 == 0 && (r `mod` 100 /= 0 || r `mod` 400 == 0) then "Rok przestepny" else "Rok nieprzestepny"
-- 6. Funkcja sprawdzajaca czy osoba jest juz na emeryturze czy nie, z roznieniem dla plci
emerytura :: Int -> String -> String 
emerytura wiek plec = case plec of
    "m" -> if wiek <65
        then "Do emerytury pozostalo: " ++ show (65 - wiek)  ++ " lat"
        else "Jestes na emeryturze od: " ++ show(wiek-65) ++ " lat"
    "k" -> if wiek <60 
        then "Do emerytury pozostalo: " ++ 
        show (60 - wiek) ++ " lat"
        else "Jestes na emeryturze od: " ++ show(wiek-60) ++ " lat"
    _ -> "Nieprawidlowa plec"
-- 7. Przypisanie miesiecy jako por roku 
miesiacjakoporaRoku :: Int -> String
miesiacjakoporaRoku miesiac = case miesiac of
    12 -> "zima"
    1 -> "zima"
    2 -> "zima"
    3 -> "wiosna"
    4 -> "wiosna"
    5 -> "wiosna"
    6 -> "lato"
    7 -> "lato"
    8 -> "lato"
    9 -> "jesien"
    10 -> "jesien" 
    11 -> "jesien" 
    _ -> "Bledny miesiac"
-- 8. Przeliczanie jednostek z wykorzystaniem case'a 
przeliczJednostki :: Float -> String -> Float
przeliczJednostki metry jednostka = case jednostka of 
    "cm" -> metry * 100
    "mm" -> metry * 1000
    "km" -> metry / 1000
    _    -> 0 