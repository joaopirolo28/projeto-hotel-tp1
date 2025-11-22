#include "apresentacao/ControladoraHospede.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

ControladoraHospede::ControladoraHospede(IServicoHospede* sHospede)
    : servicoHospede(sHospede){}

Hospede ControladoraHospede::coletarDadosHospede() {
    string nomeStr, emailStr, enderecoStr, cartaoStr;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nome do Hospede: ";
    getline(cin, nomeStr);

    cout << "Endereco: ";
    getline(cin, enderecoStr);

    cout << "Email (Chave Primaria): ";
    cin >> emailStr;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Cartao (16 digitos, Luhn): ";
    cin >> cartaoStr;

    Nome nome(nomeStr);
    Email email(emailStr);
    Endereco endereco(enderecoStr);
    Cartao cartao(cartaoStr);

    Hospede novoHospede;
    novoHospede.setNome(nome);
    novoHospede.setEmail(email);
    novoHospede.setEndereco(endereco);
    novoHospede.setCartao(cartao);

    return novoHospede;
}

void ControladoraHospede::cadastrarHospede() {
    cout << "\n--- CADASTRO DE HÓSPEDE ---" << endl;
    try {
        Hospede novoHospede = coletarDadosHospede();

        if (servicoHospede->cadastrarHospede(novoHospede)) {
            cout << "\n Hóspede '" << novoHospede.getNome().getNome() << "' cadastrado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao cadastrar Hóspede. O email pode já existir." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NO CADASTRO: " << e.what() << endl;
    }
}

void ControladoraHospede::consultarHospede() {
    cout << "\n--- CONSULTA DE HÓSPEDE ---" << endl;
    string emailStr;

    cout << "Digite o Email do Hóspede para consulta: ";
    cin >> emailStr;

    try {
        Email email(emailStr);

        Hospede hospede = servicoHospede->consultarHospede(email);

        cout << "\n HÓSPEDE ENCONTRADO:" << endl;
        cout << "   Nome: " << hospede.getNome().getNome() << endl;
        cout << "   Email: " << hospede.getEmail().getEmail() << endl;
        cout << "   Endereco: " << hospede.getEndereco().getEndereco() << endl;
        cout << "   Cartao: " << hospede.getCartao().getValor() << endl;

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Email inválido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO DE CONSULTA: Hóspede não encontrado. " << e.what() << endl;
    }
}

void ControladoraHospede::editarHospede() {
    cout << "\n--- EDIÇÃO DE HÓSPEDE ---" << endl;

    try {
        Hospede hospedeAtualizado = coletarDadosHospede();

        if (servicoHospede->editarHospede(hospedeAtualizado)) {
            cout << "\n Hóspede com Email '" << hospedeAtualizado.getEmail().getEmail() << "' editado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao editar Hóspede. Verifique se o Email existe." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EDIÇÃO: " << e.what() << endl;
    }
}

void ControladoraHospede::excluirHospede() {
    cout << "\n--- EXCLUSÃO DE HÓSPEDE ---" << endl;
    string emailStr;
    cout << "Digite o Email do Hóspede a ser excluído: ";
    cin >> emailStr;

    try {
        Email email(emailStr);

        if (servicoHospede->excluirHospede(email)) {
            cout << "\n Hóspede com Email '" << email.getEmail() << "' excluído com sucesso." << endl;
        } else {
            cout << "\n Falha ao excluir Hóspede. Pode haver Reservas ativas (Violacao de Multiplicidade)." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Email inválido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EXCLUSÃO: " << e.what() << endl;
    }
}

void ControladoraHospede::listarHospedes() {
    cout << "\n--- LISTAGEM DE HÓSPEDES ---" << endl;
    try {
        vector<Hospede> hospedes = servicoHospede->listarHospedes();

        if (hospedes.empty()) {
            cout << "Nenhum hóspede cadastrado." << endl;
            return;
        }

        cout << "\nLISTA COMPLETA DE HÓSPEDES:" << endl;
        for (const auto& hospede : hospedes) {
            cout << "---------------------------------" << endl;
            cout << "Nome: " << hospede.getNome().getNome() << endl;
            cout << "Email: " << hospede.getEmail().getEmail() << endl;
            cout << "Cartao: " << hospede.getCartao().getValor() << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Total de hóspedes: " << hospedes.size() << endl;

    } catch (const runtime_error& e) {
        cout << "\n ERRO NA LISTAGEM: " << e.what() << endl;
    }
}

// --- Método Público de Execução ---

void ControladoraHospede::executar() {
    int opcao;

    do {
        cout << "\n--- GERENCIAR HÓSPEDES (CRUD) ---" << endl;
        cout << "1 - Cadastrar Novo Hóspede" << endl;
        cout << "2 - Consultar Hóspede (por Email)" << endl;
        cout << "3 - Editar Hóspede" << endl;
        cout << "4 - Excluir Hóspede" << endl;
        cout << "5 - Listar Todos" << endl;
        cout << "0 - Voltar ao Menu Gerente" << endl;
        cout << "Selecione uma opção: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1: cadastrarHospede(); break;
            case 2: consultarHospede(); break;
            case 3: editarHospede(); break;
            case 4: excluirHospede(); break;
            case 5: listarHospedes(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
