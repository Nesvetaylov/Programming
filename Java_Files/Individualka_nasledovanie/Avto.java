package Individualka_nasledovanie;

public class Avto {
    String brand;
    int power;
    double engineVolume;

    public Avto(String brand, int power, double engineVolume) {
        this.brand = brand;
        this.power = power;
        this.engineVolume = engineVolume;
    }

    // Функции назначения и изменения полей

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public double getEngineVolume() {
        return engineVolume;
    }

    public void setEngineVolume(double engineVolume) {
        this.engineVolume = engineVolume;
    }

    public String toString() {
        return "Марка: "+brand+"\nМощность: "+power+"\nОбъем Двигателя: "+engineVolume;

    }
}