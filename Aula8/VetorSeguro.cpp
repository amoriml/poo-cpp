#include<iostream>
#include<stdexcept>

class TamanhoMuitoGrandeException : public std::runtime_error{
    public:
        TamanhoMuitoGrandeException():std::runtime_error("runtime error: indice fora dos limites do vetor."){}
};


class VetorSeguro{
    private:
        int tamanho;
        int* vetor;
    public:
        VetorSeguro(){}

        VetorSeguro(int tamanho){
            this->setTamanho(tamanho);
            this->vetor = new int[tamanho];
        }

        int getTamanho(){
            return this->tamanho;
        }

        void setTamanho(int tamanho){
            this->tamanho = tamanho;
        }

        int acessaVetor(int indice) throw(TamanhoMuitoGrandeException){
            if(indice >= this->getTamanho() || indice < 0){
                throw TamanhoMuitoGrandeException();    
            }
            else{
                return this->vetor[indice];
            }
        }

        void inserirValor(int valor, int indice){
            this->vetor[indice] = valor;
        }

};


int main(){
    int tamanho, valor;
    std::cin >> tamanho;
    VetorSeguro vetor = VetorSeguro(tamanho);

    for(int i = 0; i < vetor.getTamanho(); i ++){
        std::cin >> valor;
        vetor.inserirValor(valor, i);
    }

    int indice;
    while(std::cin >> indice){
        try{
            int resultado = vetor.acessaVetor(indice);
            std::cout << resultado << std::endl;
        }
        catch(TamanhoMuitoGrandeException e){
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}