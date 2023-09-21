import java.util.Random;
public class Matrix {

    private int n;
    private int[][] arr;


    Matrix(int m){ //создание матрицы
        n=m;
        arr=new int[n][n];
        Random r= new Random();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = r.nextInt(50);
            }
        }
    }

    public void printMatrix(){ //ввод ее
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println(" ");
        }

    }

    public int sumMainDiagonal(){
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j&&(Functions.prosto(arr[i][j])==true)){
                    sum+=arr[i][j];
                }
            }
        }
        return sum;
    }
    public void zamena0(){

        for(int j=0;j<n;j++){
            int k=0;
            for(int i=0;i<n;i++){
                if(Functions.sov(arr[j][i])==true) k++;
            }
            if(k>2){
                for(int i=0;i<n;i++){
                    if(arr[j][i]%2==0) arr[j][i]=0;
                }
            }
        }
    }

    public int proizvLow(int a){
        int pr=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>a&&(i>n-1-j)){
                    pr*=arr[i][j];
                }

            }
        }
        return pr;
    }

    public int proizvSov(){
        int pr=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Functions.sov(arr[i][j])==true)
                    pr*=arr[i][j];
            }
        }
        return pr;
    }

}
