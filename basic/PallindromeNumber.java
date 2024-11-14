import java.util.Scanner;

class PallindromeNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int initialN = n;

        int temp = 0;

        while (n > 0) {
            int rem = n % 10;
            temp = temp * 10 + rem;
            n = n / 10;
        }

        if (initialN == temp) {
            System.out.println("Pallindrome number");
        } else {
            System.out.println("Not a pallindrome number");
        }
    }
}