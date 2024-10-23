import java.util.Scanner;

public class Main {
    public static void main(String[] args) {


    Scanner scanner = new Scanner(System.in);
    String expresion = scanner.nextLine();

    ExpressionParser parser = new ExpressionParser();
    parser.parse(expresion);
    }
}
