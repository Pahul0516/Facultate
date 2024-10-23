import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.AbstractMap.SimpleEntry;


public class ExpressionParser {

    static NumarComplex[] final_list;
    static char final_operation;

    public ExpressionParser() {
    }

    public boolean verification(String expression) {
        var strings = expression.split("(?=i)", 0);
        char operation = '\0';
        for (int i = 0; i < strings.length - 1; i++) {
            strings[i] = strings[i].replaceAll(" ", "").replace("∗", "*").replace("−", "-");
            if (i == 0) {
                strings[i] += "i";
                strings[i + 1] = strings[i + 1].substring(1);
            } else {
                strings[i] += "i";
                if (operation == '\0') operation = strings[i].charAt(0);
                else if (operation != strings[i].charAt(0)) return false;
                strings[i + 1] = strings[i + 1].substring(1);
                strings[i] = strings[i].substring(1);
            }
        }

        List<String> list = new ArrayList<>(Arrays.asList(strings));
        if (!list.isEmpty() && Objects.equals(list.getLast(), "")) list.removeLast();

        String regex = "^-?\\d+\\s*[+-]\\s*\\d+\\s*\\*?\\s*i$";
        Pattern pattern = Pattern.compile(regex);
        for (var number : list)
        {
            number = number.trim();
            Matcher matcher = pattern.matcher(number);
            if (!matcher.matches() && number!="") {
                return false;
            }
        }
        if (list.size()==1 || list.isEmpty()) return false;
        return true;
    }


    public void parse(String expression) {
        if (!verification(expression)) {
            System.out.println("Expresie invalida.");
            return;
        }

        var strings = expression.split("(?=i)", 0);
        char operation = '\0';
        for (int i = 0; i < strings.length - 1; i++) {
            strings[i] = strings[i].replaceAll(" ", "").replace("∗", "*").replace("−", "-");
            if (i == 0) {
                strings[i] += "i";
                strings[i + 1] = strings[i + 1].substring(1);
            } else {
                strings[i] += "i";
                if (operation == '\0') operation = strings[i].charAt(0);
                strings[i + 1] = strings[i + 1].substring(1);
                strings[i] = strings[i].substring(1);
            }
        }



        List<String> list = new ArrayList<>(Arrays.asList(strings));
        if (!list.isEmpty() && Objects.equals(list.getLast(), "")) list.removeLast();
        final_operation = operation;

        List<NumarComplex> complexList = new ArrayList<>();
        for (var number : list) {
            SimpleEntry<Double, Double> pair = extractNumbers(number);
            NumarComplex nr1 = new NumarComplex(pair.getKey(), pair.getValue());
            complexList.add(nr1);
        }

        final_list = complexList.toArray(new NumarComplex[0]);
        createFactory();
    }

    private static SimpleEntry<Double, Double> extractNumbers(String complexString) {
        String regex = "([+-]?\\d*\\.?\\d+)([+-]\\d*\\.?\\d+)\\*i";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(complexString);

        if (matcher.matches()) {
            double realPart = Double.parseDouble(matcher.group(1));
            double imaginaryPart = Double.parseDouble(matcher.group(2));
            return new SimpleEntry<>(realPart, imaginaryPart);
        }
        else
            return new SimpleEntry<>(0.0, 0.0);
    }

    public void createFactory()
    {
        ExpressionFactory factory = new ExpressionFactory();
        factory.createExpression(final_operation,final_list);
    }
}