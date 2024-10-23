import java.util.List;

public abstract class ComplexExpression {
    private Operations operations;
    private List<NumarComplex> list;



    public ComplexExpression(Operations o, List<NumarComplex> l) {
        this.operations = o;
        this.list = l;
    }

    public NumarComplex execute() {
        while (list.size() > 1) {
            executeOneOperation();
        }
        return list.getFirst();
    }

    public List<NumarComplex> getList() {
        return list;
    }

    public abstract void executeOneOperation();

}
