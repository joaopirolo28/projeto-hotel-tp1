#include <iostream>
#include<stdexcept>
#include "dominios.hpp" //juntei em dominios para ficar mais limpo -Tarsila

using namespace std;

int main()
{
    Data a;

    if(a.setData(4, "FEV", 2019)){
        cout << "Data = " << a.getDia() << '/' << a.getMes() << '/' << a.getAno() << endl;
    }else{
        cout << "Data invalido" << endl;
    }

    if(a.setData(29, "FEV", 2025)){
        cout << "Data = " << a.getDia() << '/' << a.getMes() << '/' << a.getAno() << endl;
    }else{
        cout << "Data invalido" << endl;
    }

    Capacidade b;

    if(b.setValor(3)){
        cout << "Valor = " << b.getValor() << endl;
    }else{
        cout << "Valor invalido" << endl;
    }

    if(b.setValor(30)){
        cout << "Valor = " << b.getValor() << endl;
    }else{
        cout << "Valor invalido" << endl;
    }

    Endereco casinha;

    if(casinha.setEndereco("Pequepe, lote 21, apt.666")){
        cout << "Endereco = " << casinha.getEndereco() << endl;
    }else{
        cout << "Endereco invalido" << endl;
    }

    if(casinha.setEndereco("Pequepe,. lote 21, apt.666")){
        cout << "Endereco = " << casinha.getEndereco() << endl;
    }else{
        cout << "Endereco invalido" << endl;
    }

    Ramal ramal;

    if(ramal.setValor(43)){
        cout << "Ramal = " << ramal.getValor() << endl;
    }else{
        cout << "Ramal invalido" << endl;
    }

    if(ramal.setValor(55)){
        cout << "Valor = " << ramal.getValor() << endl;
    }else{
        cout << "Valor invalido" << endl;
    }

    try{
        Codigo codigo("HotelPqpes");
        cout<<"Codigo criado com sucesso: "<<codigo.getValor()<< endl;
        Codigo codigoInvalido("H@tel!");
    }catch(const invalid_argument &exp){
        cout<<"Erro ao criar codigo: "<<exp.what()<<endl;
    }

    try{
        Email email("m.nome-123@gmail.com");
        cout<<"Email criado: "<<email.getEmail()<<endl;
    } catch(const invalid_argument& exp){
        cout<<"Erro inesperado: "<<exp.what()<<endl;
    }
    try{
        Email email_invalido(".comeca@componto.com");
    }catch(const invalid_argument &exp){
        cout<<"Erro inesperado: "<< exp.what()<<endl;
    }
    
    try {
        Email email_invalido("outro@dominio..com");
    } catch(const invalid_argument& exp) {
        cout<<"Erro esperado: "<< exp.what()<<endl;
    }
    return 0;

}
