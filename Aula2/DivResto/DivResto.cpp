#include <iostream>

int main()
{
    int a, b, div, resto;
    
    std::cin >> a >> b;
    
    div = a / b;
    resto = a % b;
    
    std::cout << div << " " << resto << std::endl;    
    
    return 0;
}