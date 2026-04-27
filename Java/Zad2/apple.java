package Zad2;
import Zad2.fruit;
public class apple extends fruit {
    public static final String TYPE = "jabłkowate";
    private String variety;

    public apple(double weight, String variety) {
        super(weight, TYPE);
        this.variety = variety;
    }

    @Override
    public String getInfo() {
        return super.getInfo() + ", odmiana: " + variety;
    }
}
