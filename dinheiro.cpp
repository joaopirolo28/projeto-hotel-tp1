#include"dinheiro.hpp"
#include<cmath>
#include<stdexcept>

const double LIMITE_MAXIMO = 1000000.00;

Dinheiro::Dinheiro(){
    this->valorCentavos = 0;
}

void Dinheiro::validar(double valor)const{
    if(valor<=0.0){
        throw invalid_argument("Valor nao pode ser negativo nem nulo.");
    }

    if(valor>= LIMITE_MAXIMO){
        throw invalid_argument("Valor execede o limite maximo permitido.");
    }
    double centavos = valor * 100.0;
    if(abs(centavos - round(centavos))> 0.0001){
        throw invalid_argument("Valor nao pode ter mais de duas casas decimais.");
    }
}

void Dinheiro :: setValor(double valor){
    validar(valor);
    this->valorCentavos = static_cast<long int>(round(valor*100.0));
}

double Dinheiro :: getValor() const{
    return static_cast<double>(this->valorCentavos)/100.0;
}