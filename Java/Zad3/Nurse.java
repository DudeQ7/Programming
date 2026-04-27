package Zad3;

public class Nurse extends Person{
    double overtime;

    public double getOvertime() {
        return overtime;
    }

    public void setOvertime(double overtime) {
        this.overtime = overtime;
    }

    public Nurse(String imie, String nazwisko, double wyplata, double overtime){
        super(imie,nazwisko,wyplata);
        this.overtime = overtime;
    }
    @Override
    public String toString(){
        return super.toString() + " Nadgodziny: " + overtime;
    }
}
