#include "servico/ServicoAutenticacao.hpp"
#include <iostream>

using namespace std;

ServicoAutenticacao::ServicoAutenticacao(unique_ptr<IPersistenciaGerente> p) {
    persistencia = move(p);
}

bool ServicoAutenticacao::cadastrarGerente(Gerente gerente){
    try{
        persistencia->consultar(gerente.getEmail());

        throw runtime_error("Gerente com este email já cadastrado.");
    } catch (const runtime_error& exp){

        if(string(exp.what()).find("Gerente com este email já cadastrado.") != string::npos){
            throw;
        }
        return persistencia->cadastrar(gerente);
    }

}

bool ServicoAutenticacao::autenticar(Email email, Senha senha) {
    return persistencia->autenticar(email, senha);
}

Gerente ServicoAutenticacao::consultarGerente(Email email) {
    return persistencia->consultar(email);
}

bool ServicoAutenticacao::editarGerente(Gerente gerente) {
    return persistencia->editar(gerente);
}

bool ServicoAutenticacao::excluirGerente(Email email) {
    return persistencia->excluir(email);
}
