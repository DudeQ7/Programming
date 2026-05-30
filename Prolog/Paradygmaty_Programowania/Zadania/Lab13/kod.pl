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