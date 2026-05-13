% cena_brutto(Netto, Vat, Brutto)
cena_brutto(Netto, Vat, Brutto) :-
    Brutto is Netto + Netto * Vat / 100.