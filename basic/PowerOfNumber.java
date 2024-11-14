import java.util.Scanner;

class PowerOfNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int p = in.nextInt();
        int ans = 1;
        int count = 1;

        if (p != 0) {

            // ans = n;
            while (count <= p) {
                ans = ans * n;
                count++;
            }
        }

        System.out.println(n + " ** " + p + " = " + ans);
    }
}