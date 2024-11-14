package functions;

import java.util.Scanner;

class PrimeNumber {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.println("Enter the number: ");
            System.out.println(isPrime(in.nextInt()));
        }
    }

    static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        int c = 2;
        while (c * c <= n) {
            if (n % c == 0) {
                return false;
            }
            c++;
        }

        // return c*c > n;
        return true;
    }
}