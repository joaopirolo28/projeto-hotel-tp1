/**
 * @file PersistenciaHotel.hpp
 * @brief Definição da classe concreta de persistência para Hotel.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIAHOTEL_HPP
#define PERSISTENCIAHOTEL_HPP

#include "persistencias/IPersistenciaHotel.hpp"
#include <sqlite3.h>

/**
 * @brief Implementação concreta da interface IPersistenciaHotel.
 * @details Responsável por mapear e manipular os dados da entidade Hotel
 * no banco de dados SQLite.
 */
class PersistenciaHotel : public IPersistenciaHotel {
private:
    sqlite3 *db_connection;

public:
    /**
     * @brief Construtor da classe de persistência.
     */
    PersistenciaHotel();

    /**
     * @brief Destrutor da classe de persistência.
     */
    ~PersistenciaHotel();

    bool cadastrar(const Hotel& hotel) override;
    Hotel consultar(const Codigo& codigo) override;
    bool editar(const Hotel& hotel) override;
    bool excluir(const Codigo& codigo) override;
    std::vector<Hotel> listarTodos() override;
};

#endif // PERSISTENCIAHOTEL_HPP
