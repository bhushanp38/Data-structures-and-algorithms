import java.util.Scanner;
import java.util.Arrays;

class LinearSearch {
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

        // take targe input
        System.out.println("Enter the target element to search: ");
        int target = in.nextInt();

        // run function and print the ans
        int ans = linearSearchFn(arr, target);
        System.out.println("The element was found at index: " + ans);

    }

    // LINEAR SEARCH FUNCTION
    static int linearSearchFn(int[] arr, int target) {
        if (arr.length == 0) {
            return -1;
        }

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }

        return -1;
    }

    // SEARCH IN RANGE
    static int linearSearchFn(int[] arr, int target, int start, int end) {
        if (arr.length == 0) {
            return -1;
        }

        for (int i = start; i < end; i++) {
            if (arr[i] == target) {
                return i;
            }
        }

        return -1;
    }
}