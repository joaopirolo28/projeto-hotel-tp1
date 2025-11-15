#include "dominios/email.hpp"
#include<cctype>
#include<vector>
#include<sstream>

using namespace std;

void Email::validarParteLocal(string parteLocal){
    if(parteLocal.empty() || parteLocal.length()>TAMANHO_MAX_LOCAL){
        throw invalid_argument("Parte local invalida (mais de 64 caracteres ou vazia)");
    }
    if(parteLocal.front() == '.' || parteLocal.front() == '-' || parteLocal.back() == '.' || parteLocal.back()== '-' ){
        throw invalid_argument ("Parte local invalida, nao pode comecar com ponto ou hifen");
    }
    for(size_t i = 0; i<parteLocal.length(); i++){
        char c = parteLocal[i];
        if (!isalnum(c) && c != '.' && c!= '-'){
            throw invalid_argument("Parte local contem caractere invalido.");
        }
        if ((c == '.' || c == '-') && i+1 < parteLocal.length()){
            char proximo = parteLocal[i+i];
            if (!isalnum(proximo)){
                throw invalid_argument ("Ponto ou hifen deve ser seguido por uma letra ou digito");
            }
        }
    }
}

void Email::validarDominio(string dominio){
    if(dominio.empty() || dominio.length()>TAMANHO_MAX_DOMINIO){
        throw invalid_argument("Dominio vazio ou maior que 255 caracteres.");
    }
    stringstream ss(dominio);
    string parte;
    while (getline(ss, parte, '.')){
        if(parte.empty()){
            throw invalid_argument("Dominio contem partes vazias.");
        }
        if(parte.front() == '-' || parte.back() == '-'){
            throw invalid_argument("Partes do dominio nao podem comecar ou terminar com hifen.");
        }
        for(char c : parte){
            if(!isalnum(c) && c != '-'){
                throw invalid_argument ("Dominio contem caractere invalido.");
            }
        }
    }
}

void Email::validar(string email){
    size_t posArroba = email.find('@');
    if (posArroba == string::npos){
        throw invalid_argument("Email deve conter um caractere '@'.");
    }
    if(email.find('@', posArroba +1) != string::npos){
        throw invalid_argument("Email nao pode conter mais de um '@");
    }
    string parteLocal = email.substr(0,posArroba);
    string dominio = email.substr(posArroba + 1);

    validarParteLocal(parteLocal);
    validarDominio(dominio);
}

void Email::setEmail(string email) {
    validar(email);
    this->email = email;
}

Email::Email(string email){
    this->setEmail(email);
}

Email::Email(){}
