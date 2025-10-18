#include"cartao.hpp"
#include<stdexcept>
#include<cctype>
#include<numeric>

using namespace std;

void Cartao::validar(const string&valorCartao)const{
    if(valorCartao.length() != 16){
        throw invalid_argument("Numero do cartao deve ter 16 digitos.");
    }
    int soma = 0;
    bool dobra = false;
    for(int i = valorCartao.length()-1; i>=0; i--){
        if(!isdigit(valorCartao[i])){
            throw invalid_argument("cartao deve ter apenas numeros.");
        }
        int digito = valorCartao[i] - '0';
        if (dobra){
            digito *= 2;
            if(digito>9){
                digito = (digito%10)*1;
            }
        }
        soma += digito;
        dobra = !dobra;
    }
    if(soma%10!=0){
        throw invalid_argument("Numero do cartao invalido, falha no algoritmo de Luhn.");
    }
}

void Cartao :: setValor(const string&valorCartao){
    validar(valorCartao);
    this->valor = valorCartao;
}

