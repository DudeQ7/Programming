public class apple extends fruit {
    private String variety; // odmiana jabłka
    public static final String TYPE = "jabłkowate";

    public apple(double weight, String variety) {
        super(TYPE, weight);
        this.variety = variety;
    }


    public String getInfo() {
        return super.getInfo() + ", odmiana: " + this.variety;
    }
}
