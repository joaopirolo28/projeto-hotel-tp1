#include "ramal.hpp"

bool Ramal::setValor(int valor){
    if(!validar(valor)){
        return false;
    }
    this->valor = valor;
    return true;
}


bool Ramal::validar(int valor){
    if(valor < 0 || valor > LIMITE){
        return false;
    }
    return true;
}
