import random # import funkcji random
projekty = ["lego", "samochod","przyszlosc","organizacja"]
random_number = random.randint(0,3)
moje_opcje = ["DeathStranding","Youtube_kursy","ksiązka","matma","pieniądze",projekty[random_number]]
print(random.choice(moje_opcje))