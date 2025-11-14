/**
 * @file hotel.hpp
 * @brief Definição da classe da entidade Hotel.
 * @author João Pedro
 * @date 14/11/2025
 */

#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED

// Assumindo que os includes para Domínios estão em hotel.hpp
#include "dominios/nome.hpp"
#include "dominios/endereco.hpp"
#include "dominios/telefone.hpp"
#include "dominios/codigo.hpp"

/**
 * @brief Classe entidade que representa um Hotel no sistema.
 * @details Contém informações básicas do hotel, como nome, endereço,
 * contato telefônico e um código de identificação.
 */
class Hotel{
    private:
        /**
         * @brief O nome comercial do hotel (Domínio Nome).
         */
        Nome nome;
        /**
         * @brief O endereço físico do hotel (Domínio Endereco).
         */
        Endereco endereco;
        /**
         * @brief O número de telefone de contato do hotel (Domínio Telefone).
         */
        Telefone telefone;
        /**
         * @brief O código único de identificação do hotel (Domínio Codigo).
         */
        Codigo codigo;

    public:

        /**
         * @brief Define o nome do hotel.
         * @param nome Um objeto do tipo Nome.
         */
        void setNome(Nome nome);
        /**
         * @brief Retorna o nome do hotel.
         * @return Um objeto do tipo Nome.
         */
        Nome getNome();

        /**
         * @brief Define o endereço do hotel.
         * @param endereco Um objeto do tipo Endereco.
         */
        void setEndereco(Endereco endereco);
        /**
         * @brief Retorna o endereço do hotel.
         * @return Um objeto do tipo Endereco.
         */
        Endereco getEndereco();

        // ... (Outros métodos set/get devem ser documentados de forma similar)

};

// ... (Métodos inline mantidos)

#endif // HOTEL_HPP_INCLUDED
