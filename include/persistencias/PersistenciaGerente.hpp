/**
 * @file PersistenciaGerente.hpp
 * @brief Declaracao da classe concreta de persistencia (DAO) para Gerente.
 */

#ifndef PERSISTENCIAGERENTE_HPP
#define PERSISTENCIAGERENTE_HPP
#include "interfaces/interfaces.hpp"
#include "persistencias/IPersistenciaGerente.hpp"
#include "entidades/gerente.hpp"
#include "dominios/email.hpp"
#include "dominios/senha.hpp"
#include "sqlite3.h"
#include <vector>
#include <stdexcept>

using namespace std;

 /**
 * @brief Implementacao concreta da interface IPersistenciaGerente (DAO).
 * @details Responsavel por gerenciar as operacoes CRUD e autenticacao da entidade Gerente
 * utilizando o banco de dados SQLite.
 */

class PersistenciaGerente : public IPersistenciaGerente {
private:
    /**
     * @brief Ponteiro para o manipulador da conexao SQLite.
     * Esta e a dependencia interna que gerencia a conexao (abrir e fechar).
     */
    sqlite3 *db_connection;

public:
    /**
     * @brief Construtor da classe de persistencia.
     * @details Abre a conexao com o banco de dados SQLite e garante que a tabela GERENTES exista.
     */
    PersistenciaGerente();

    /**
     * @brief Destrutor da classe de persistencia.
     * @details Fecha a conexao ativa com o banco de dados SQLite.
     */
    ~PersistenciaGerente();

    // --- Metodos do Contrato IPersistenciaGerente ---

    /**
     * @brief Armazena um novo Gerente no repositorio de dados.
     * @param gerente O objeto Gerente a ser persistido.
     * @return true se o cadastro for bem-sucedido.
     */
    bool cadastrar(const Gerente& gerente) override;

    /**
     * @brief Consulta um Gerente pelo seu email.
     * @param email O email do Gerente (chave primaria).
     * @return O objeto Gerente se encontrado.
     * @throw runtime_error Se o Gerente nao for encontrado.
     */
    Gerente consultar(const Email& email) override;

    /**
     * @brief Verifica se um Gerente existe e a senha corresponde.
     * @param email O email para autenticacao.
     * @param senha A senha para autenticacao (Dominio Senha).
     * @return true se as credenciais estiverem corretas.
     */
    bool autenticar(const Email& email, const Senha& senha) override;

    /**
     * @brief Edita um Gerente existente no repositorio de dados.
     * @param gerente O objeto Gerente com os dados atualizados.
     * @return true se a edicao for bem-sucedida.
     */
    bool editar(const Gerente& gerente) override;

    /**
     * @brief Exclui um Gerente pelo seu email.
     * @param email O email do Gerente a ser excluido.
     * @return true se a exclusao for bem-sucedida.
     */
    bool excluir(const Email& email) override;

    /**
     * @brief Retorna uma lista de todos os Gerentes no repositorio.
     * @return Um vetor de objetos Gerente.
     */
    std::vector<Gerente> listarTodos() override;
};

#endif // PERSISTENCIAGERENTE_HPP
