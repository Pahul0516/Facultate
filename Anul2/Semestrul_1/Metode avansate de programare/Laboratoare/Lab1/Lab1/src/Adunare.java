import java.util.List;

public class Adunare extends ComplexExpression{
    public Adunare(Operations operations, List<NumarComplex> l) {
        super(operations,l);
    }

    @Override
    public void executeOneOperation() {
        List<NumarComplex> list = getList();
        NumarComplex nr1 = list.get(0);
        NumarComplex nr2 = list.get(1);
        NumarComplex rez = nr1.adunare(nr2);
        list.removeFirst();
        list.set(0, rez);
    }
}
