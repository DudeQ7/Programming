ksiazka(wiedzmin,fantasy).
ksiazka(lalka,powiesc).
ksiazka(dziady,dramat).
gatunek(X,Y) :- ksiazka(X,Y).
%listing(gatunek);