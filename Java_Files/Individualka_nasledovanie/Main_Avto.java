import java.util.*;
public class Main_Avto {
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
        System.out.println("Введите данные авто: ");
        System.out.println("Введите марку: ");
        String brand=sc.nextLine();

        System.out.println("Введите мощность авто: ");
        int power=sc.nextInt();

        System.out.println("Введите объем двигателя авто: ");
        double engineVolume=sc.nextDouble();

        Avto a=new Avto(brand, power, engineVolume);
        System.out.println("Данные авто после ввода: ");
        System.out.println();
        System.out.println(a.toString());
        System.out.println("--------------------------");

        System.out.println("Введите количество сидячих мест: ");
        int seatingCapacity=sc.nextInt();
        System.out.println("--------------------------");

        PassengerCar pc=new PassengerCar(brand, power, engineVolume, seatingCapacity);
        System.out.println("Данные авто с введённым количеством мест: ");
        System.out.println();
        System.out.println(pc.toString());
        System.out.println("--------------------------");

        System.out.println("Данные авто с изменённым количеством мест: ");
        System.out.println();
        pc.setSeatingCapacity(2);
        System.out.println(pc.toString());


    }
}