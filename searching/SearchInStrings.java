import java.util.Scanner;

public class SearchInStrings {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the string: ");
        String str = in.next();

        char ch = in.next().charAt(0);

    }

    static boolean SearchInString(String str, char target) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == target) {
                return true;
            }
        }
        return false;
    }

    // USING ENHANCED FOR LOOP(FOR EACH)
    static boolean SearchInString2(String str, char target) {
        for (char ch : str.toCharArray()) {
            if (ch == target) {
                return true;
            }
        }
        return false;
    }

}
