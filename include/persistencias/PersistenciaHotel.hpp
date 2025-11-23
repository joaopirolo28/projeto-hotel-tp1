/**
 * @file PersistenciaHotel.hpp
 * @brief Definição da classe concreta de persistência para Hotel.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIAHOTEL_HPP
#define PERSISTENCIAHOTEL_HPP

#include "interfaces/IPersistenciaHotel.hpp"
#include "entidades/hotel.hpp"
#include "dominios/codigo.hpp"
#include <sqlite3.h>
#include <vector>

/**
 * @brief Implementação concreta da interface IPersistenciaHotel (DAO).
 * @details Responsável por mapear e manipular os dados da entidade Hotel
 * no banco de dados SQLite.
 */
class PersistenciaHotel : public IPersistenciaHotel {
private:
    /**
     * @brief Ponteiro para o manipulador da conexão SQLite.
     * @details Usado para realizar todas as operações SQL no banco de dados.
     */
    sqlite3 *db_connection;

public:
    /**
     * @brief Construtor da classe de persistência.
     * @details Abre a conexão com o banco de dados e garante que a tabela HOTEIS exista.
     */
    PersistenciaHotel();

    /**
     * @brief Destrutor da classe de persistência.
     * @details Fecha a conexão ativa com o banco de dados SQLite.
     */
    ~PersistenciaHotel();

    /**
     * @brief Armazena um novo Hotel no banco de dados.
     * @param hotel O objeto Hotel a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrário (ex: código duplicado).
     */
    bool cadastrar(const Hotel& hotel) override;

    /**
     * @brief Consulta um Hotel pelo seu código.
     * @param codigo O código do Hotel (chave primária).
     * @return O objeto Hotel se encontrado.
     * @throw runtime_error Se o Hotel não for encontrado.
     */
    Hotel consultar(const Codigo& codigo) override;

    /**
     * @brief Edita um Hotel existente no banco de dados.
     * @param hotel O objeto Hotel com os dados atualizados.
     * @return true se a edição for bem-sucedida, false caso contrário.
     */
    bool editar(const Hotel& hotel) override;

    /**
     * @brief Exclui um Hotel pelo seu código.
     * @param codigo O código do Hotel a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir(const Codigo& codigo) override;

    /**
     * @brief Retorna uma lista de todos os Hotéis no repositório.
     * @return Um vetor (vector) de objetos Hotel.
     */
    std::vector<Hotel> listarTodos() override;
};

#endif // PERSISTENCIAHOTEL_HPP