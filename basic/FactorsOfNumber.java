import java.util.Scanner;

class FactorsOfNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String ans = "";
        // Input a number and print all the factors of that number (use loops).

        // int i = 1;
        // while (i <= n / 2) {
        // if (n % i == 0) {
        // ans = ans + i + " ";
        // }
        // i++;
        // }
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                ans = ans + i + " ";
            }
        }
        System.out.println(ans);
    }
}