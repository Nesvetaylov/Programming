package Interface;

public class Paral implements Body {
    double a,b,c;

    public Paral(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double V() {
        return a*b*c;
    }

    @Override
    public double S() {
        return 2*(a*b+b*c+a*c);
    }

    @Override
    public void print() {
        System.out.println("параллелограмм = "+a+" "+b+" "+c);
    }
}
