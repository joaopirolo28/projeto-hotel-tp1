#include"numero.hpp"

using namespace std;

void Numero::validar(int valor){
    if(valor<LIMITE_INFERIOR || valor > LIMITE_SUPERIOR){
        throw invalid_argument("Valor deve estar entre 1 e 999.");
    }
}

Numero::Numero(int valor){
    validar(valor);
    this->valor = valor;
}

void Numero::setValor(int valor){
    validar(valor);
    this->valor=valor;
}