import java.util.Scanner;

public class DivResto{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int div = a/b;
        int resto = a%b;
        
        System.out.println(div + " " + resto);
    }
}