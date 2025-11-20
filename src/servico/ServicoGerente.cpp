#include "servico/ServicoGerente.hpp"
#include "entidades/gerente.hpp"
#include "dominios/email.hpp"
#include "dominios/senha.hpp"
#include <iostream>
#include <stdexcept>
#include <utility> 

using namespace std;

ServicoGerente::ServicoGerente(unique_ptr<IPersistenciaGerente> p) : persistencia(std::move(p)) {
}


bool ServicoGerente::cadastrarGerente(Gerente gerente) {
    try {
        return persistencia->cadastrar(gerente);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao cadastrar gerente: " << e.what() << endl;
        return false;
    }
}

Gerente ServicoGerente::consultarGerente(Email email) {
    try {
        return persistencia->consultar(email);
    } catch (const runtime_error& e) {
        cout << "LOG SERVICO: Consulta de gerente falhou. Propagando erro." << endl;
        throw;
    }
}

bool ServicoGerente::editarGerente(Gerente gerente) {
    try {
        return persistencia->editar(gerente);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao editar gerente: " << e.what() << endl;
        return false;
    }
}

bool ServicoGerente::excluirGerente(Email email) {
    
    try {
        return persistencia->excluir(email);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao excluir gerente: " << e.what() << endl;
        return false;
    }
}