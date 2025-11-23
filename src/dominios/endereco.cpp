#include "dominios/endereco.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;



void Endereco::validar(string valor) {


    if (valor.length() < 5 || valor.length() > 30) {
        throw invalid_argument("Tamanho invalido. O endereco deve ter 5 a 30 caracteres.");
    }


    char primeiro = valor[0];
    char ultimo = valor[valor.length() - 1];


    if (primeiro == ' ' || primeiro == ',' || primeiro == '.') {
        throw invalid_argument("Endereco nao pode comecar com espaco, virgula ou ponto.");
    }
    if (ultimo == ' ' || ultimo == ',' || ultimo == '.') {
        throw invalid_argument("Endereco nao pode terminar com espaco, virgula ou ponto.");
    }


    for (size_t i = 0; i < valor.length(); ++i) {
        char c = valor[i];


        char c_next = (i < valor.length() - 1) ? valor[i+1] : '\0';


        if (!isalnum(c) && c != ' ' && c != ',' && c != '.') {
            throw invalid_argument("Endereco com caracter invalido ou nao permitido(nao coloque acento).");
        }


        if (c == ' ' || c == ',' || c == '.') {


            if (c_next == ' ' || c_next == ',' || c_next == '.') {
                throw invalid_argument("Endereco com pontuacao/espaco seguido por outro pontuacao/espaco (sequencia invalida).");
            }


            if (c == ' ' && !isalnum(c_next) && c_next != '\0') {
                 throw invalid_argument("O espaco deve ser seguido por letra ou digito no endereco.");
            }
        }
    }
}


Endereco::Endereco() {}

Endereco::Endereco(string valor) {
    this->setEndereco(valor);
}


void Endereco::setEndereco(string endereco) {
    validar(endereco);
    this->endereco_Completo = endereco;
}
