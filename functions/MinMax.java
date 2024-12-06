import java.util.Scanner;
import java.util.Arrays;

class MinMax {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // take size input
        System.out.println("Enter number of elements in array: ");
        int n = in.nextInt();

        // declare array
        int[] arr = new int[n];

        // take array input
        System.out.println("Enter an array: ");
        for (int i = 0; i < arr.length; i++) {
            arr[i] = in.nextInt();
        }
        System.out.println(Arrays.toString(arr));

        System.out.println("Smallest number in array is: " + min(arr));
        System.out.println("Largest number in array is: " + max(arr));

    }

    // assuming that an array is empty
    static int min(int[] arr) {
        int min = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    static int max(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

}