#include "capacidade.hpp"

bool Capacidade::validar(int valor){
    if(valor > MAXIMO || valor < MINIMO){
        return false;
    }
    return true;
}

bool Capacidade::setValor(int valor){
    if(!validar(valor)){
        return false;
    }
    this->valor = valor;
}
