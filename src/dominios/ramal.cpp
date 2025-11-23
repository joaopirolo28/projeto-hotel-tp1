#include "dominios/ramal.hpp"

void Ramal::setValor(int valor){
    validar(valor);
    this->valor = valor;
}


void Ramal::validar(int valor){
    if(valor < 0 || valor > LIMITE){
        throw invalid_argument("Valor invalido. EScolha um numero entre 1-50");
    }
}
Ramal::Ramal(){}

Ramal::Ramal(int valor){
    this->setValor(valor);
}
