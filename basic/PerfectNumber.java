import java.util.Scanner;

class PerfectNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        // String ans = "";
        int ans = 0;
        // Input a number and print all the factors of that number (use loops).

        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                ans = ans + i;
            }
        }

        if (ans == n) {
            System.out.println("Perfect number");
        } else {
            System.out.println("Not a Perfect number");
        }
    }
}