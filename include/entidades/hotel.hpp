/**
 * @file hotel.hpp
 * @brief Definição da classe de entidade Hotel.
 * @author Joao Pedro
 * @date 14 de novembro de 2025
 */

#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED

#include "dominios/nome.hpp"
#include "dominios/endereco.hpp"
#include "dominios/telefone.hpp"
#include "dominios/codigo.hpp"

/**
 * @brief Classe entidade que representa um Hotel no sistema.
 * @details Contém informações básicas do hotel, como nome, endereço,
 * contato telefonico e um código de identificação.
 */
class Hotel {
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
     * @brief Construtor padrão.
     * @details Construtor padrão que é chamado automaticamente.
     */
    Hotel() {}

    /**
     * @brief Define o nome do hotel.
     * @param nome Um objeto do tipo Nome.
     */
    void setNome(Nome nome); // Corrigido
    /**
     * @brief Retorna o nome do hotel.
     * @return Um objeto do tipo Nome.
     */
    Nome getNome() const; // Corrigido


    /**
     * @brief Define o endereço do hotel.
     * @param endereco Um objeto do tipo Endereco.
     */
    void setEndereco(Endereco endereco); // Corrigido
    /**
     * @brief Retorna o endereço do hotel.
     * @return Um objeto do tipo Endereco.
     */
    Endereco getEndereco() const; // Corrigido


    /**
     * @brief Define o telefone do hotel.
     * @param telefone Um objeto do tipo Telefone.
     */
    void setTelefone(Telefone telefone); // Corrigido
    /**
     * @brief Retorna o telefone do hotel.
     * @return Um objeto do tipo Telefone.
     */
    Telefone getTelefone() const;


    /**
     * @brief Define o código do hotel.
     * @param codigo Um objeto do tipo Codigo.
     */
    void setCodigo(Codigo codigo); // Corrigido
    /**
     * @brief Retorna o codigo do hotel.
     * @return Um objeto do tipo Codigo.
     */
    Codigo getCodigo() const;


};


inline void Hotel::setNome(Nome nome) { 
    this->nome = nome;
}

inline Nome Hotel::getNome() const { 
    return nome;
}

inline void Hotel::setEndereco(Endereco endereco) { 
    this->endereco = endereco;
}

inline Endereco Hotel::getEndereco() const { 
    return endereco;
}

inline void Hotel::setTelefone(Telefone telefone) {
    this->telefone = telefone;
}

inline Telefone Hotel::getTelefone() const { 
    return telefone;
}

inline void Hotel::setCodigo(Codigo codigo) { 
    this->codigo = codigo;
}

inline Codigo Hotel::getCodigo() const {
    return codigo;
}

#endif // HOTEL_HPP_INCLUDED