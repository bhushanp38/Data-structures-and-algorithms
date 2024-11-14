import java.util.Scanner;

class Area {
    public static void main(String[] args) {
        System.out.println("Find area of");
        System.out.println("1. Triangle \n2. Square \n3. Rectangle \n4. Circle");

        Scanner in = new Scanner(System.in);
        int choice = in.nextInt();

        switch (choice) {
            case 1 -> {
                System.out.println("Enter base and height");
                int b = in.nextInt();
                int h = in.nextInt();
                float area = (1f / 2) * b * h;
                System.out.println(area);
            }
            case 2 -> {
                System.out.println("Enter side");
                int s = in.nextInt();
                float area = s * s;
                System.out.println(area);
            }
            case 3 -> {
                System.out.println("Enter width and height");
                int b = in.nextInt();
                int h = in.nextInt();
                float area = b * h;
                System.out.println(area);
            }
            case 4 -> {
                System.out.println("Enter radius");
                float pi = 3.14f;
                int r = in.nextInt();
                float area = pi * r * r;
                System.out.println(area);
            }
        }
    }
}