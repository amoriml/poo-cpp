import java.util.Scanner;

public class Idade{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int anoAtual = sc.nextInt();
        String nome = sc.next();
        int anoNascimento = sc.nextInt();
        int idade = anoAtual - anoNascimento;
        
        System.out.println(nome + ", voce completa " + idade + " anos de idade neste ano.");
    }
}