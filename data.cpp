#include "data.hpp"

using namespace std;

bool Data::setData(int dia, string mes, int ano){
    if(!validar(dia, mes, ano)){
        return false;
    }
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    return true;
}

bool Data::validar(int dia, string mes, int ano){
    int LIMITE;

    if(ano > 2999 || ano < 2000){
        return false;
    }

    if(MES_DIA[mes]){
        LIMITE = MES_DIA[mes];

        if(mes == "FEV"){
            if(bissexto(ano)){
                LIMITE++;
            }
        }
    }else{
        return false;
    }

    if(dia < 0 || dia > LIMITE){
        return false;
    }

    return true;
}

bool Data::bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        return true;
    }
    return false;
}
