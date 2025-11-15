#include "dominios/senha.hpp"

void Senha::validar(string senha){
    if(senha.size() != 5){
        throw invalid_argument("Tamanho incorreto");
    }

    int qntm = 0;
    int qntM = 0;
    int qntd = 0;

    for(int i = 0; i < senha.size(); i++){
        char c = senha[i];


        if(!isalnum(c) && !especiais[c]){
            throw invalid_argument("Senha invalida");
        }

        if(isdigit(c)){
            qntd++;
        }else if(isalpha(c)){
            if(isupper(c)){
                qntM++;
            }else{
                qntm++;
            }
        }

        if(isdigit(c) && isdigit(senha[i+1]) && (i+1) < senha.size()){
            throw invalid_argument("Nao pode ter digito seguido");
        }

        if(isalpha(c) && isalpha(senha[i+1]) && (i+1) < senha.size()){
            throw invalid_argument("Nao pode ter letra seguido");
        }

    }
    if(qntd == 0 || qntM == 0 || qntm == 0){
        throw invalid_argument("Deve ter pelo menos uma letra minuscula, uma minuscula e um digito");
    }
}

void Senha::setSenha(string senha){
    validar(senha);
    this->senha = senha;
}

Senha::Senha(){}

Senha::Senha(string senha){
    this->setSenha(senha);
}