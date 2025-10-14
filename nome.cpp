#include "nome.hpp"

void Nome::validar(string nome){
    bool maiuscula = 0;

    if(nome.size() < 5 || nome.size() > 20){
        throw invalid_argument("Tamanho do nome, pequeno ou grande demais");
    }

    for(int i = 0; i < nome.size(); i++){
        char c = nome[i];

        if(isupper(c)){
            int j = i+1;
            while(nome[j] != ' ' && j < nome.size()){
                if(isupper(nome[j])){
                    throw invalid_argument("Cada palavra deve haver apenas uma letra maiuscula");
                }
                j++;
            }
        }

        if(!isalpha(c) && c != ' '){
            throw invalid_argument("Caracter(s) Invalido");
        }
        if(c == ' '){
            if(i == nome.size()-1){
                throw invalid_argument("Caracter no final não pode ser espaço");
            }
            if(nome[i+1] == ' '){
                throw invalid_argument("Não pode ter 2 espaços seguidos");
            }
        }
    }
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}
