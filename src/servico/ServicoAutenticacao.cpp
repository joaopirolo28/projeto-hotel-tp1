#include "servico/ServicoAutenticacao.hpp"
#include <iostream>

using namespace std;

ServicoAutenticacao::ServicoAutenticacao(unique_ptr<IPersistenciaGerente> p) {
    persistencia = move(p);
}
