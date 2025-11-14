#include "dominios/endereco.hpp"

void Endereco::setEndereco(string endereco){
    validar(endereco);
    endereco_Completo = endereco;
}

void Endereco::validar(string endereco){
    int tamanho = endereco.size();

    if(tamanho < 5 || tamanho > 30){
        throw invalid_argument("Maximo 30 caracteres / minimo 5 caracteres.");
    }

    if(endereco.front() == ',' || endereco.front() == '.' || endereco.front() == ' '){
        throw invalid_argument("Nao pode comecar com ponto, virgula ou espaco.");
    }
    if(endereco.back() == ',' || endereco.back() == '.' || endereco.back() == ' '){
        throw invalid_argument("Nao pode terminar com ponto, virgula ou espaco.");
    }

    for(int i = 0; i < tamanho; i++){
        char caracter = endereco[i];

        if(!isalnum(caracter) && caracter != ',' && caracter != '.' && caracter != ' '){
            throw invalid_argument("Algum caracter invalido.");
        }

        if(caracter == ',' || caracter == '.'){
            if(i+1 < tamanho && (endereco[i+1] == ',' || endereco[i+1] == '.')){
                throw invalid_argument("Ponto e virgula nao pode ser seguido de ponto ou virgula.");
            }
        }

        if(caracter == ' '){
            if(i+1 < tamanho && !isalnum((endereco[i+1]))){
                throw invalid_argument("Algum caracter invalido.");
            }
        }
    }
}
