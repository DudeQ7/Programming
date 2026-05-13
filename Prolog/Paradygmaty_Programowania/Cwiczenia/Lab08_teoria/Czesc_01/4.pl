% , = and 
ojciec(Jan,Piotr).
matka(Anna,Piotr).
ojciec(Jan,ewa).
matka(Anna,ewa).
rodzic(X,Y) :- ojciec(X,Y).
rodzic(X,Y):-matka(X,Y).
%rodzic(anna,ewa).
rodzenstwo(X,Y) :- 
    rodzic(Z,X),    
    %pyta sama litera wymusza by program sam znalazl wspolne ogniwo 
    rodzic(Z,Y),
    X \=Y.
%To zwroci true gdy istnieje jakas osoba Z ktora jest rodzicem Y , X oraz Y to nie jest ta sama osoba 
