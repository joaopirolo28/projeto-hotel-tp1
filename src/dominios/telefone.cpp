#include"dominios/telefone.hpp"
#include<cctype>

void Telefone::validar(const string& valor){
    if(valor.front()!='+'){
        throw invalid_argument("Telefone deve comecar com '+'.");
    }
    if(valor.length()!=TAMANHO){
        throw invalid_argument("Telefone precisa ter 12 caracteres");
    }
    for(size_t i = 1; i<valor.length(); ++i){
        if(!isdigit(valor[i])){
            throw invalid_argument("Apos o '+' deve conter apenas digitos.");
        }
    }
}

void Telefone::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

Telefone::Telefone(string valor){
    this->setValor(valor);
}

Telefone::Telefone(){}
