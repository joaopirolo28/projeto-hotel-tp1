/**
 * @file IPersistenciaQuarto.hpp
 * @brief Definição da interface de persistência (Contrato) para a entidade Quarto.
 * @author João Pedro
 * @date 21 de novembro de 2025
 */

#ifndef IPERSISTENCIAQUARTO_HPP
#define IPERSISTENCIAQUARTO_HPP

#include "dominios/codigo.hpp"
#include "dominios/numero.hpp"
#include "entidades/quarto.hpp"
#include <stdexcept>
#include <vector>

/**
 * @brief Interface Abstrata para Persistência de Dados do Quarto.
 * @details Define o contrato CRUD para a entidade Quarto, que utiliza uma chave
 * composta (Código do Hotel + Número do Quarto) para identificação única.
 */
class IPersistenciaQuarto {
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~IPersistenciaQuarto() = default;

    /**
     * @brief Armazena um novo Quarto no repositório de dados.
     * @param codigoHotel Código do Hotel ao qual o quarto pertence.
     * @param quarto Objeto Quarto a ser persistido.
     * @return true se o cadastro for bem-sucedido, false caso contrário
     *         (chave duplicada ou chave estrangeira inválida).
     */
    virtual bool cadastrar(const Codigo& codigoHotel, const Quarto& quarto) = 0;

    /**
     * @brief Consulta um Quarto pela sua chave composta.
     * @param codigoHotel Código do Hotel.
     * @param numeroQuarto Número do Quarto.
     * @return O objeto Quarto se encontrado.
     * @throws std::runtime_error Se o quarto não existir no repositório.
     */
    virtual Quarto consultar(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    /**
     * @brief Edita um Quarto existente no repositório de dados.
     * @param codigoHotel Código do Hotel ao qual o quarto pertence.
     * @param quarto Objeto Quarto com dados atualizados.
     * @return true se a edição for bem-sucedida, false caso contrário.
     */
    virtual bool editar(const Codigo& codigoHotel, const Quarto& quarto) = 0;

    /**
     * @brief Exclui um Quarto pela sua chave composta.
     * @param codigoHotel Código do Hotel.
     * @param numeroQuarto Número do Quarto a ser excluído.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    virtual bool excluir(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

    /**
     * @brief Retorna uma lista de todos os quartos de um hotel específico.
     * @param codigoHotel Código do Hotel usado como filtro.
     * @return Vetor contendo objetos Quarto.
     */
    virtual std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) = 0;
};

#endif // IPERSISTENCIAQUARTO_HPP
