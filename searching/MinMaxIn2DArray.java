import java.util.Scanner;
import java.util.Arrays;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter number of rows: ");
        int rows = in.nextInt();

        System.out.println("Enter number of columns: ");
        int cols = in.nextInt();

        int[][] arr = new int[rows][cols];

        System.out.println("Enter elements: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = in.nextInt();
            }
        }

        // // PRINT 2D array
        // for(int[] row : arr) {
        // System.out.println(Arrays.toString(row));
        // }

        int[] position = findMinMax(arr);
        System.out.println("Min and Max value for given 2D array: " + Arrays.toString(position));

    }

    static int[] findMinMax(int[][] arr) {
        int min = arr[0][0];
        int max = arr[0][0];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if (arr[i][j] < min) {
                    min = arr[i][j];
                } else if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
        return new int[] { min, max };
    }
}
