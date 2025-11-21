/**
 * @file PersistenciaReserva.hpp
 * @brief Definição da classe concreta de persistência para Reserva.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIARESERVA_HPP
#define PERSISTENCIARESERVA_HPP

#include "persistencias/IPersistenciaReserva.hpp"
#include <sqlite3.h>

/**
 * @brief Implementação concreta da interface IPersistenciaReserva.
 * @details Responsável por mapear e manipular os dados da entidade Reserva
 * no banco de dados SQLite.
 */
class PersistenciaReserva : public IPersistenciaReserva {
private:
    sqlite3 *db_connection;

public:
    PersistenciaReserva();
    ~PersistenciaReserva();

    bool cadastrar(const Reserva& reserva) override;
    Reserva consultar(const Codigo& codigo) override;
    bool editar(const Reserva& reserva) override;
    bool excluir(const Codigo& codigo) override;
    std::vector<Reserva> listarPorHospede(const Email& emailHospede) override;
    std::vector<Reserva> listarReservasPorQuarto(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
};

#endif // PERSISTENCIARESERVA_HPP
