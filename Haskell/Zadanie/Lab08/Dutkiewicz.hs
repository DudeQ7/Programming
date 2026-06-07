-- Sprawdza podana liczbe i wraca odpowiedni dzien tygodnia 
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