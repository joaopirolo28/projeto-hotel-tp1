#include "apresentacao/ControladoraSistema.hpp"
#include "apresentacao/ControladoraAutenticacao.hpp"
#include "apresentacao/ControladoraHotel.hpp"
#include "apresentacao/ControladoraQuarto.hpp"
#include "apresentacao/ControladoraGerente.hpp"
#include "apresentacao/ControladoraHospede.hpp"
#include "apresentacao/ControladoraReserva.hpp"

#include "interfaces/interfaces.hpp"
#include "dominios/dominios.hpp"

#include "servico/FabricaServico.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

ControladoraSistema::ControladoraSistema(FabricaServico* f)
    : fabrica(f),
      controladoraAutenticacao(nullptr),
      controladoraGerente(nullptr)
{
    carregarControladoras();
}

void ControladoraSistema::carregarControladoras(){

    IServicoAutenticacao* servicoRawAuth = fabrica->criarServicoAutenticacao();
    IServicoGerente* servicoRawGerente = fabrica->criarServicoGerente();


    unique_ptr<IServicoAutenticacao> temp_unique_auth(servicoRawAuth);
    unique_ptr<IServicoGerente> temp_unique_gerente(servicoRawGerente);

    controladoraAutenticacao = new ControladoraAutenticacao(move(temp_unique_auth), move(temp_unique_gerente));



    IServicoHotel* sHotelRaw = fabrica->criarServicoHotel();
    IServicoQuarto* sQuartoRaw = fabrica->criarServicoQuarto();
    IServicoHospede* sHospedeRaw = fabrica->criarServicoHospede();

    unique_ptr<IServicoHotel> sHotelUnique(sHotelRaw);
    unique_ptr<IServicoQuarto> sQuartoUnique(sQuartoRaw);
    unique_ptr<IServicoHospede> sHospedeUnique(sHospedeRaw);

    ControladoraHotel* cHotelRaw = new ControladoraHotel(sHotelRaw);
    ControladoraQuarto* cQuartoRaw = new ControladoraQuarto(sQuartoRaw);
    ControladoraHospede* cHospedeRaw = new ControladoraHospede(sHospedeRaw);

    controladoraGerente = new ControladoraGerente(
        move(sHotelUnique),
        move(sQuartoUnique),
        move(sHospedeUnique),
        cHotelRaw,
        cQuartoRaw,
        cHospedeRaw
    );

}

void ControladoraSistema::executar() {

    cout << "\n--- SISTEMA DE GESTAO DE HOTEIS ---\n";

    emailGerenteLogado = controladoraAutenticacao->executar();

    if (!emailGerenteLogado.empty()) {
        apresentarMenuPrincipal();
    }else{
        std::cout << "Nenhum gerente logado. Encerrando o sistema." << std::endl;
    }
}

void ControladoraSistema::apresentarMenuPrincipal() {
    cout << "\nBem-vindo(a), Gerente " << emailGerenteLogado << "!\n";

    controladoraGerente->executar();
}
