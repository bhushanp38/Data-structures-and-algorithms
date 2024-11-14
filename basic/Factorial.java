
import java.util.Scanner;

class Factorial {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = 0;
        int b = 1;
        int n = in.nextInt();

        String ans = "0 1";
        int count = 2;
        if (n == 1) {
            System.out.println("0");
        } else if (n == 2) {
            System.out.println("0 1");
        } else {
            while (count < n) {
                int temp = b;
                b = a + b;
                a = temp;
                ans = ans + " " + b;
                count++;
            }
            System.out.println(ans);
        }
    }
}