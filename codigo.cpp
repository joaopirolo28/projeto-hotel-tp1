#include "codigo.hpp"
#include <cctype>

using namespace std;

void Codigo::validar(const string&valor){
    if(valor.length()!=TAMANHO_MAX){
    throw invalid_argument("O codigo deve conter exatamente 10 carcteres.");   
}
    for(char c: valor){
        if (!isalnum(c)){ //confere se é um caracterere alfanumerico
            throw invalid_argument("O codigo deve conter apenas letras e digitos.");
        }
    }
}

void Codigo::setValor(const string&valor){
    validar(valor);
    this->valor=valor;
}

Codigo::Codigo(const string&valor){
    validar(valor);
    this->valor=valor;
}