import java.util.Objects;

public class NumarComplex {

    private double re;
    private double im;

    public NumarComplex(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }

    public void setIm(double im) {
        this.im = im;
    }

    public void setRe(double re) {
        this.re = re;
    }

    public NumarComplex adunare(NumarComplex n){
        return new NumarComplex(this.getRe() + n.getRe(), this.getIm() + n.getIm());
    }

    public NumarComplex scadere(NumarComplex n) {
        return new NumarComplex(this.getRe() - n.getRe(), this.getIm() - n.getIm());
    }

    public NumarComplex inmultire(NumarComplex n) {
        var re = this.getRe() * n.getRe() - this.getIm() * n.getIm();
        var im  = this.getRe() * n.getIm() + this.getIm() * n.getRe();
        return new NumarComplex(re,im);
    }

    public NumarComplex impartire(NumarComplex n) {
        var conj = n.conjugat();
        var numitor = this.inmultire(conj);
        var numarator = n.inmultire(conj);
        return new NumarComplex(numitor.getRe()/numarator.getRe(), numitor.getIm()/numarator.getRe());
    }

    public NumarComplex conjugat() {
        return new NumarComplex(this.getRe(), (double)-1 * this.getIm());
    }

    @Override
    public String toString() {
        return "NumarComplex{" +
                "re=" + re +
                ", im=" + im +
                '}';
    }



}
