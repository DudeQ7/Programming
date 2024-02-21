package Zad2;

public class apple extends fruit {
   private  String variety; // odmiana jablek
    public static final String TYPE = "jablkowate";
    public  apple(double weight,String variety){
        super(TYPE,weight);
        this.variety = variety}
    public String getInfo(){
        return super.getInfo() + "odmiana: "+this.variety;
    }

}
