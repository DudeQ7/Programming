mezczyzna(dariusz).mezczyzna(pawel).mezczyzna(lukasz).
kobieta(anna).kobieta(asia).kobieta(karolina).
%rodzicielstwo (rodzic(rodzic,dziecko)
% :- = jezeli
%definicja ojca , ktos jest ojcem jesli jest rodzicem X osoby Y i jest mezczyzna X 
ojciec(X,Y) :- rodzic(X,Y),mezczyzna(X).
rodzic(dariusz,asia). %dariusz jest rodzicem anny 
rodzic(dariusz,karolina). %dariusz jest rodizcem karoliny
rodzic(anna,asia). %anna jest rodzicem asi
rodzic(anna,karolina). %anna jest rodzicem karoliny 
%przykladowe reguly 
%ktos jest ojcem jesli jest rodzicem X osoby Y i jest mezczyzna X 
ojciec(X,Y) :- 
    rodzic(X,Y),
    mezczyzna(X).
%przykldaowe pytania:
kto_ojciec(Dziecko,Ojciec) :- ojciec(Ojciec,Dziecko).