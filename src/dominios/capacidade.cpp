#include "dominios/capacidade.hpp"

Capacidade::Capacidade(){};

Capacidade::Capacidade(int valor){
    this->setValor(valor);
};

void Capacidade::validar(int valor){
    if(valor > MAXIMO || valor < MINIMO){
        throw invalid_argument("Capacidade invalida.");
    }
}

void Capacidade::setValor(int valor){
    validar(valor);
    this->valor = valor;
}
