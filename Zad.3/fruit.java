public class fruit {
    private String typowocu; // potencjalny blad 
    private int waga; // potencjalny blad 
    public fruit(String typowocu,int waga){
        this.typowocu = typowocu;
        this.waga = waga ;
    }
        public String getinfo(String typowocu, int waga){
            return "Typ owocu: "+ typowocu + " Waga: "+ waga+"gramow";
        }
        public static void main(String[] args) {
            fruit fruit = new fruit("jablko", 5);
            System.out.println(fruit.getinfo(null, 0));
        }
}
