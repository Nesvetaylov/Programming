import java.util.*;

public class ExtendsAvto {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Введите данные для авто: ");
        System.out.println("Введите марку: ");
        String marka=sc.nextLine();
        System.out.println("Введите номер: ");
        String number=sc.nextLine();
        System.out.println("Введите вин: ");
        String vin=sc.nextLine();
        System.out.println("Введите год выпуска: ");
        int year=sc.nextInt();
        System.out.println("Введите объем двигателя: ");
        double vol=sc.nextDouble();
        System.out.println("Введите цена: ");
        int price=sc.nextInt();
        System.out.println("Введите пробег: ");
        int km=sc.nextInt();
        Avto a=new Avto(marka,number,vin, year,vol,price,km);
        System.out.println("Данные авто: ");
        System.out.println(a.toString());

        String q=sc.nextLine();//Пустая строка
        System.out.println("Введите ФИО водителя: ");
        String f=sc.nextLine();
        System.out.println("Введите стоимость за км: ");
        int price_km=sc.nextInt();
        Taxi t=new Taxi(marka,number,vin, year,vol,price,km, f, price_km);
        System.out.println("введите дальность расстояния в км: ");
        double km1=sc.nextDouble();
        System.out.println("Стоимость поездки: "+t.cost(km1));
        System.out.println("Данные такси: ");
        System.out.println(t.toString());
    }
}
