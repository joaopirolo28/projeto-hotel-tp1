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

using namespace std;

/**
 * @brief Interface Abstrata para Persistência de Dados do Quarto.
 * @details Define o contrato CRUD para a entidade Quarto, que utiliza uma chave
 * composta (Codigo do Hotel e Numero do Quarto) para identificação.
 */
class IPersistenciaQuarto {
    public:
        /**
         * @brief Destrutor virtual.
         */
        virtual ~IPersistenciaQuarto() {}

        /**
         * @brief Armazena um novo Quarto no repositório de dados.
         * @param codigoHotel O Código do Hotel ao qual o quarto pertence.
         * @param quarto O objeto Quarto a ser persistido.
         * @return true se o cadastro for bem-sucedido, false caso contrário (chave duplicada ou FK inválida).
         */
        virtual bool cadastrar(const Codigo& codigoHotel, const Quarto& quarto) = 0;

        /**
         * @brief Consulta um Quarto pela sua chave composta.
         * @param codigoHotel O Código do Hotel.
         * @param numeroQuarto O Número do Quarto.
         * @return O objeto Quarto se encontrado.
         * @throw std::runtime_error Se o Quarto não for encontrado no repositório.
         */
        virtual Quarto consultar(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

        /**
         * @brief Edita um Quarto existente no repositório de dados.
         * @param codigoHotel O Código do Hotel ao qual o quarto pertence.
         * @param quarto O objeto Quarto com os dados atualizados.
         * @return true se a edição for bem-sucedida, false caso contrário.
         */
        virtual bool editar(const Codigo& codigoHotel, const Quarto& quarto) = 0;

        /**
         * @brief Exclui um Quarto pela sua chave composta.
         * @param codigoHotel O Código do Hotel.
         * @param numeroQuarto O Número do Quarto a ser excluído.
         * @return true se a exclusão for bem-sucedida, false caso contrário.
         */
        virtual bool excluir(const Codigo& codigoHotel, const Numero& numeroQuarto) = 0;

        /**
         * @brief Retorna uma lista de todos os Quartos de um Hotel específico.
         * @param codigoHotel O Código do Hotel para filtrar os quartos.
         * @return Um vetor (vector) de objetos Quarto.
         */
        virtual std::vector<Quarto> listarQuartos(const Codigo& codigoHotel) = 0;
};

#endif // IPERSISTENCIAQUARTO_HPP
