#include "servico/FabricaServicoImpl.hpp"
// Includes das implementações CONCRETAS de Serviço
#include "servico/ServicoAutenticacao.hpp" 
#include "servico/ServicoGerente.hpp" 
#include "servico/ServicoHospede.hpp" 
#include "servico/ServicoHotel.hpp" 
#include "servico/ServicoQuarto.hpp" 
#include "servico/ServicoReservas.hpp" 
// Includes das implementações CONCRETAS de Persistência (DAO)
#include "servico/PersistenciaGerente.hpp" 
#include "servico/PersistenciaHospede.hpp" 
#include "servico/PersistenciaHotel.hpp" 
#include "servico/PersistenciaQuarto.hpp" 
#include "servico/PersistenciaReserva.hpp" 
#include "interfaces/IPersistenciaGerente.hpp" // Para a declaração do unique_ptr
#include "interfaces/IPersistenciaHospede.hpp" // Para a declaração do unique_ptr
// ... inclua as outras interfaces de persistência ...

#include <memory> 
#include <utility> // Para std::move

using namespace std;

// Implementação do método de autenticação
IServicoAutenticacao* FabricaServicoImpl::criarServicoAutenticacao() {
    // 1. Cria a persistência concreta (Gerente)
    unique_ptr<IPersistenciaGerente> persistencia = make_unique<PersistenciaGerente>();
    
    // 2. Cria o serviço, injetando a persistência (transferindo a propriedade)
    return new ServicoAutenticacao(std::move(persistencia));
}

// Implementação do Serviço Gerente
IServicoGerente* FabricaServicoImpl::criarServicoGerente() {
    unique_ptr<IPersistenciaGerente> persistencia = make_unique<PersistenciaGerente>();
    
    // Assumindo que ServicoGerente aceita o IPersistenciaGerente*
    return new ServicoGerente(std::move(persistencia));
}

// Implementação do Serviço Hóspede
IServicoHospede* FabricaServicoImpl::criarServicoHospede() {
    unique_ptr<IPersistenciaHospede> persistencia = make_unique<PersistenciaHospede>();

    // Assumindo que ServicoHospede aceita o IPersistenciaHospede*
    return new ServicoHospede(std::move(persistencia));
}

// Implementação do Serviço Hotel
IServicoHotel* FabricaServicoImpl::criarServicoHotel() {
    unique_ptr<IPersistenciaHotel> persistencia = make_unique<PersistenciaHotel>();

    // Assumindo que ServicoHotel aceita o IPersistenciaHotel*
    return new ServicoHotel(std::move(persistencia));
}

// Implementação do Serviço Quarto
IServicoQuarto* FabricaServicoImpl::criarServicoQuarto() {
    unique_ptr<IPersistenciaQuarto> persistencia = make_unique<PersistenciaQuarto>();

    // Assumindo que ServicoQuarto aceita o IPersistenciaQuarto*
    return new ServicoQuarto(std::move(persistencia));
}

// Implementação do Serviço Reservas
IServicoReservas* FabricaServicoImpl::criarServicoReservas() {
    unique_ptr<IPersistenciaReserva> persistencia = make_unique<PersistenciaReserva>();

    // Assumindo que ServicoReservas aceita o IPersistenciaReserva*
    return new ServicoReservas(std::move(persistencia));
}