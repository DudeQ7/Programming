silnia(0,1).
silnia(N,Wynik) :-
    N > 0,
    N1 is N - 1,
    silnia(N1,W1),
    Wynik is  N * W1.
%suma liczb od 0 do N 
suma(0,0).
suma(N,Wynik) :-
    N > 0,
    N1 is N -1,
    suma(N1,PrevSuma),
    Wynik is N + PrevSuma.
potega(0,_,1). %Y ^0 = 1 
potega(X,Y,Wynik) :-
    X > 0,
    X1 is X - 1,
    potega(X1,Y,PrevPotega),
    Wynik is Y * PrevPotega.
liczba_cyfr(N,1) :- N < 10. %regula ktora jesli podana liczba jest mniejsza od 10 to ma 1 cyfre 
liczba_cyfr(N,L) :-
    N >= 10,
    Reszta is N //10, % usuniecie ostatniej cyfry
    liczba_cyfr(Reszta,L1),
    L is L1 + 1.
czy_potega_dwojki(1).
czy_potega_dwojki(N) :-
    N > 1, 
    0 is N mod 2,
    N1 is N //2, % i-- 
    czy_potega_dwojki(N1).

%czy_pierwsza(N).
%dowolne:
%nwd(A,B,W).
%maksimum(A,B,M).