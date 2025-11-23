#include"dominios/cartao.hpp"
#include<stdexcept>
#include<cctype>
#include<numeric>

using namespace std;

Cartao::Cartao(){};

Cartao::Cartao(string valorCartao){
    this->setValor(valorCartao);
}



void Cartao::validar(string valorCartao){
    if(valorCartao.length() != 16){
        throw invalid_argument("Numero do cartao deve ter 16 digitos.");
    }


    for(int i = valorCartao.length()-1; i>=0; i--){
        if(!isdigit(valorCartao[i])){
            throw invalid_argument("Cartao deve ter apenas numeros.");
        }
    }


    int soma = 0;
    bool dobra = false;

    for(int i = valorCartao.length()-1; i>=0; i--){
        int digito = valorCartao[i] - '0';

        if (dobra){
            digito *= 2;

            if(digito > 9){
                digito = digito - 9;
            }
        }

        soma += digito;
        dobra = !dobra; // Alterna para o próximo dígito
    }

    if(soma%10 != 0){
        throw invalid_argument("Numero do cartao invalido, falha no algoritmo de Luhn.");
    }
}

void Cartao :: setValor(string valorCartao){
    validar(valorCartao);
    this->valor = valorCartao;
}



