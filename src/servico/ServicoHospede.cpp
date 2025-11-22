#include "servico/ServicoHospede.hpp"
#include "entidades/hospede.hpp"
#include "dominios/email.hpp"
#include "dominios/nome.hpp"
#include "interfaces/interfaces.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

ServicoHospede::ServicoHospede(unique_ptr<IPersistenciaHospede> p, IServicoReserva* s)
    : persistencia(std::move(p)), servicoReserva(s) {}


bool ServicoHospede::cadastrarHospede(Hospede hospede) {
    try {
        return persistencia->cadastrar(hospede);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao cadastrar hospede: " << e.what() << endl;
        return false;
    }
}

Hospede ServicoHospede::consultarHospede(Email email) {
    try {
        return persistencia->consultar(email);
    } catch (const runtime_error& e) {
        cout << "LOG SERVICO: Consulta de hospede falhou. Propagando erro." << endl;
        throw;
    }
}

bool ServicoHospede::editarHospede(Hospede hospede) {
    try {
        return persistencia->editar(hospede);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao editar hospede: " << e.what() << endl;
        return false;
    }
}

bool ServicoHospede::excluirHospede(Email email) {


    try {
        vector<Reserva> reservasAtivas = servicoReserva->listarReservas(email);

        if (!reservasAtivas.empty()) {
            cout << "LOG SERVICO: Falha. Hospede nao pode ser excluido, tem reservas ativas." << endl;
            return false;
        }
    } catch (const runtime_error& e) {
        cout << "LOG SERVICO: Erro ao checar reservas do hospede. Prosseguindo." << endl;
    }


    try {
        return persistencia->excluir(email);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao excluir hospede: " << e.what() << endl;
        return false;
    }
}

vector<Hospede> ServicoHospede::listarHospedes() {
    try {
        return persistencia->listarTodos();
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao listar hospedes: " << e.what() << endl;
        return vector<Hospede>();
    }
}
