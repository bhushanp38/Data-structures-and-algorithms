package functions;

public class ThreeDigitArmstrongNumbers {
    public static void main(String[] args) {
        String ans = "";
        for (int i = 0; i < 1000; i++) {
            if (isArmstrong(i)) {
                ans = ans + i + "\n ";
            }
        }

        System.out.println(ans);

    }

    static boolean isArmstrong(int n) {
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

        return temp == initialN;
    }
}
