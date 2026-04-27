/**
 * Pracownik
 */
class szef extends Pracownik{
public int premia;
}
class Pracownik {
    String imie;
    String nazwisko;
    int wyplata;
}

public class Firma {
    String imie;
    String nazwisko;
    int wyplata;
    public static void main(String[] args) {
        Pracownik prac = new Pracownik();
        prac.imie ="Włodek";
        prac.nazwisko="Zięba";
        prac.wyplata = 3000;
    

        szef boss = new szef();
        boss.imie="Tadesz";
        boss.nazwisko = "Zięba";
        boss.wyplata = 10000;
        boss.premia = 2000;
    }
}