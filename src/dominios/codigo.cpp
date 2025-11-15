#include "dominios/codigo.hpp"
#include <cctype>

using namespace std;

void Codigo::validar(string valor){
    if(valor.length()!=TAMANHO_MAX){
    throw invalid_argument("O codigo deve conter exatamente 10 carcteres.");
}
    for(char c: valor){
        if (!isalnum(c)){ 
            throw invalid_argument("O codigo deve conter apenas letras e digitos.");
        }
    }
}

void Codigo::setValor(string valor){
    validar(valor);
    this->valor=valor;
}

Codigo::Codigo(string valor){
    this->setValor(valor);
}

Codigo::Codigo(){}