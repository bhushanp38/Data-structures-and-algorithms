import java.util.Scanner;
import java.util.Arrays;

class Input2DArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 2D array
        // int[][] arr = {
        // {1, 2, 3},
        // {4, 5, 6},
        // {7, 8, 9}
        // };

        System.out.println("Choose from below");
        System.out.println("0. Fixed sized array");
        System.out.println("1. Jagged array(variable column size)");
        int choice = in.nextInt();

        System.out.println("Enter number of rows");
        int rows = in.nextInt();

        int[][] arr = new int[rows][];

        if (choice == 0) {
            arr = takeFixedSized2DArray(in, rows);
            print2DArray(arr);
        } else if (choice == 1) {
            arr = takeJagged2DArray(in, rows);
            print2DArray(arr);
        } else {
            System.out.println("Enter a valid choice!");
        }
    }

    // take input for fixed sized array
    static int[][] takeFixedSized2DArray(Scanner in, int rows) {
        System.out.println("Enter number of columns: ");
        int cols = in.nextInt();

        int[][] temp = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[i][j] = in.nextInt();
            }
        }

        return temp;

    }

    // take input for jagged array
    static int[][] takeJagged2DArray(Scanner in, int rows) {

        int[][] temp = new int[rows][];

        for (int i = 0; i < rows; i++) {
            System.out.println("Enter number of columns for row: " + (i + 1));
            int cols = in.nextInt();

            temp[i] = new int[cols]; // IMPORTANT

            for (int j = 0; j < cols; j++) {
                temp[i][j] = in.nextInt();
            }
        }

        return temp;
    }

    // print 2d array
    static void print2DArray(int[][] arr) {
        for (int[] row : arr) {
            System.out.println(Arrays.toString(row));
        }
        System.out.println();
    }
}
