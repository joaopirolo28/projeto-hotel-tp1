#include "apresentacao/ControladoraHotel.hpp"
#include "interfaces/interfaces.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Funcao Auxiliar: Usada para ler uma linha de texto do console.
// Necessaria para evitar conflitos de buffer do cin.
string solicitarNovoValor(const string& prompt) {
    string valor;
    cout << prompt;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, valor);
    return valor;
}

ControladoraHotel::ControladoraHotel(IServicoHotel* sHotel)
    : servicoHotel(sHotel) {
}


Hotel ControladoraHotel::coletarDadosHotel() {
    string nomeStr, enderecoStr, telefoneStr, codigoStr;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Nome do Hotel: ";
    getline(cin, nomeStr);

    cout << "Endereco: ";
    getline(cin, enderecoStr);

    cout << "Telefone (+DD DDDDDDDDD - SEM ESPACOS): ";
    cin >> telefoneStr;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Codigo (10 caracteres, letras/digitos): ";
    cin >> codigoStr;

    Nome nome(nomeStr);
    Endereco endereco(enderecoStr);
    Telefone telefone(telefoneStr);
    Codigo codigo(codigoStr);

    Hotel novoHotel;
    novoHotel.setNome(nome);
    novoHotel.setEndereco(endereco);
    novoHotel.setTelefone(telefone);
    novoHotel.setCodigo(codigo);

    return novoHotel;
}

void ControladoraHotel::cadastrarHotel() {
    cout << "\n--- CADASTRO DE HOTEL ---" << endl;
    try {
        Hotel novoHotel = coletarDadosHotel();

        if (servicoHotel->cadastrarHotel(novoHotel)) {
            cout << "\n Hotel '" << novoHotel.getNome().getNome() << "' cadastrado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao cadastrar Hotel. O código pode já existir." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NO CADASTRO: " << e.what() << endl;
    }
}

void ControladoraHotel::consultarHotel() {
    cout << "\n--- CONSULTA DE HOTEL ---" << endl;
    string codigoStr;
    cout << "Digite o Codigo do Hotel para consulta: ";
    cin >> codigoStr;

    try {
        Codigo codigo(codigoStr);

        Hotel hotel = servicoHotel->consultarHotel(codigo);

        cout << "\n HOTEL ENCONTRADO:" << endl;
        cout << "    Nome: " << hotel.getNome().getNome() << endl;
        cout << "    Codigo: " << hotel.getCodigo().getValor() << endl;
        cout << "    Endereco: " << hotel.getEndereco().getEndereco() << endl;
        cout << "    Telefone: " << hotel.getTelefone().getValor() << endl;

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Codigo invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO DE CONSULTA: Hotel nao encontrado. " << e.what() << endl;
    }
}

// --- MÉTODO EDITAR HOTEL (CORRIGIDO COM MENU) ---
void ControladoraHotel::editarHotel() {
    cout << "\n--- EDICAO DE HOTEL ---" << endl;
    string codigoStr;
    cout << "Digite o Codigo do Hotel para edicao: ";
    cin >> codigoStr;

    try {
        Codigo codigo(codigoStr);
        // 1. Consulta o hotel existente para obter os dados atuais
        Hotel hotelAtualizado = servicoHotel->consultarHotel(codigo);

        cout << "Hotel '" << hotelAtualizado.getNome().getNome() << "' encontrado." << endl;

        int opcao;
        cout << "\n Selecione o campo para alterar:" << endl;
        cout << "1 - Nome: (" << hotelAtualizado.getNome().getNome() << ")" << endl;
        cout << "2 - Endereco: (" << hotelAtualizado.getEndereco().getEndereco() << ")" << endl;
        cout << "3 - Telefone: (" << hotelAtualizado.getTelefone().getValor() << ")" << endl;
        cout << "0 - Cancelar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 0) return;

        // 2. Coleta e valida o novo valor
        string novoValorStr;
        switch (opcao) {
            case 1: {
                novoValorStr = solicitarNovoValor("Digite o NOVO Nome: ");
                Nome novoNome(novoValorStr); // Valida o domínio
                hotelAtualizado.setNome(novoNome); // Aplica a mudanca
                break;
            }
            case 2: {
                novoValorStr = solicitarNovoValor("Digite o NOVO Endereco: ");
                Endereco novoEndereco(novoValorStr); // Valida o domínio
                hotelAtualizado.setEndereco(novoEndereco); // Aplica a mudanca
                break;
            }
            case 3: {
                novoValorStr = solicitarNovoValor("Digite o NOVO Telefone (+DD...): ");
                Telefone novoTelefone(novoValorStr); // Valida o domínio
                hotelAtualizado.setTelefone(novoTelefone); // Aplica a mudanca
                break;
            }
            default: {
                cout << "Opcao invalida." << endl;
                return;
            }
        }

        // 3. Chama o serviço com a entidade atualizada
        if (servicoHotel->editarHotel(hotelAtualizado)) {
            cout << "\n Hotel '" << hotelAtualizado.getNome().getNome() << "' editado com sucesso!" << endl;
        } else {
            cout << "\n Falha ao editar Hotel. O serviço não conseguiu atualizar." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Valor invalido para o novo campo. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EDICAO: Hotel nao encontrado ou erro de sistema. " << e.what() << endl;
    }
}

void ControladoraHotel::excluirHotel() {
    cout << "\n--- EXCLUSAO DE HOTEL ---" << endl;
    string codigoStr;
    cout << "Digite o Codigo do Hotel a ser excluido: ";
    cin >> codigoStr;

    try {
        Codigo codigo(codigoStr);

        if (servicoHotel->excluirHotel(codigo)) {
            cout << "\n Hotel com Codigo '" << codigo.getValor() << "' excluido com sucesso." << endl;
        } else {
            cout << "\n Falha ao excluir Hotel. Pode haver Quartos ou Reservas ativas (Violacao de Multiplicidade)." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Codigo invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EXCLUSAO: " << e.what() << endl;
    }
}

void ControladoraHotel::listarHoteis() {
    cout << "\n--- LISTAGEM DE HOTEIS ---" << endl;
    try {
        vector<Hotel> hoteis = servicoHotel->listarHoteis();

        if (hoteis.empty()) {
            cout << "Nenhum hotel cadastrado." << endl;
            return;
        }

        for (const auto& hotel : hoteis) {
            cout << "---------------------------------" << endl;
            cout << "Codigo: " << hotel.getCodigo().getValor() << endl;
            cout << "Nome: " << hotel.getNome().getNome() << endl;
            cout << "Endereco: " << hotel.getEndereco().getEndereco() << endl;
            cout << "Telefone: " << hotel.getTelefone().getValor() << endl;
        }
        cout << "---------------------------------" << endl;
        cout << "Total de hoteis: " << hoteis.size() << endl;

    } catch (const runtime_error& e) {
        cout << "\n ERRO NA LISTAGEM: " << e.what() << endl;
    }
}


void ControladoraHotel::executar() {
    int opcao;

    do {
        cout << "\n--- GERENCIAR HOTEIS (CRUD) ---" << endl;
        cout << "1 - Cadastrar Novo Hotel" << endl;
        cout << "2 - Consultar Hotel (por Codigo)" << endl;
        cout << "3 - Editar Hotel" << endl;
        cout << "4 - Excluir Hotel" << endl;
        cout << "5 - Listar Todos" << endl;
        cout << "0 - Voltar ao Menu Gerente" << endl;
        cout << "Selecione uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1: cadastrarHotel(); break;
            case 2: consultarHotel(); break;
            case 3: editarHotel(); break;
            case 4: excluirHotel(); break;
            case 5: listarHoteis(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
