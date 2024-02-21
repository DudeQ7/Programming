public class fruit {
    protected double weight; // waga w gramach
    protected String type; // typ owocu

    public fruit(String type, double weight) {
        this.type = type;
        this.weight = weight;
    }

    public String getInfo() {
        return "Waga: " + this.weight + "g, typ: " + this.type;
    }
}
