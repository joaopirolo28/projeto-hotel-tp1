/**
 * @file IPersistenciaHospede.hpp
 * @brief Definição da interface de persistencia (DAO) para a entidade Hospede.
 * @author Tarsila Marques
 * @date 21 de novembro de 2025
 */

#ifndef IPERSISTENCIAHOSPEDE_HPP
#define IPERSISTENCIAHOSPEDE_HPP

#include "dominios/email.hpp"
#include "entidades/hospede.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

/**
 * @brief Interface para a Camada de Acesso a Dados (DAO) do Hospede.
 * @details Define o contrato CRUD (Criar, Ler, Atualizar, Deletar) para a entidade Hospede,
 * sendo a base para implementacoes em memoria ou SQL.
 */
class IPersistenciaHospede {
public:
    virtual ~IPersistenciaHospede() {}

    /**
     * @brief Armazena um novo Hospede no repositorio de dados.
     * @param hospede O objeto Hospede a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrario.
     */
    virtual bool cadastrar(const Hospede& hospede) = 0;

    /**
     * @brief Consulta um Hospede pelo seu email.
     * @param email O email do Hospede (chave primaria).
     * @return O objeto Hospede se encontrado.
     * @throw runtime_error Se o Hospede nao for encontrado.
     */
    virtual Hospede consultar(const Email& email) = 0;

    /**
     * @brief Edita um Hospede existente no repositorio de dados.
     * @param hospede O objeto Hospede com os dados atualizados.
     * @return true se a edicao for bem-sucedida, false caso contrario.
     */
    virtual bool editar(const Hospede& hospede) = 0;

    /**
     * @brief Exclui um Hospede pelo seu email.
     * @param email O email do Hospede a ser excluido.
     * @return true se a exclusao for bem-sucedida, false caso contrario.
     */
    virtual bool excluir(const Email& email) = 0;
    
    /**
     * @brief Retorna uma lista de todos os Hospedes no repositorio.
     * @return Um vetor de objetos Hospede.
     */
    virtual vector<Hospede> listarTodos() = 0;
};

#endif // IPERSISTENCIAHOSPEDE_HPP