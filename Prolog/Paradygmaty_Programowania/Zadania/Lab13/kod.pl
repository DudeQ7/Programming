studenci([
    student(anna,18),
    student(jan,9),
    student(piotr,15),
    student(ewa,20),
    student(karol,7),
    student(maria,13)
]).
student(maria,13).
%max 20 pkt, powyzej 10 zalicza laboratorium
suma_punktow([],0). %pusta lista = 0 pkt
suma_punktow([student(_, Punkty) | T], Suma) :-
    suma_punktow(T, SumaOgona),
    Suma is Punkty + SumaOgona.

liczba_studentow([],0).
liczba_studentow([_|T],N) :-
    liczba_studentow(T,N1),
    N is N1 + 1. 

srednia_punktow(Lista,Srednia) :-
    suma_punktow(Lista,S),
    liczba_studentow(Lista,N),
    N > 0, %failsafe przed dzieleniem przez 0 
    Srednia is S / N. 
%case 1 - student spelnia warunek = lista wynikowa
%case 2 - student nie spelnia warunku = pomijamy go
zaliczeni([],[]).
%case punkty >=10 
zaliczeni([student(Imie,Punkty) | T],[student(Imie,Punkty)|TZal]) :-
    Punkty >=10,
    zaliczeni(T,TZal).
%case punkty <10
zaliczeni([student(_,Punkty) | T], TZal) :-
    Punkty < 10,
    zaliczeni(T,TZal).

niezaliczeni([],[]).
%case punkty >=10 
niezaliczeni([student(Imie,Punkty) | T],[student(Imie,Punkty)|TNiezal]) :-
    Punkty < 10,
    niezaliczeni(T,TNiezal).
%case punkty <10
niezaliczeni([student(_,Punkty) | T], TNiezal) :-
    Punkty < 10,
    niezaliczeni(T,TNiezal).