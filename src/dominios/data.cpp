#include "dominios/data.hpp"


using namespace std;

Data::Data(){}

Data::Data(int dia, string mes, int ano){
    this->setData(dia, mes, ano);
}

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

void Data::setValorDB(const std::string& dataCompleta) {
    if (dataCompleta.empty()) {
        return;
    }

    stringstream ss(dataCompleta);
    string diaStr, mesStr, anoStr;


    try {
        if (!getline(ss, diaStr, '-')) {
            throw invalid_argument("Erro de parsing: Dia nao encontrado.");
        }

        if (!getline(ss, mesStr, '-')) {
            throw invalid_argument("Erro de parsing: Mes nao encontrado.");
        }

        if (!getline(ss, anoStr)) {
            throw invalid_argument("Erro de parsing: Ano nao encontrado.");
        }

        int diaInt = std::stoi(diaStr);
        int anoInt = std::stoi(anoStr);

        setData(diaInt, mesStr, anoInt);

    } catch (const invalid_argument& e) {

        throw invalid_argument("Data com formato incorreto (DD-MMM-AAAA): " + std::string(e.what()));
    }
}
