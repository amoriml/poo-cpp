#include <iostream>

class Item{
    private:
        int chave;
        Item* proximo;
    public:
        Item(){}
        Item(int chave){
            this->chave = chave;
        }
        Item(int chave, Item* elemento){
            this->setChave(chave);
            this->setProximo(elemento);
        }
        int getChave(){
            return this->chave;
        }
        Item* getProximo(){
            return this->proximo;
        }
        void setChave(int chave){
            this->chave = chave;
        }
        void setProximo(Item* proximo){
            this->proximo = proximo;
        }    
};
class LDE{
    private:
        Item* primeiro;
        Item* ultima;
        int totalDeElementos;

    public:
        LDE(){
            totalDeElementos = 0;
        }
        LDE(Item* primeiro){
            this->setPrimeiro(primeiro);
            totalDeElementos = 0;
        }
        int getTotalElementos(){
            return this->totalDeElementos;
        }
        Item* getPrimeiro(){
            return this->primeiro;
        }
        Item* getUltimo(){
            return this->ultima;
        }
        Item* getItem(int index){
            Item* atual = this->getPrimeiro();
            for(int i = 0; i < index - 1; i ++){
                atual = atual->getProximo();
            }
            return atual;
        }
        void setPrimeiro(Item* primeiro){
            this->primeiro = primeiro;
        }
        void setUltimo(Item* item){
            this->ultima = item;
        }
        void setTotalElementos(int elementos){
            this->totalDeElementos = elementos;
        }
        void inserir(int valor){
            if(this->getTotalElementos() == 0){
                Item* item = new Item(valor);
                this->setPrimeiro(item);
                this->setUltimo(item);
                this->setTotalElementos(this->getTotalElementos() + 1);
            }
            else{

                for(int i = 0; i < totalDeElementos; i ++){
                    Item* atual = this->getItem(i);
                    if(atual->getChave() > valor){
                        Item* item = new Item(valor, atual);
                        if(i > 0){
                            Item* anterior = this->getItem(i - 1);
                            anterior->setProximo(item);
                        }
                        else{
                            
                        }
                        
                    }
                }
            }
        }
        void remover(int valor){

        }
        bool buscar(int valor){

        }
        void listar(){

        }

};