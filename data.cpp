#include "data.hpp"

using namespace std;

void Data::setData(int dia, string mes, int ano){
    validar(dia, mes, ano);

    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

void Data::validar(int dia, string mes, int ano){
    int LIMITE;

    if(ano > 2999 || ano < 2000){
        throw invalid_argument("Ano invalido.");
    }

    if(MES_DIA[mes]){
        LIMITE = MES_DIA[mes];

        if(mes == "FEV"){
            if(bissexto(ano)){
                LIMITE++;
            }
        }
    }else{
        throw invalid_argument("Mes invalido.");
    }

    if(dia < 0 || dia > LIMITE){
        throw invalid_argument("Dia invalido");
    }
}

bool Data::bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        return true;
    }
    return false;
}
