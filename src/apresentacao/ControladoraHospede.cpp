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

    cout << "Cartao: ";
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
    cout << "\n--- CADASTRO DE HOSPEDE ---" << endl;
    try {
        Hospede novoHospede = coletarDadosHospede();

        if (servicoHospede->cadastrarHospede(novoHospede)) {
            cout << "\n Hospede '" << novoHospede.getNome().getNome() << "' cadastrado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao cadastrar Hospede. O email pode ja existir." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NO CADASTRO: " << e.what() << endl;
    }
}

void ControladoraHospede::consultarHospede() {
    cout << "\n--- CONSULTA DE HOSPEDE ---" << endl;
    string emailStr;

    cout << "Digite o Email do Hospede para consulta: ";
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
        cout << "\n ERRO DE FORMATO: Email invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO DE CONSULTA: Hospede nao encontrado. " << e.what() << endl;
    }
}

void ControladoraHospede::editarHospede() {
    cout << "\n--- EDICAO DE HOSPEDE ---" << endl;

    try {
        Hospede hospedeAtualizado = coletarDadosHospede();

        if (servicoHospede->editarHospede(hospedeAtualizado)) {
            cout << "\n Hospede com Email '" << hospedeAtualizado.getEmail().getEmail() << "' editado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao editar Hospede. Verifique se o email existe." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EDICAO: " << e.what() << endl;
    }
}

void ControladoraHospede::excluirHospede() {
    cout << "\n--- EXCLUSAO DE HOSPEDE ---" << endl;
    string emailStr;
    cout << "Digite o Email do Hospede a ser excluido: ";
    cin >> emailStr;

    try {
        Email email(emailStr);

        if (servicoHospede->excluirHospede(email)) {
            cout << "\n Hospede com Email '" << email.getEmail() << "' excluido com sucesso." << endl;
        } else {
            cout << "\n Falha ao excluir Hospede. Pode haver Reservas ativas." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Email invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EXCLUSAO: " << e.what() << endl;
    }
}

void ControladoraHospede::listarHospedes() {
    cout << "\n--- LISTAGEM DE HOSPEDES ---" << endl;
    try {
        vector<Hospede> hospedes = servicoHospede->listarHospedes();

        if (hospedes.empty()) {
            cout << "Nenhum hospede cadastrado." << endl;
            return;
        }

        cout << "\nLISTA COMPLETA DE HOSPEDES:" << endl;
        for (const auto& hospede : hospedes) {
            cout << "---------------------------------" << endl;
            cout << "Nome: " << hospede.getNome().getNome() << endl;
            cout << "Email: " << hospede.getEmail().getEmail() << endl;
            cout << "Cartao: " << hospede.getCartao().getValor() << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Total de hospedes: " << hospedes.size() << endl;

    } catch (const runtime_error& e) {
        cout << "\n ERRO NA LISTAGEM: " << e.what() << endl;
    }
}

// --- Método Público de Execução ---

void ControladoraHospede::executar() {
    int opcao;

    do {
        cout << "\n--- GERENCIAR HOSPEDES (CRUD) ---" << endl;
        cout << "1 - Cadastrar Novo Hospede" << endl;
        cout << "2 - Consultar Hospede (por Email)" << endl;
        cout << "3 - Editar Hospede" << endl;
        cout << "4 - Excluir Hospede" << endl;
        cout << "5 - Listar Todos" << endl;
        cout << "0 - Voltar ao Menu Gerente" << endl;
        cout << "Selecione uma opcao: ";

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
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
