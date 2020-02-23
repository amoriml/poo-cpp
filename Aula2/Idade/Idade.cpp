#include <iostream>

int main()
{
    int ano_atual, ano_nascimento, idade_atual;
    std::string nome;
    
    std::cin >> ano_atual;
    std::cin >> nome;
    std::cin >> ano_nascimento;
    
    idade_atual = ano_atual - ano_nascimento;
    
    std::cout << nome << ", voce completa " << idade_atual << " anos de idade neste ano." << std::endl;
    return 0;
}