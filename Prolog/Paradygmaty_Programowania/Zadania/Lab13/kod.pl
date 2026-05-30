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
    suma_punktow(T, Suma_additional),
    Suma is Punkty + Suma_additional.