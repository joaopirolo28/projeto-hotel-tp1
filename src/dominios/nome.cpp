#include "dominios/nome.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;

void Nome::validar(string nome) {

    if (nome.size() < 5 || nome.size() > 20) {
        throw invalid_argument("Tamanho do nome, pequeno ou grande demais.");
    }

    if (nome[0] == ' ') {
        throw invalid_argument("O nome nao pode comecar com espaco.");
    }

    for (int i = 0; i < nome.size(); i++) {
        char c = nome[i];

        if (!isalpha(c) && c != ' ') {
            throw invalid_argument("Caracter(s) Invalido. Apenas letras e espacos.");
        }



        if (c == ' ') {

            if (i == nome.size() - 1) {
                throw invalid_argument("O nome nao pode terminar com espaco.");
            }

            if (nome[i+1] == ' ') {
                throw invalid_argument("Nao pode ter 2 espacos seguidos.");
            }

            continue;
        }


        bool inicioDaPalavra = (i == 0 || nome[i - 1] == ' ');

        if (inicioDaPalavra) {

            if (!isupper(c)) {
                throw invalid_argument("Cada palavra deve comecar com letra maiuscula.");
            }
        } else {

            if (isupper(c)) {
                throw invalid_argument("Apenas a primeira letra da palavra deve ser maiuscula.");
            }
        }
    }
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}

Nome::Nome(){}

Nome::Nome(string nome){
    this->setNome(nome);
}
