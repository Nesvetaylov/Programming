import javax.print.DocFlavor;

public class Taxi extends Avto{
    private  String driver;
    private int price_km;
    Taxi(String marka, String number, String vin, int year, double vol, int price, int km, String driver, int price_km) {
        super(marka, number, vin, year, vol, price, km);
        this.driver=driver;
        this.price_km=price_km;
    }
    double cost(double km) {
        return km*price_km;
    }
    String getDriver() {
        return driver;
    }
    String setDriver() {
        return driver;
    }
    public String toString() {
        return super.toString() + "\nВодитель: "+driver+"\nЦена: "+price_km;
    }
}
