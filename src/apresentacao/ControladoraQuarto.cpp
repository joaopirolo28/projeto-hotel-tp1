#include "apresentacao/ControladoraQuarto.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <iomanip>

using namespace std;

ControladoraQuarto::ControladoraQuarto(IServicoQuarto* sQuarto)
    : servicoQuarto(sQuarto) {}

Quarto ControladoraQuarto::coletarDadosQuarto() {
    string numeroStr, capacidadeStr, diariaStr, ramalStr;

    cout << "Numero do Quarto (001 a 999): ";
    cin >> numeroStr;

    cout << "Capacidade (1, 2, 3 ou 4): ";
    cin >> capacidadeStr;

    cout << "Diaria (Valor monetario, ex: 150.50): ";
    cin >> diariaStr;

    cout << "Ramal (00 a 50): ";
    cin >> ramalStr;

    Numero numero(stoi(numeroStr));
    Capacidade capacidade(stoi(capacidadeStr));
    Dinheiro diaria(stod(diariaStr));
    Ramal ramal(stoi(ramalStr));

    Quarto novoQuarto;
    novoQuarto.setNumero(numero);
    novoQuarto.setCapacidade(capacidade);
    novoQuarto.setDiaria(diaria);
    novoQuarto.setRamal(ramal);

    return novoQuarto;
}

void ControladoraQuarto::cadastrarQuarto() {
    cout << "\n--- CADASTRO DE QUARTO ---" << endl;
    string codigoHotelStr;

    cout << "Digite o Codigo do HOTEL onde o Quarto sera cadastrado: ";
    cin >> codigoHotelStr;

    try {
        Codigo codigoHotel(codigoHotelStr);
        Quarto novoQuarto = coletarDadosQuarto();

        if (servicoQuarto->cadastrarQuarto(codigoHotel, novoQuarto)) {
            cout << "\n Quarto numero " << novoQuarto.getNumero().getValor()
                 << " cadastrado no Hotel " << codigoHotel.getValor() << " com sucesso!" << endl;
        } else {
            cout << "\n Falha ao cadastrar Quarto. Verifique se o Hotel existe e se o Numero do Quarto ja esta em uso." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NO CADASTRO: " << e.what() << endl;
    }
}

void ControladoraQuarto::consultarQuarto() {
    cout << "\n--- CONSULTA DE QUARTO ---" << endl;
    string codigoHotelStr, numeroQuartoStr;

    cout << "Codigo do HOTEL: ";
    cin >> codigoHotelStr;
    cout << "Numero do QUARTO: ";
    cin >> numeroQuartoStr;

    try {
        Codigo codigoHotel(codigoHotelStr);
        Numero numeroQuarto(stoi(numeroQuartoStr));

        Quarto quarto = servicoQuarto->consultarQuarto(codigoHotel, numeroQuarto);

        cout << "\n QUARTO ENCONTRADO:" << endl;
        cout << "   Hotel: " << codigoHotel.getValor() << endl;
        cout << "   Numero: " << quarto.getNumero().getValor() << endl;
        cout << "   Capacidade: " << quarto.getCapacidade().getValor() << endl;
        cout << "   Diaria: R$ " << fixed << setprecision(2) << quarto.getDiaria().getValor() << endl;

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Codigo ou Numero invalidos. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO DE CONSULTA: Quarto nao encontrado ou Hotel inexistente. " << e.what() << endl;
    }
}

void ControladoraQuarto::editarQuarto() {
    cout << "\n--- EDICAO DE QUARTO ---" << endl;
    string codigoHotelStr;

    cout << "Digite o Codigo do HOTEL que contem o Quarto a ser editado: ";
    cin >> codigoHotelStr;

    try {
        Codigo codigoHotel(codigoHotelStr);
        Quarto quartoAtualizado = coletarDadosQuarto();

        if (servicoQuarto->editarQuarto(codigoHotel, quartoAtualizado)) {
            cout << "\n Quarto com Numero " << quartoAtualizado.getNumero().getValor()
                 << " no Hotel " << codigoHotel.getValor() << " editado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao editar Quarto. Verifique se o Hotel e o Quarto existem." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n️ ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EDICAO: " << e.what() << endl;
    }
}

void ControladoraQuarto::excluirQuarto() {
    cout << "\n--- EXCLUSAO DE QUARTO ---" << endl;
    string codigoHotelStr, numeroQuartoStr;

    cout << "Codigo do HOTEL: ";
    cin >> codigoHotelStr;
    cout << "Numero do QUARTO a ser excluido: ";
    cin >> numeroQuartoStr;

    try {
        Codigo codigoHotel(codigoHotelStr);
        Numero numeroQuarto(stoi(numeroQuartoStr));

        if (servicoQuarto->excluirQuarto(codigoHotel, numeroQuarto)) {
            cout << "\n Quarto " << numeroQuarto.getValor() << " do Hotel "
                 << codigoHotel.getValor() << " excluido com sucesso." << endl;
        } else {
            cout << "\n Falha ao excluir Quarto. Pode haver Reservas ativas (Violacao de Multiplicidade)." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Codigo ou Numero invalidos. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EXCLUSAO: " << e.what() << endl;
    }
}

void ControladoraQuarto::listarQuartos() {
    cout << "\n--- LISTAGEM DE QUARTOS ---" << endl;
    string codigoHotelStr;

    cout << "Digite o Codigo do HOTEL para listar os Quartos: ";
    cin >> codigoHotelStr;

    try {
        Codigo codigoHotel(codigoHotelStr);
        vector<Quarto> quartos = servicoQuarto->listarQuartos(codigoHotel);

        if (quartos.empty()) {
            cout << "Nenhum quarto cadastrado neste hotel ou hotel nao existe." << endl;
            return;
        }

        cout << "\nQUARTOS ENCONTRADOS NO HOTEL " << codigoHotel.getValor() << ":" << endl;
        for (const auto& quarto : quartos) {
            cout << "---------------------------------" << endl;
            cout << "Numero: " << quarto.getNumero().getValor() << endl;
            cout << "Capacidade: " << quarto.getCapacidade().getValor() << endl;
            cout << "Diaria: R$ " << fixed << setprecision(2) << quarto.getDiaria().getValor() << endl;
        }
        cout << "---------------------------------" << endl;

    } catch (const invalid_argument& e) {
        cout << "\n️ ERRO DE FORMATO: Codigo invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA LISTAGEM: " << e.what() << endl;
    }
}

void ControladoraQuarto::executar() {
    int opcao;

    do {
        cout << "\n--- GERENCIAR QUARTOS (CRUD) ---" << endl;
        cout << "1 - Cadastrar Novo Quarto" << endl;
        cout << "2 - Consultar Quarto (por Hotel e Numero)" << endl;
        cout << "3 - Editar Quarto" << endl;
        cout << "4 - Excluir Quarto" << endl;
        cout << "5 - Listar Todos os Quartos de um Hotel" << endl;
        cout << "0 - Voltar ao Menu Gerente" << endl;
        cout << "Selecione uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1: cadastrarQuarto(); break;
            case 2: consultarQuarto(); break;
            case 3: editarQuarto(); break;
            case 4: excluirQuarto(); break;
            case 5: listarQuartos(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
