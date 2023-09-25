// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Avto {
    String marka;
    String number;
    String vin;
    int year;
    double vol;
    int price;
    int km;
    Avto(String marka, String number, String vin, int year, double vol, int price,int km) {
    this.marka=marka;
    this.number=number;
    this.vin=vin;
    this.year=year;
    this.vol=vol;
    this.price=price;
    this.km=km;
    }
    public String toString() {
        return "Марка: "+marka+"\nНомер: "+number+"\nВин: "+vin+"\nГод: "+year+"\nОбъем двигателя"
                +vol+"\nЦена: "+price+"\nПробег: "+km;

    }
    String getMarka() {
        return marka;
    }
    String getNumber() {
        return number;
    }
    String getVin() {
        return vin;
    }
    public int getYear() {
        return year;
    }
    public double getVol() {
        return vol;
    }
    public int getPrice() {
        return price;
    }
    public int getKm() {
        return km;
    }
}

