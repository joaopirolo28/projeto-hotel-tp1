#include "servico/FabricaServicoImpl.hpp"

#include "servico/ServicoAutenticacao.hpp"
#include "servico/ServicoGerente.hpp"
#include "servico/ServicoHospede.hpp"
#include "servico/ServicoHotel.hpp"
#include "servico/ServicoQuarto.hpp"
#include "servico/ServicoReservas.hpp"

#include "servico/PersistenciaGerente.hpp"
#include "servico/PersistenciaHospede.hpp"
#include "servico/PersistenciaHotel.hpp"
#include "servico/PersistenciaQuarto.hpp"
#include "servico/PersistenciaReserva.hpp"

#include "interfaces/IPersistenciaGerente.hpp"
#include "interfaces/IPersistenciaHospede.hpp"
#include "interfaces/IPersistenciaHotel.hpp"
#include "interfaces/IPersistenciaQuarto.hpp"
#include "interfaces/IPersistenciaReserva.hpp"

#include <memory>
#include <utility>

using namespace std;

IServicoAutenticacao* FabricaServicoImpl::criarServicoAutenticacao() {
    unique_ptr<IPersistenciaGerente> persistencia = make_unique<PersistenciaGerente>();
    return new ServicoAutenticacao(std::move(persistencia));
}


IServicoGerente* FabricaServicoImpl::criarServicoGerente() {
    unique_ptr<IPersistenciaGerente> persistencia = make_unique<PersistenciaGerente>();
    return new ServicoGerente(std::move(persistencia));
}


IServicoHospede* FabricaServicoImpl::criarServicoHospede() {

    unique_ptr<IPersistenciaHospede> persistenciaHospede = make_unique<PersistenciaHospede>();

    unique_ptr<IPersistenciaReserva> persistenciaReserva = make_unique<PersistenciaReserva>();

    //IServicoReservas* servicoReservas = new ServicoReservas(std::move(persistenciaReserva));

    return new ServicoHospede(std::move(persistenciaHospede), servicoReservas);
}

IServicoHotel* FabricaServicoImpl::criarServicoHotel() {
    unique_ptr<IPersistenciaHotel> persistencia = make_unique<PersistenciaHotel>();
    return new ServicoHotel(std::move(persistencia));
}

IServicoQuarto* FabricaServicoImpl::criarServicoQuarto() {
    unique_ptr<IPersistenciaQuarto> persistencia = make_unique<PersistenciaQuarto>();
    return new ServicoQuarto(std::move(persistencia));
}

IServicoReservas* FabricaServicoImpl::criarServicoReservas() {
    unique_ptr<IPersistenciaReserva> persistencia = make_unique<PersistenciaReserva>();
    return new ServicoReservas(std::move(persistencia));
}
