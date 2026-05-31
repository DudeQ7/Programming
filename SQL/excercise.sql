create  table samochody
{
    id_auta Primary Key AUTO INCREMENT,
    marka varchar(30) NOT NULL ,
    model varchar(60),
    rok_produkcji int,
    kolor varchar(20),
    cena float
};
create table Klienci
{
    id_klienta Primary Key AUTO INCREMENT,
    imie varchar(30),
    nazwisko varchar(30)
};
INSERT INTO samochody 
(mark,model,rok_produkcji,kolor,cena) 
VALUES
{"Toyota","Corolla",2015,"Czarny",50000},
{"Honda","Civic",2018,"Biały",60000},
{"Ford","Focus",2017,"Srebrny",55000},
{"BMW","3 Series",2016,"Niebieski",70000},
{"Audi","A4",2019,"Czerwony",75000};
INSERT INTO Klienci 
(imie,nazwisko)
VALUES
{"Jan","Kowalski"},
{"Anna","Nowak"},
{"Piotr","Wiśniewski"};

Update samochody 
SET 
color = "Metaliczny błękit"
WHERE 
id_auta = 1; 

UPDATE samochody
set 
cena = cena * 1.10 ; 

Alter TABLE samochody
ADD column id_wlasciciela INT REFERENCES Klienci(id_klienta);


