/**
 * @file IPersistenciaGerente.hpp
 * @brief Definição da interface de persistência para a entidade Gerente.
 * @details Define o contrato para operações de CRUD com o banco de dados.
 */
#ifndef IPERSISTENCIAGERENTE_HPP
#define IPERSISTENCIAGERENTE_HPP

#include "dominios/email.hpp"
#include "dominios/senha.hpp" // Adicionado: Necessário para o método autenticar
#include "entidades/gerente.hpp"
#include <stdexcept>

using namespace std;

/**
 * @brief Interface para persistência de dados do Gerente.
 * @details Responsável por salvar, consultar e autenticar Gerentes no repositório de dados.
 */
class IPersistenciaGerente {
    public:
        /**
         * @brief Destrutor virtual.
         */
        virtual ~IPersistenciaGerente() {}

        /**
         * @brief Armazena um novo Gerente no banco de dados.
         * @param gerente O objeto Gerente a ser persistido.
         * @return True se o cadastro for bem-sucedido, False caso contrário.
         */
        virtual bool cadastrar(const Gerente& gerente) = 0;

        /**
         * @brief Consulta um Gerente pelo seu email.
         * @param email O email do Gerente (chave primária).
         * @return O objeto Gerente se encontrado. Lança exceção se não encontrado.
         * @throw runtime_error Se o Gerente não for encontrado.
         */
        virtual Gerente consultar(const Email& email) = 0;

        /**
         * @brief Verifica se um Gerente existe e a senha corresponde.
         * @param email O email para autenticação.
         * @param senha A senha para autenticação (Domínio Senha).
         * @return True se as credenciais estiverem corretas, False caso contrário.
         */
        virtual bool autenticar(const Email& email, const Senha& senha) = 0;

        /**
         * @brief Edita um Gerente existente no banco de dados.
         * @param gerente O objeto Gerente com os dados atualizados.
         * @return True se a edição for bem-sucedida, False caso contrário.
         */
        virtual bool editar(const Gerente& gerente) = 0;

        /**
         * @brief Exclui um Gerente pelo seu email.
         * @param email O email do Gerente a ser excluído.
         * @return True se a exclusão for bem-sucedida, False caso contrário.
         */
        virtual bool excluir(const Email& email) = 0;
};

#endif // IPERSISTENCIAGERENTE_HPP