package Zad2;
public class fruit {
    protected  double weight;
    protected  String type;
    public fruit(double weight, String type) {
        this.weight = weight;
        this.type = type;
    }
public String getInfo(){
        return "Waga: "+this.weight +"g" +"typ: "+this.type;
}


}
