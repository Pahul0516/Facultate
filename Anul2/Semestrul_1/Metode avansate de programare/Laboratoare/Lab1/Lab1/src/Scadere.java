import java.util.List;

public class Scadere extends ComplexExpression{
    public Scadere(Operations operations, List<NumarComplex> l) {
        super(operations,l);
    }

    @Override
    public void executeOneOperation() {
        var list = getList();
        NumarComplex nr1 = list.get(0);
        NumarComplex nr2 = list.get(1);
        NumarComplex rez = nr1.scadere(nr2);
        list.removeFirst();
        list.set(0, rez);
    }

}