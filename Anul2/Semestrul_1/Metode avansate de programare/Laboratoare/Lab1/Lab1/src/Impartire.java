import java.util.List;

public class Impartire extends ComplexExpression{
    public Impartire(Operations operations, List<NumarComplex> l) {
        super(operations,l);
    }

    @Override
    public void executeOneOperation() {
        var list = getList();
        NumarComplex nr1 = list.get(0);
        NumarComplex nr2 = list.get(1);
        NumarComplex rez = nr1.impartire(nr2);
        list.removeFirst();
        list.set(0, rez);
    }

}

