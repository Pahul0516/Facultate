import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ExpressionFactory {

    private static ExpressionFactory instance;

    ExpressionFactory() {}

    public ComplexExpression createExpression(char operations, NumarComplex[] args) {
        List<NumarComplex> complexList = new ArrayList<>(Arrays.asList(args));
        switch (operations) {
            case '+':
                ComplexExpression ex1 = new Adunare(Operations.ADDITION, complexList);
                ex1.execute();
                System.out.println(complexList.getFirst());
                break;
            case '-':
                ComplexExpression ex2 = new Scadere(Operations.SUBTRACTION, complexList);
                ex2.execute();
                System.out.println(complexList.getFirst());
                break;
            case '*':
                ComplexExpression ex3 = new Inmultire(Operations.MULTIPLICATION, complexList);
                ex3.execute();
                System.out.println(complexList.getFirst());
                break;
            case '/':
                ComplexExpression ex4 = new Impartire(Operations.DIVISION, complexList);
                ex4.execute();
                System.out.println(complexList.getFirst());
                break;
        }
        return null;
    }

    public static ExpressionFactory getInstance() {
        if (instance == null) {
            instance = new ExpressionFactory();
        }
        return instance;
    }
}
