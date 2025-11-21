/**
 * @file IControleGerente.hpp
 * @brief Definição da interface de controle (Contêiner) para a entidade Gerente.
 */
#ifndef ICONTRLEGERENTE_HPP
#define ICONTRLEGERENTE_HPP

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <list>

class IControleGerente {
public:
    virtual ~IControleGerente() = default;

    /**
     * @brief Inclui um novo Gerente no contêiner.
     * @param gerente Objeto Gerente a ser salvo.
     * @return true se a inclusão for bem-sucedida, false se o Email já existir.
     */
    virtual bool incluir(const Gerente& gerente) = 0;

    /**
     * @brief Remove um Gerente pela chave primária (Email).
     * @param email O Email do Gerente a ser removido.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    virtual bool remover(const Email& email) = 0;

    /**
     * @brief Pesquisa um Gerente pelo Email.
     * @param email O Email do Gerente a ser pesquisado.
     * @return O objeto Gerente encontrado.
     * @throw runtime_error se o Gerente não for encontrado.
     */
    virtual Gerente pesquisar(const Email& email) = 0;

    /**
     * @brief Atualiza os dados de um Gerente existente.
     * @param gerente O objeto Gerente com os dados a serem atualizados.
     * @return true se a atualização for bem-sucedida, false se o Gerente não existir.
     */
    virtual bool atualizar(const Gerente& gerente) = 0;
};

#endif // ICONTRLEGERENTE_HPP
