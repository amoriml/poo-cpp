import java.util.Scanner;
import java.lang.Math;

public class Eq2{
    public static void main (String[] args) {
        double a, b, c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        
        double delta = Math.sqrt((Math.pow(b, 2.00) - (4*a*c)));
        double primeiraRaiz = (-b + delta)/(2*a);
        double segundaRaiz = (-b - delta)/(2*a);
        
        String str1 = String.format("%.4f", primeiraRaiz);
        String str2 = String.format("%.4f", segundaRaiz);
        System.out.println(str1 + " " + str2);
        
    }
}