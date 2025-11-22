#include "servico/ServicoAutenticacao.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

ServicoAutenticacao::ServicoAutenticacao(unique_ptr<IPersistenciaGerente> p) {
    persistencia = move(p);
}

bool ServicoAutenticacao::autenticar(Email email, Senha senha) {
    try {
        Gerente gerente = persistencia->consultar(email);

        if (gerente.getSenha().getSenha() == senha.getSenha()) {
            return true;
        } else {
            return false;
        }

    } catch (const runtime_error& e) {
        return false;
    }
}
