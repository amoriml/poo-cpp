#include <iostream>

class Pilha{
    private:
        int tamanho;
        int* elementos;
        int topo;
    public:
        Pilha(){

        }
        Pilha(int tamanho){
            this->setTamanho(tamanho);
            this->setTopo(0);
            this->elementos = new int[tamanho];
        }
        int getTamanho(){
            return this->tamanho;
        }
        int getTopo(){
            return this->topo;
        }
        void setTamanho(int tamanho){
            this->tamanho = tamanho;
        }
        void setTopo(int topo){
            this->topo = topo;
        }
        void empilha(int valor){
            if(!this->isCheia()){
                this->elementos[this->getTopo()] = valor;
                this->setTopo(this->getTopo() + 1);
            }
        }
        void desempilha(){
            if(!this->isVazia()){
                this->elementos[this->getTopo() - 1] = 0;
                this->setTopo(this->getTopo() - 1);
            }
        }
        bool isCheia(){
            return this->getTamanho() == this->getTopo();
        }
        bool isVazia(){
            return this->getTopo() == 0;
        }
        void printTopo(){
            int i;
            for( i = this->getTopo() - 1; i >= 0; i --){
                std::cout << this->elementos[i] << std::endl;
            }
        }
        void printBase(){
            for(int i = 0; i < this->getTopo(); i ++){
                std::cout << this->elementos[i] << std::endl;
            }
        }
};

int main(){
    int tamanho, valor;
    char op;
    std::cin >> tamanho;
    Pilha* p =  new Pilha(tamanho);

    while(std::cin >> op){
        switch (op)
        {
            case 'E':
                std::cin >> valor;
                p->empilha(valor);
                break;
            case 'D':
                p->desempilha();
                break;
            case 'T':
                p->printTopo();
                break;
            case 'B':
                p->printBase();
                break;
            default:
                break;
        }
    }
    return 0;
}