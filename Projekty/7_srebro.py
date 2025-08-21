#program ktory bedzie pobierac dane ze strony internetowej i na jej podstawie bedzie wyswietlac najkorzystnierza aktualnie cene gdzie mozna kupic ta monete
#metalmarket.eu , metale lokacyjne 

Brittania = 115.67 
filharmonik = 116.20 
kangur = 118.34
Kruggerand = 117.67
liść_klonowy = 120.99
Amerykanski_orzel = 128.71

ile_monet = int(input("Ile srebrnych monet 1Oz chcesz kupić? : "))
x = min(Brittania,filharmonik,kangur,Kruggerand,liść_klonowy,Amerykanski_orzel)
if(x == filharmonik):
    print("Najtansza moneta to","filharmonik","z ceną : ", (ile_monet * filharmonik) , "zł")
elif(x == kangur):
    print("Najtansza moneta to","kangur","z ceną: ", (ile_monet * kangur), "zł")
elif(x == Kruggerand):
    print("Najtansza moneta to","kruggerand","z ceną: ",(ile_monet * Kruggerand) , "zł")
elif(x == Brittania):
    print("Najtansza moneta to","Brittania","z ceną: ",(ile_monet * Brittania) , "zł")
elif(x == Amerykanski_orzel):
    print("Najtansza moneta to","amerykanski_orzel","z ceną: ",(ile_monet * Amerykanski_orzel),"zł")
else:
    print("Najtansza moneta to","lisc_klonowy","z ceną: ", (ile_monet * liść_klonowy),"zł")
