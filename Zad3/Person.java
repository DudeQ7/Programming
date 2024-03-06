package Zad3;
public class Person {
    String imie;
    String nazwisko;
    double wyplata;
    public Person(String imie, String nazwisko, double wyplata) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.wyplata = wyplata;
    }
    @Override
    public String toString(){
        return "Imie: " + imie + " Nazwisko: "+ nazwisko + " Wyplata: " + wyplata;
    }

}
