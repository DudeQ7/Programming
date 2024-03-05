public class fruit {
    private double weight;
    private String type;

    public fruit(double weight, String type) {
        this.weight = weight;
        this.type = type;
    }

    public String getInfo() {
        return "Waga: " + weight + "g, typ: " + type;
    }
}
