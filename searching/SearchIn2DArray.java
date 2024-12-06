import java.util.Scanner;
import java.util.Arrays;

class Searching2DArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 2D array
        int[][] arr = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
        };

        System.out.println("Enter element to search in 2D array: ");
        int target = in.nextInt();

        int[] position = findPosition(arr, target);
        System.out.println(Arrays.toString(position));

    }

    static int[] findPosition(int[][] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] { -1, -1 }; // IMPORTANT --> Creates new array without giving explicit size
        // This syntax is required if the value to be returned is not declared
        // explicitly.
    }
}
