package Interface;


import java.util.*;
public class InterfaceBody {
    public static void main(String[] args) {
        Body[] f;
        Scanner sc=new Scanner(System.in);
        System.out.println("Введите уоличество элементов: ");
        int k=sc.nextInt();
        f=new Body[k];
        for (int i=0;i<k;i++) {
            System.out.println("1-шар,2-параллелограмм");
            int p=sc.nextInt();
            if (p==1) {
                System.out.println("Введите r: ");
                double r=sc.nextDouble();
                Shar shar=new Shar(r);
                f[i]=shar;
            }
            if (p==2) {
                System.out.println("Введите 3 стороны: ");
                double a=sc.nextDouble();
                double b1=sc.nextDouble();
                double c=sc.nextDouble();
                Paral paral=new Paral(a, b1, c);
                f[i]=paral;
            }
        }
        for (int i=0;i<k;i++) {
            f[i].print();
            System.out.println("S = "+f[i].S()+" "+"V = "+f[i].V());
        }
    }
}
