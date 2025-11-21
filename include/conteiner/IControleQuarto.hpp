/**
 * @file IControleQuarto.hpp
 * @brief Definição da interface de controle (Contêiner) para a entidade Quarto.
 */
#ifndef ICONTRLEQUARTO_HPP
#define ICONTRLEQUARTO_HPP

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include <stdexcept>
#include <vector>

class IControleQuarto {
public:
    virtual ~IControleQuarto() = default;

    /**
     * @brief Inclui um novo Quarto no contêiner.
     * @param codigoHotel Codigo do Hotel ao qual o quarto pertence.
     * @param quarto Objeto Quarto a ser salvo.
     * @return true se a inclusão for bem-sucedida, false se o Quarto já existir.
     */
    virtual bool incluir(const Codigo& codigoHotel, const Quarto& quarto) = 0;

    /**
     * @brief Remove um Quarto pela chave composta (Codigo Hotel + Numero Quarto).
     * @param codigoHotel Codigo do Hotel.
     * @param numeroQuarto Numero do Quarto a ser removido.
     * @return true se a remoção for bem-sucedida, false caso contrário.
     */
    virtual bool remover(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    /**
     * @brief Pesquisa um Quarto pela chave composta.
     * @param codigoHotel Codigo do Hotel.
     * @param numeroQuarto Numero do Quarto a ser pesquisado.
     * @return O objeto Quarto encontrado.
     * @throw runtime_error se o Quarto não for encontrado.
     */
    virtual Quarto pesquisar(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    /**
     * @brief Atualiza os dados de um Quarto existente.
     * @param codigoHotel Codigo do Hotel.
     * @param quarto O objeto Quarto com os dados a serem atualizados.
     * @return true se a atualização for bem-sucedida, false se o Quarto não existir.
     */
    virtual bool atualizar(const Codigo& codigoHotel, const Quarto& quarto) = 0;

    /**
     * @brief Retorna a lista de Quartos pertencentes a um Hotel.
     * @param codigoHotel Codigo do Hotel.
     * @return Um vetor de objetos Quarto.
     */
    virtual std::vector<Quarto> listarPorHotel(const Codigo& codigoHotel) = 0;
};

#endif // ICONTRLEQUARTO_HPP
