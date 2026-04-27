package Zad3;

import javax.print.Doc;

public class Doctor extends Person {

    public double premia;

    public double getPremia() {
        return premia;
    }

    public void setPremia(double premia) {
        this.premia = premia;
    }

    public Doctor(String imie, String nazwisko, double wyplata, double premia){
        super(imie,nazwisko,wyplata);
        this.premia = premia;

    }
    @Override
    public  String toString(){
        return super.toString()+ " Premia: " + premia;
    }
}
