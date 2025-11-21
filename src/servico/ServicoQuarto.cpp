#include "servico/ServicoQuarto.hpp"
#include "entidades/quarto.hpp"
#include "entidades/hotel.hpp" 
#include "dominios/codigo.hpp"
#include "dominios/numero.hpp"
#include "servico/IPersistenciaQuarto.hpp" 
#include "servico/IPersistenciaHotel.hpp" 
#include "servico/IPersistenciaReserva.hpp" 

#include <iostream>
#include <stdexcept>
#include <utility> 
#include <vector>

using namespace std;


ServicoQuarto::ServicoQuarto(unique_ptr<IPersistenciaQuarto> pQuarto, 
                             IPersistenciaHotel* pHotel, 
                             IPersistenciaReserva* pReserva) 
    : persistenciaQuarto(std::move(pQuarto)), 
      persistenciaHotel(pHotel), 
      persistenciaReserva(pReserva) 
{
    
}


bool ServicoQuarto::cadastrarQuarto(Codigo codigoHotel, Quarto quarto) {
    try {
        
        persistenciaHotel->consultar(codigoHotel);

       
        return persistenciaQuarto->cadastrar(codigoHotel, quarto); 
        
    } catch (const runtime_error& e) {
        
        cout << "LOG SERVICO: Falha ao cadastrar quarto. Hotel pai nao encontrado: " << e.what() << endl;
        return false;
    } catch (const exception& e) {
        
        cout << "LOG SERVICO: Erro ao cadastrar quarto: " << e.what() << endl;
        return false; 
    }
}

Quarto ServicoQuarto::consultarQuarto(Numero numero) {
    try {
        
        return persistenciaQuarto->consultar(numero);
    } catch (const runtime_error& e) {
        
        cout << "LOG SERVICO: Consulta de quarto falhou. Propagando erro." << endl;
        throw;
    }
}

bool ServicoQuarto::editarQuarto(Quarto quarto) {
    try {
        
        return persistenciaQuarto->editar(quarto);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao editar quarto: " << e.what() << endl;
        return false;
    }
}

bool ServicoQuarto::excluirQuarto(Numero numero) {
   
    try {
        
        vector<Reserva> reservasAtivas = persistenciaReserva->listarReservasPorQuarto(numero);

        if (!reservasAtivas.empty()) {
            cout << "LOG SERVICO: Falha. Quarto nao pode ser excluido, ha reservas ativas (Consistencia)." << endl;
            return false; 
        }

        return persistenciaQuarto->excluir(numero);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao excluir quarto: " << e.what() << endl;
        return false;
    }
}

vector<Quarto> ServicoQuarto::listarQuartos(Codigo codigoHotel) {
    try {
        return persistenciaQuarto->listarQuartos(codigoHotel);
    } catch (const exception& e) {
        cout << "LOG SERVICO: Erro ao listar quartos: " << e.what() << endl;
        return vector<Quarto>();
    }
}