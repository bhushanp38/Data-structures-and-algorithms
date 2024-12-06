import java.util.Scanner;

class CountNumbersWithEvenDigits {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter size of an array: ");
        int n = in.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter the elements of array");
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        // String ans = "";
        // for (int i = 0; i < n; i++) {
        // ans = ans + arr[i] + " ";
        // }

        // System.out.println("Enterd array: " + ans);

        System.out.println("Numbers with even digits in given array: " + findEvenDigits(arr));

    }

    // We can also convert each element to string and get its length
    static int findEvenDigits(int[] arr) {
        int count = 0;

        for (int num : arr) {
            int digits = 0;
            if (num == 0) {
                digits = 1;
            } else if (num < 0) {
                num = num * -1; // if the number is negative, make it positive
            }

            while (num > 0) {
                digits += 1;
                num /= 10;
            }

            if (digits % 2 == 0) {
                count += 1;
            }
        }
        return count;
    }
}
