package Zad3;

public class Nurse extends Person{
    double overtime;
    public Nurse(String imie,String nazwisko,double wyplata,double overtime){
        super(imie,nazwisko,wyplata);
        this.overtime = overtime;
    }
    @Override
    public String toString(){
        return super.toString() + " Nadgodziny: " + overtime;
    }
}
