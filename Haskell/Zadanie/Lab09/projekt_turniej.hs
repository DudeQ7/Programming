-- Projekt domowy: Analizator wynikow turnieju programistycznego 
-- Przedmiot: Paradygmaty programowania 
-- Zakres: listy, krotki, funkcje map/filter/fold/zip 
 
type Uczestnik = (String, String, [Int]) 
-- (imie i nazwisko, grupa, punkty z kolejnych zadan) 
 
uczestnicy :: [Uczestnik] 
uczestnicy = 
    [ ("Anna Nowak", "INF3A", [18, 20, 17, 15]) 
    , ("Jan Kowalski", "INF3B", [12, 14, 10, 8]) 
    , ("Ola Mazur", "INF3A", [20, 19, 18, 20]) 
    , ("Piotr Lis", "INF3C", [15, 15, 16, 14]) 
    , ("Ewa Zielinska", "INF3B", [19, 18, 17, 18]) 
    ] 
 
pobierzNazwe :: Uczestnik -> String 
pobierzNazwe (nazwa, _, _) = nazwa 
 
pobierzGrupe :: Uczestnik -> String 
pobierzGrupe (_, grupa, _) = grupa 
 
pobierzPunkty :: Uczestnik -> [Int] 
pobierzPunkty (_, _, punkty) = punkty 
 
-- TODO 1: oblicz sume punktow jednego uczestnika 
sumaPunktow :: Uczestnik -> Int 
sumaPunktow uczestnik = undefined 
 
-- TODO 2: oblicz srednia punktow jednego uczestnika 
sredniaPunktow :: Uczestnik -> Double 
sredniaPunktow uczestnik = undefined 
 
-- TODO 3: zwroc liste par (nazwa uczestnika, suma punktow) 
wyniki :: [Uczestnik] -> [(String, Int)] 
wyniki xs = undefined 
 
-- TODO 4: zostaw uczestnikow z wynikiem co najmniej 60 punktow 
zakwalifikowani :: [Uczestnik] -> [Uczestnik] 
zakwalifikowani xs = undefined 
 
-- TODO 5: filtruj uczestnikow po grupie, np. "INF3A" 
uczestnicyGrupy :: String -> [Uczestnik] -> [Uczestnik] 
uczestnicyGrupy grupa xs = undefined 
 
-- TODO 6: znajdz najlepszy wynik punktowy 
najlepszyWynik :: [Uczestnik] -> Int 
najlepszyWynik xs = undefined 
 
-- TODO 7: zwroc wszystkich uczestnikow, ktorzy maja najlepszy wynik 
najlepsi :: [Uczestnik] -> [Uczestnik] 
najlepsi xs = undefined 
 
-- TODO 8: przygotuj raport tekstowy 
raport :: [Uczestnik] -> [String] 
raport xs = undefined 
 
-- Przykladowe testy w interpreterze: 
-- sumaPunktow (head uczestnicy) 
-- sredniaPunktow (head uczestnicy) 
-- wyniki uczestnicy 
-- zakwalifikowani uczestnicy 
-- uczestnicyGrupy "INF3A" uczestnicy 
-- najlepszyWynik uczestnicy 
-- najlepsi uczestnicy 
-- raport uczestnicy