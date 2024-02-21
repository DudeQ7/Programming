package Zad2;

import java.lang.reflect.Type;

public class fruit {
    public fruit(String typ, double weight) {
        this.typ = typ;
        this.weight = weight;
    }
    public static final String species_Type = "jabłkowate";
public void getInfo(double weight,String typ){
    System.out.println("waga: " + weight);
    System.out.println("Typ:" + typ);
    }
    public String typ;
    public double weight;

    public  String species;

}