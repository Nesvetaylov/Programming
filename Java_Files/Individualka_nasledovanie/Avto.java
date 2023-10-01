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
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public void setEngineVolume(int engineVolume) {
        this.engineVolume = engineVolume;
    }

    public String toString() {
        return "Марка: "+brand+"\nМощность: "+power+"\nОбъем Двигателя: "+engineVolume;

    }
}