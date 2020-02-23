#include <iostream>

class Fila{
    private:
        int tamanho;
        int *valores;
        int inicio, fim;
    public:
        Fila(){

        }
        Fila(int tamanho){
            this->valores = new int[tamanho];
            this->setTamanho(tamanho);
            this->setIncio(0);
            this->setFim(0);
        }
        int getTamanho(){
            return this->tamanho;
        }
        int getIncio(){
            return this->inicio;
        }
        int getFim(){
            return this->fim;
        }
        void setTamanho(int tamanho){
            this->tamanho = tamanho;
        }
        void setIncio(int inicio){
            this->inicio = inicio;
        }
        void setFim(int fim){
            this->fim = fim;
        }
        void enfileira(int valor){
            if(!this->isCheia()){
                this->valores[this->getFim()] = valor;
                this->setFim(this->getFim() + 1);
            }
        
        }
        void desenfileira(){
            if(!this->isVazia()){
                std::cout << this->valores[this->getIncio()] << std::endl;
                this->setIncio(this->getIncio() + 1);

                if(this->isCheia() && this->getIncio() == this->getFim()){
                    this->setFim(0);
                    this->setIncio(0);
                }
            }
        }
        bool isCheia(){
            return this->getFim() == this->getTamanho();
        }
        bool isVazia(){
            return this->getFim() == 0;
        }

};

int main(){
    char op;
    int tamanho;
    int valor;

    std::cin >> tamanho;
    Fila *f = new Fila(tamanho);
    while(std::cin >> op){
        if(op == 'E'){
            std::cin >> valor;
            f->enfileira(valor);
        }
        else if(op == 'D'){
            f->desenfileira();
        }
    }
    return 0;
}  