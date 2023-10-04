package Individualka_nasledovanie;

public class PassengerCar extends Avto {
    private int seatingCapacity;

    public PassengerCar(String brand, int power, double engineVolume, int seatingCapacity) {
        super(brand, power, engineVolume);
        this.seatingCapacity = seatingCapacity;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }
    // Функция переназначения количества мест

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    @Override
    public String toString() {
        return super.toString()+"\nКоличество сидячих мест: "+seatingCapacity;
    }
}