#include "servico/FabricaServicoImpl.hpp"
#include "servico/ServicoAutenticacao.hpp" // Necessário para a definição concreta
#include "servico/PersistenciaGerente.hpp" // Necessário para a definição concreta
#include <memory> 
#include <utility> // Para std::move
#include "servico/FabricaServicoImpl.hpp"

using namespace std;

IServicoAutenticacao* FabricaServicoImpl::criarServicoAutenticacao() {
    unique_ptr<IPersistenciaGerente> p = make_unique<PersistenciaGerente>();

    return new ServicoAutenticacao(std::move(p));
}


