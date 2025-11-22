#include "servico/ServicoHotel.hpp"
#include "entidades/hotel.hpp"
#include "dominios/codigo.hpp"
#include "dominios/nome.hpp"
#include "persistencias/IPersistenciaHotel.hpp"
#include "persistencias/IPersistenciaQuarto.hpp"
#include "persistencias/IPersistenciaReserva.hpp"
#include "interfaces/interfaces.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

ServicoHotel::ServicoHotel(unique_ptr<IPersistenciaHotel> pHotel,
                           IServicoQuarto* sQuarto,
                           IServicoReserva* sReserva)
    : persistenciaHotel(std::move(pHotel)),
      servicoQuarto(sQuarto),
      servicoReserva(sReserva)
{
}


bool ServicoHotel::cadastrarHotel(Hotel hotel) {
    try {
        return persistenciaHotel->cadastrar(hotel);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao cadastrar hotel: " << e.what() << endl;
        return false;
    }
}

Hotel ServicoHotel::consultarHotel(Codigo codigo) {
    try {
        return persistenciaHotel->consultar(codigo);
    } catch (const runtime_error& e) {
        cout << "LOG SERVICO: Consulta de hotel falhou. Propagando erro." << endl;
        throw;
    }
}

bool ServicoHotel::editarHotel(Hotel hotel) {
    try {
        return persistenciaHotel->editar(hotel);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao editar hotel: " << e.what() << endl;
        return false;
    }
}

bool ServicoHotel::excluirHotel(Codigo codigo) {

    try {
        vector<Quarto> quartosAtivos = servicoQuarto->listarQuartos(codigo);

        if (!quartosAtivos.empty()) {
            cout << "LOG SERVICO: Falha. Hotel nao pode ser excluido, ha quartos ativos (Consistencia - Quartos)." << endl;
            return false;
        }
        return persistenciaHotel->excluir(codigo);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao excluir hotel: " << e.what() << endl;
        return false;
    }
}

vector<Hotel> ServicoHotel::listarHoteis() {
    try {
        return persistenciaHotel->listarTodos();
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao listar hoteis: " << e.what() << endl;
        return vector<Hotel>();
    }
}
