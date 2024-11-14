import java.util.Scanner;

class ArmstrongNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int initialN = n;
        int temp = 0;

        if (n == 0) {
            System.out.println("Armstrong number");
        } else {
            while (n > 0) {
                int rem = n % 10;
                temp = temp + (rem * rem * rem);
                n = n / 10;
            }
        }

        if (temp == initialN) {
            System.out.println("Armstrong number");
        } else {
            System.out.println("Not an Armstrong number");
        }
    }
}