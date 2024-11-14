import java.util.Scanner;

class MaxTillZeroEntered {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num;
        int max = 0;

        while ((num = in.nextInt()) != 0) {
            if (num > max) {
                max = num;
            }
        }

        System.out.println(max);
        in.close();
    }
}