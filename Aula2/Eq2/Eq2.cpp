#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    float a, b, c;
    
    std::cin >> a >> b >> c;
    
    float delta = (float) sqrt((b*b) - (4.00*a*c));
    float primeira_raiz = (float) (-b + delta)/(2.00*a);
    float segunda_raiz = (float) (-b - delta)/(2.00*a);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(4) << primeira_raiz << " " << std::setprecision(4) << segunda_raiz << std::endl;
    return 0;    
}