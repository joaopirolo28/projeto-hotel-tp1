/**
 * @file reserva.hpp
 * @brief Definição da classe da entidade Reserva.
 * @author João Pedro
 * @date 14/11/2025
 */

#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED

// Includes necessários para os domínios
#include "dominios/data.hpp"
#include "dominios/dinheiro.hpp"
#include "dominios/codigo.hpp"

/**
 * @brief Classe entidade que representa uma Reserva de hospedagem.
 * @details Contém as datas de chegada e partida, o valor total e
 * um código único de identificação da reserva.
 */
class Reserva {
private:
    /**
     * @brief A data de chegada do hóspede (Domínio Data).
     */
    Data chegada;
    /**
     * @brief A data de partida/saída do hóspede (Domínio Data).
     */
    Data partida;
    /**
     * @brief O valor total da reserva (Domínio Dinheiro).
     */
    Dinheiro valor;
    /**
     * @brief O código único de identificação da reserva (Domínio Codigo).
     */
    Codigo codigo;

public:
    /**
     * @brief Construtor padrão.
     * @details Construtor padrão que é chamado automaticamente.
     */
    Reserva() {}

    /**
     * @brief Define a data de chegada da reserva.
     * @param chegada Um objeto do tipo Data.
     */
    void setChegada(Data chegada);
    /**
     * @brief Retorna a data de chegada da reserva.
     * @return Um objeto do tipo Data.
     */
    Data getChegada() const; // Adicionado const

    /**
     * @brief Define a data de partida da reserva.
     * @param partida Um objeto do tipo Data.
     */
    void setPartida(Data partida);
    /**
     * @brief Retorna a data de partida da reserva.
     * @return Um objeto do tipo Data.
     */
    Data getPartida() const; // Adicionado const

    /**
     * @brief Define o valor total da reserva.
     * @param valor Um objeto do tipo Dinheiro.
     */
    void setValor(Dinheiro valor);
    /**
     * @brief Retorna o valor total da reserva.
     * @return Um objeto do tipo Dinheiro.
     */
    Dinheiro getValor() const; 

    /**
     * @brief Define o código de identificação da reserva.
     * @param codigo Um objeto do tipo Codigo.
     */
    void setCodigo(Codigo codigo);
    /**
     * @brief Retorna o código de identificação da reserva.
     * @return Um objeto do tipo Codigo.
     */
    Codigo getCodigo() const; 
};



inline void Reserva::setChegada(Data chegada) {
    this->chegada = chegada;
}

inline Data Reserva::getChegada() const {
    return chegada;
}

inline void Reserva::setPartida(Data partida) {
    this->partida = partida;
}

inline Data Reserva::getPartida() const {
    return partida;
}

inline void Reserva::setValor(Dinheiro valor) {
    this->valor = valor;
}

inline Dinheiro Reserva::getValor() const {
    return valor;
}

inline void Reserva::setCodigo(Codigo codigo) {
    this->codigo = codigo;
}

inline Codigo Reserva::getCodigo() const {
    return codigo;
}

#endif // RESERVA_HPP_INCLUDED