package Interface;

public class Shar implements Body {
    double r;
    public Shar(double r) {
        this.r=r;
    }

    @Override
    public double V() {
        return 4/3*Math.PI*r*r*r;
    }

    @Override
    public double S() {
        return 4*Math.PI*r*r;
    }

    @Override
    public void print() {
        System.out.println("Шар = "+r);
    }
}
