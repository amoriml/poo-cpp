#include <iostream>

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Data(){

        }
        Data(int dia, int mes, int ano){
            this->setDia(dia);
            this->setMes(mes);
            this->setAno(ano);
        }
        int getDia(){
            return this->dia;
        }
        int getMes(){
            return this->mes;
        }
        int getAno(){
            return this->ano;
        }
        void setDia(int dia){
            this->dia = dia;
        }
        void setMes(int mes){
            this->mes = mes;
        }
        void setAno(int ano){
            this->ano = ano;
        }
        bool isDiaValido(){
            int diasEsperados = this->diasDoMesAtual();
            return (this->getDia() > 0 && this->getDia() <= diasEsperados);
        }
        bool isMesValido(){
            return (this->getMes() <= 12 && this->getMes() > 0);
        }
        bool isAnoValido(){
            return (this->getAno() >= 0);
        }
        bool isDataValida(){
            return (this->isDiaValido() && this->isMesValido() && this->isAnoValido());
        }
        bool isBixesto(){
            return (this->getAno() % 4 == 0 && this->getAno() % 100 != 0) || this->getAno() % 400 == 0;
        }
        int diasDoMesAtual(){
            int mesAtual = this->getMes();
            int dias = 30;
            switch(mesAtual){
                case 2:
                    if(this->isBixesto()){
                        return dias - 1;
                    }
                    else{
                        return dias - 2;
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    return dias;
                    break;
                default:
                    return dias + 1;
                    break;
            }
        }
};

int main(){
    int casosTeste;
    std::cin >> casosTeste;
    Data *dt;
    for(int i = 0; i < casosTeste; i ++){
        int dia, mes, ano;
        std::cin >> dia >> mes >> ano;
        dt = new Data(dia, mes,ano);
        bool resposta = dt->isDataValida();
        if(resposta){
            std::cout << "DATA VALIDA" << std::endl;
        }
        else{
            std::cout << "DATA INVALIDA" << std::endl;
        }
    }
    delete dt;
    return 0;
}