/**
 * @file PersistenciaHospede.hpp
 * @brief Definição da classe concreta de persistência para Hospede.
 * @author Tarsila Marques
 * @date 21 de novembro de 2025
 */
#ifndef PERSISTENCIAHOSPEDE_HPP
#define PERSISTENCIAHOSPEDE_HPP

#include "persistencias/IPersistenciaHospede.hpp"
#include <string>

/**
 * @brief Implementação concreta da interface IPersistenciaHospede.
 * @details Responsável por mapear e manipular os dados da entidade Hospede
 * no banco de dados SQLite.
 */
class PersistenciaHospede : public IPersistenciaHospede {
public:
    /**
     * @brief Construtor que inicializa a conexão com o banco de dados SQLite.
     */
    PersistenciaHospede();

    /**
     * @brief Destrutor que fecha a conexão com o banco de dados.
     */
    ~PersistenciaHospede();

    /**
     * @brief Persiste um novo hóspede no repositório (tabela HOSPEDES).
     *
     * @param hospede Objeto Hospede contendo os dados a serem gravados.
     * @return true Se o cadastro for bem-sucedido.
     * @return false Se ocorrer violação de chave primária ou falha na inserção.
     */
    bool cadastrar(const Hospede& hospede) override;

    /**
     * @brief Consulta um hóspede pelo seu email (chave primária).
     *
     * @param email Email do hóspede a ser consultado.
     * @return Hospede Objeto Hospede preenchido com os dados recuperados.
     * @throw runtime_error Se o hóspede não for encontrado ou ocorrer erro de leitura.
     */
    Hospede consultar(const Email& email) override;

    /**
     * @brief Atualiza os dados de um hóspede existente identificando-o pelo email.
     *
     * @param hospede Objeto Hospede com os novos dados (o email deve ser o mesmo da linha a ser atualizada).
     * @return true Se a atualização afetar alguma linha.
     * @return false Se nenhuma linha for alterada ou ocorrer falha.
     */
    bool editar(const Hospede& hospede) override;

    /**
     * @brief Remove um hóspede do repositório pelo email.
     *
     * @param email Email do hóspede a ser excluído.
     * @return true Se a exclusão for bem-sucedida e uma linha for removida.
     * @return false Se nenhuma linha for removida ou ocorrer falha.
     */
    bool excluir(const Email& email) override;

    /**
     * @brief Retorna a lista completa de hóspedes cadastrados.
     *
     * @return vector<Hospede> Vetor com todos os hóspedes presentes na tabela.
     * @throw runtime_error Em caso de erro ao executar a consulta no banco.
     */
    vector<Hospede> listarTodos() override;
};

#endif // PERSISTENCIAHOSPEDE_HPP_INCLUDED
