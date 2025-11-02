#include "capacidade.hpp"

void Capacidade::validar(int valor){
    if(valor > MAXIMO || valor < MINIMO){
        throw invalid_argument("Capacidade invalida.");
    }
}

void Capacidade::setValor(int valor){
    validar(valor);
    this->valor = valor;
}
