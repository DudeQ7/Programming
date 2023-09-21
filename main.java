//metoda 1 zrobiona :) 
import java.util.Scanner;
class main {
public static void main(String[] args) {
Scanner liczba1 = new Scanner(System.in); // zwykly object
Scanner liczba2 = new Scanner(System.in); //zwykly object 2 
System.out.println("Podaj wartość liczby numer 1: ");
int liczba_1 = liczba1.nextInt();
System.out.println("Podaj wartość liczby numer 2: ");
int liczba_2 = liczba2.nextInt();
System.out.println("Wartość liczby numer 1: " + "  " + liczba_1);
System.out.println("Wartość liczby numer 2: " + "  " + liczba_2);
//Scanner liczba2 = new Scanner(System.in); //zwykly object
czyParzysta(liczba_1);
czyParzysta(liczba_2);
czyParzysta2(liczba_1,liczba_2);
}
public static void czyParzysta(int a){
   System.out.println("Metoda 1 parametrowa: ");
   if (a % 2 == 0){
    System.out.println("liczba parzysta" );
    System.out.println("Czy parzysta: ? "+ "\n" + (a%2==0));
   } 
   else {
    System.out.println("liczba nieparzysta");
    System.out.println("Czy nieparzysta: ? " + "\n" + (a%2!=0));
   }
}
public static void czyParzysta2(int x, int y ){
System.out.println("Metoda 2 parametrowa: ");
if (x % 2 == 0 && y % 2 == 0) {
    System.out.println("Obie liczby są parzyste");
    System.out.println("Liczba liczb parzystych: 2");
 } else if (x % 2 == 0 || y % 2 == 0) {
    System.out.println("Jedna z liczb jest parzysta");
    System.out.println("Liczba liczb parzystych: 1");
 } else {
    System.out.println("Żadna z liczb nie jest parzysta :(");
    System.out.println("Liczba liczb parzystych: 0");
}
}
}