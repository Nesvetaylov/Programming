import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("введите кол-во: ");

        int n=sc.nextInt();
        Matrix matrix = new Matrix(n);
        matrix.printMatrix();

        System.out.println("Cумм = "+matrix.sumMainDiagonal());

        matrix.zamena0();
        matrix.printMatrix();


        System.out.println("введите число для проверки: ");
        int a=sc.nextInt();
        matrix.proizvLow(a);
        System.out.println("Произведение чисел ниже глав диог = "+matrix.proizvLow(a));
        System.out.println("Произведение совершенных эл-ов матрицы = "+matrix.proizvSov());

    }
}