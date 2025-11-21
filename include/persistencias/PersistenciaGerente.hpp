/**
 * @file PersistenciaGerente.hpp
 * @brief Definição da classe concreta de persistência para Gerente.
 */
#ifndef PERSISTENCIAGERENTE_HPP
#define PERSISTENCIAGERENTE_HPP

#include "persistencias/IPersistenciaGerente.hpp"
#include <string>
#include <sqlite3.h>

/**
 * @brief Implementação concreta da interface IPersistenciaGerente.
 * @details Responsável por mapear e manipular os dados da entidade Gerente
 * no banco de dados SQLite.
 */
class PersistenciaGerente : public IPersistenciaGerente {
private:
    /**
     * @brief Ponteiro de conexão com o banco de dados SQLite.
     * @details Membro de instância para gerenciamento seguro da conexão.
     */
    sqlite3 *db_connection;
public:
    /**
     * @brief Construtor da classe de persistência.
     * @details Abre a conexão com o banco de dados e garante que a tabela GERENTES exista.
     * @throw std::runtime_error Se a conexão falhar.
     */
    PersistenciaGerente();

    bool cadastrar(const Gerente& gerente) override;
    Gerente consultar(const Email& email) override;
    //bool autenticar(const Email& email, const Senha& senha) override;
    bool editar(const Gerente& gerente) override;
    bool excluir(const Email& email) override;
    std::vector<Gerente> listarTodos() override;
};

#endif // PERSISTENCIAGERENTE_HPP
