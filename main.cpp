#include <iostream>

#include "capacidade.hpp"
#include "data.hpp"
#include "endereco.hpp"
#include "ramal.hpp"

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

    return 0;

}
