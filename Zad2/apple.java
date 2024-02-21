package Zad2;

public class apple extends fruit {
    private int waga;
    private String nazwa;

    public apple(int waga, String nazwa) {
        this.waga = waga;
        this.nazwa = nazwa;
    }
    public static void main(String[] args) {
        apple apple1 = new apple(150, "jablko");
        apple1.nazwa = "lol";
        System.out.println(apple1.nazwa);
    }
}
