package programming;
// EvenAdder.java; //niepotrzebny fragment //POPRAWA
import java.util.Arrays;
import java.util.Scanner;
class EvenAdder {
    public static void main(String[] args) {
        int[] array = createEvenArray(5);
        reverseArray(array);
        System.out.println(Arrays.toString(array));
    }

    /**
     * @param size - number of elements to read
     * @return array containing even numbers
     */
    private static int[] createEvenArray(int size) {
        Scanner scanner = new Scanner(System.in);