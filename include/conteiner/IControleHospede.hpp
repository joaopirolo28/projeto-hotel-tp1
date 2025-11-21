/**
 * @file IControleHospede.hpp
 * @brief Definição da interface de controle (Contêiner) para a entidade Hospede.
 */
#ifndef ICONTRLEHOSPEDE_HPP
#define ICONTRLEHOSPEDE_HPP

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>

class IControleHospede {
public:
    virtual ~IControleHospede() = default;

    /**
     * @brief Inclui um novo Hospede no contêiner.
     * @param hospede Objeto Hospede a ser salvo.
     * @return true se a inclusão for bem-sucedida, false se o Email já existir.
     */
    virtual bool incluir(const Hospede& hospede) = 0;

    /**
     * @brief Remove um Hospede pelo Email.
     * @param email O Email do Hospede a ser removido.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    virtual bool remover(const Email& email) = 0;

    /**
     * @brief Pesquisa um Hospede pelo Email.
     * @param email O Email do Hospede a ser pesquisado.
     * @return O objeto Hospede encontrado.
     * @throw runtime_error se o Hospede não for encontrado.
     */
    virtual Hospede pesquisar(const Email& email) = 0;

    /**
     * @brief Atualiza os dados de um Hospede existente.
     * @param hospede O objeto Hospede com os dados a serem atualizados.
     * @return true se a atualização for bem-sucedida, false se o Hospede não existir.
     */
    virtual bool atualizar(const Hospede& hospede) = 0;
};

#endif // ICONTRLEHOSPEDE_HPP
