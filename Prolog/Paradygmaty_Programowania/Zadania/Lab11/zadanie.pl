%to do:
% Rozrysuj sobie drzewo na kartce (4 pokolenia), aby nie pogubić się w imionach.
% Wypisz wszystkie fakty rodzic(..., ...). dla całej rodziny.
% Dopisuj reguły po kolei (zacznij od matka, potem dziadek, aż do prawnuczka)


%4 pokolenia
%zdefiniuj każdego członka rodziny uwzględniając płeć, bycie rodzicem itp.
%pokolenie 1 pradziadkowie
rodzic(stefan,henryk).
rodzic(maria,henryk).
rodzic(stefan,henryk).
rodzic(maria,henryk).

rodzic(wojciech,henryk).

rodzic(maria,katarzyna).
%pokolenie 2 dziadkowie
rodzic(henryk,dariusz). 
rodzic(henryk,anna). 
rodzic(zofia,dariusz).
rodzic(katarzyna,anna). 
%pokolenie 3 rodzice 
rodzic(dariusz,pawel). %moj tata 
rodzic(dariusz,joanna). %moja siostra
rodzic(dariusz,karolina). %moja siostra
rodzic(anna,asia). %moja mama
rodzic(anna,karolina). %moja mama
rodzic(anna,pawel). %moja mama
%pokolenie 4 dzieci
rodzic(asia,maja).
rodzic(lukasz,maja).
rodzic(karolina,tili).
rodzic(douglas,tili).