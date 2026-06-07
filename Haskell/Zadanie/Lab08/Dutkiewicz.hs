-- Sprawdza podana liczbe i zwraca odpowiedni dzien tygodnia 
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
-- Funkcja parzysta 
parzysta :: Int -> String 
parzysta n = if even n then "Parzysta" else "Nieparzysta"

