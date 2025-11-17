#include "servico/FabricaServicoImpl.hpp"

using namespace std;

ILNAutenticacao* FabricaServicoImpl::criarServicoAutenticacao() {
    unique_ptr<IPersistenciaGerente> p = make_unique<PersistenciaGerente>();

    return new ServicoAutenticacao(std::move(p));
}
