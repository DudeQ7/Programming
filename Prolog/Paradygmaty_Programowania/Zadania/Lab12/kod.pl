silnia(0,1).
silnia(N,Wynik) :-
    N > 0,
    N1 is N - 1,
    silnia(N1,W1),
    Wynik is  N * W1.

suma(N,Wynik).
potega(X,Y,Wynik).
%gdzie Wynik = Y^X
liczba_cyfr(N,L).
czy_potega_dwojki(N).
czy_pierwsza(N).
%dowolne:
nwd(A,B,W).
maksimum(A,B,M).