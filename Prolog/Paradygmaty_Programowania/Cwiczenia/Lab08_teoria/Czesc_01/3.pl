ojciec(Jan,Piotr).
matka(Anna,Piotr).
ojciec(Jan,ewa).
matka(Anna,ewa).
rodzic(X,Y) :- ojciec(X,Y).
rodzic(X,Y):-matka(X,Y).
%rodzic(anna,ewa).