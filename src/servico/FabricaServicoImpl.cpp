#include "servico/FabricaServicoImpl.hpp"

#include "servico/ServicoAutenticacao.hpp"
#include "servico/ServicoGerente.hpp"
#include "servico/ServicoHospede.hpp"
#include "servico/ServicoHotel.hpp"
#include "servico/ServicoQuarto.hpp"
#include "servico/ServicoReservas.hpp"

#include "persistencias/PersistenciaGerente.hpp"
#include "persistencias/PersistenciaHospede.hpp"
#include "persistencias/PersistenciaHotel.hpp"
#include "persistencias/PersistenciaQuarto.hpp"
#include "persistencias/PersistenciaReserva.hpp"

#include "persistencias/IPersistenciaGerente.hpp"
#include "persistencias/IPersistenciaHospede.hpp"
#include "persistencias/IPersistenciaHotel.hpp"
#include "persistencias/IPersistenciaQuarto.hpp"
#include "persistencias/IPersistenciaReserva.hpp"

#include <memory>
#include <utility>
#include <stdexcept>

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

    //IPersistenciaReserva* pReservaRaw = new PersistenciaReserva();
    IServicoReservas* servicoReservasRaw = criarServicoReservas();

    return new ServicoHospede(std::move(persistenciaHospede), servicoReservasRaw);
    //return new ServicoHospede(std::move(persistenciaHospede), static_cast<IServicoReservas*>(pReservaRaw));
}

IServicoHotel* FabricaServicoImpl::criarServicoHotel() {
    unique_ptr<IPersistenciaHotel> persistenciaHotel = make_unique<PersistenciaHotel>();

    IServicoQuarto* servicoQuarto = criarServicoQuarto();

    IServicoReservas* servicoReserva = criarServicoReservas();

    return new ServicoHotel(std::move(persistenciaHotel), servicoQuarto, servicoReserva);
}

IServicoQuarto* FabricaServicoImpl::criarServicoQuarto() {
    unique_ptr<IPersistenciaQuarto> persistenciaQuarto = make_unique<PersistenciaQuarto>();

    IPersistenciaHotel* pHotelRaw = new PersistenciaHotel();
    IPersistenciaReserva* pReservaRaw = new PersistenciaReserva();

    return new ServicoQuarto(std::move(persistenciaQuarto), pHotelRaw, pReservaRaw);
}

IServicoReservas* FabricaServicoImpl::criarServicoReservas() {
    unique_ptr<IPersistenciaReserva> persistencia = make_unique<PersistenciaReserva>();
    return new ServicoReservas(std::move(persistencia));
}
