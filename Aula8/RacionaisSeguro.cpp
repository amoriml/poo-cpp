#include<stdexcept>
#include<iostream>

class RacionalSeguro{
    private:
        int numerador;
        int denominador;
    public:
        RacionalSeguro(){};
        
        int getNumerador(){
            return this->numerador;
        }

        int getDenominador(){
            return this->denominador;
        }
        

};