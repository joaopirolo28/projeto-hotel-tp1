#include "dominios/ramal.hpp"

void Ramal::setValor(int valor){
    validar(valor);
    this->valor = valor;
}


void Ramal::validar(int valor){
    if(valor < 0 || valor > LIMITE){
        throw invalid_argument("Valor invalido.");
    }
}
