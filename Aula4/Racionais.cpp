#include <iostream>
#include <cmath>

struct tRacional
{
  int numerador;
  int denominador;
  
};

struct tRacional racional(int, int);
struct tRacional negativo(struct tRacional);
struct tRacional soma(struct tRacional, struct tRacional);
struct tRacional mult(struct tRacional, struct tRacional);
struct tRacional div(struct tRacional, struct tRacional);
struct tRacional reduz(struct tRacional);
int calculaMMC(int, int);
int calculaMDC(int, int);


int main()
{
    int n1, d1, n2, d2;
    char operacao;
    
    while (std::cin >> n1 >> d1 >> operacao >> n2 >> d2)
    {
        struct tRacional primeiroRacional = racional(n1, d1);
        struct tRacional segundoRacional = racional(n2, d2);
        struct tRacional resultado;
        struct tRacional racionalNegativo;
        //menu de operações
        switch (operacao)
        {
            case '+':
                resultado = soma(primeiroRacional, segundoRacional);
                break;
                
            case '-':
                racionalNegativo = negativo(segundoRacional);
                resultado = soma(primeiroRacional, racionalNegativo);
                break;
                
            case '*':
                resultado = mult(primeiroRacional, segundoRacional);
                break;
                
            case '/':
                resultado = div(primeiroRacional, segundoRacional);
                
                break;
            default:
                break;
        }
        
        std::cout << resultado.numerador << " " 
                        << resultado.denominador
                        << std::endl;
    }
    return 0;
}

int calculaMMC(int numero1, int numero2)
{
    int resto, num1, num2;
    num1 = numero1;
    num2 = numero2;

    do{
        resto = num1 % num2;
        num1 = num2;
        num2 = resto;

    }while(resto != 0);
    return (numero1 * numero2)/ num1;
}

int calculaMDC (int num1, int num2)
{
    int numero1 = std::abs(num1);
    int numero2 = std::abs(num2);
    if(numero1 == numero2)
        return numero1;
        
    //algoritmo de euclides
    int maior, menor;
    if(numero1 > numero2)
    {
        maior = numero1;
        menor = numero2;
    }
    else
    {
        maior = numero2;
        menor = numero1;
    }
    
    int resto = maior%menor;
    while(resto > 0)
    {
        maior = menor;
        menor = resto;
        resto = maior%menor;
        
    }
    
    return menor;
}
struct tRacional racional(int numerador, int denominador)
{
    struct tRacional numeroRacional = {numerador, denominador};
    return numeroRacional;
}

struct tRacional reduz(struct tRacional numRacional)
{
    struct tRacional fracaoReduzida;
    int mdc = calculaMDC(numRacional.numerador, numRacional.denominador);
    fracaoReduzida.numerador = numRacional.numerador/mdc;
    fracaoReduzida.denominador = numRacional.denominador/mdc;
    
    return fracaoReduzida;
}

struct tRacional soma(struct tRacional racionalUm, struct tRacional racionalDois)
{
    struct tRacional resultado;
    int mmc = calculaMMC(racionalUm.denominador, racionalDois.denominador);
    resultado.denominador = mmc;
    resultado.numerador = ((mmc/racionalUm.denominador)*racionalUm.numerador) + 
                            ((mmc/racionalDois.denominador)*racionalDois.numerador);
    return reduz(resultado);
    
}
struct tRacional mult(struct tRacional racionalUm, struct tRacional racionalDois)
{
    struct tRacional resultado;
    resultado.numerador = racionalUm.numerador * racionalDois.numerador;
    resultado.denominador = racionalUm.denominador*racionalDois.denominador;
    
    return reduz(resultado);
}
struct tRacional div(struct tRacional racionalUm, struct tRacional racionalDois)
{
    struct tRacional resultado;
    resultado.numerador = racionalUm.numerador*racionalDois.denominador;
    resultado.denominador = racionalUm.denominador*racionalDois.numerador;
    
    return reduz(resultado);
}
struct tRacional negativo(struct tRacional numRacional)
{
    struct tRacional racionalNegativo;
    racionalNegativo.numerador = -numRacional.numerador;
    racionalNegativo.denominador = numRacional.denominador;
    
    return racionalNegativo;
    
}