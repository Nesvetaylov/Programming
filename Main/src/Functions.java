public class Functions {
    public static boolean prosto(int n){
        //ф-ия на простоту
        int k = 0;
        for (int i =2; i < n; i++)
        {
            if (n % i == 0) k++;
        }
        if (k == 0) return true;
        return false;
    }

    public static boolean sov(int x){
        int sum = 0;
        for (int i = 1; i < x; i++){
            if (x % i == 0) sum += i;
        }
        if (sum == x) return true;
        return false;
    }

}

