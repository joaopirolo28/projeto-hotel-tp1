#include "endereco.hpp"

bool Endereco::setEndereco(string endereco){
    if(!validar(endereco)){
        return false;
    }
    endereco_Completo = endereco;
}

bool Endereco::validar(string endereco){
    int tamanho = endereco.size();

    if(tamanho < 5 || tamanho > 30){
        return false;
    }

    if(endereco.front() == ',' || endereco.front() == '.' || endereco.front() == ' '){
        return false;
    }
    if(endereco.back() == ',' || endereco.back() == '.' || endereco.back() == ' '){
        return false;
    }

    for(int i = 0; i < tamanho; i++){
        char caracter = endereco[i];

        if(!isalnum(caracter) && caracter != ',' && caracter != '.' && caracter != ' '){
            return false;
        }

        if(caracter == ',' || caracter == '.'){
            if(i+1 < tamanho && (endereco[i+1] == ',' || endereco[i+1] == '.')){
                return false;
            }
        }

        if(caracter == ' '){
            if(i+1 < tamanho && !isalnum((endereco[i+1]))){
                return false;
            }
        }
    }
    return true;
}
