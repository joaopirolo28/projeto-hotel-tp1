/**
 * @file PersistenciaQuarto.hpp
 * @brief Definição da classe concreta de persistência para Quarto.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIAQUARTO_HPP
#define PERSISTENCIAQUARTO_HPP

#include "persistencias/IPersistenciaQuarto.hpp"
#include <sqlite3.h>

class PersistenciaQuarto : public IPersistenciaQuarto {
private:
    sqlite3 *db_connection;

public:
    PersistenciaQuarto();
    ~PersistenciaQuarto();

    bool cadastrar(const Codigo& codigoHotel, const Quarto& quarto) override;
    Quarto consultar(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
    bool editar(const Codigo& codigoHotel, const Quarto& quarto) override;
    bool excluir(const Codigo& codigoHotel, const Numero& numeroQuarto) override;
    std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) override;
};

#endif // PERSISTENCIAQUARTO_HPP
