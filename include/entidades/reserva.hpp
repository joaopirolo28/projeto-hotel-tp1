/**
 * @file reserva.hpp
 * @brief Definição da classe da entidade Reserva.
 * @author João Pedro
 * @date 14/11/2025
 */

#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED

#include "dominios/dominios.hpp"

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

    /**
     * @brief O email do hóspede associado à reserva (Domínio Email).
     */
    Email emailHospede;
    /**
     * @brief O código do hotel onde a reserva foi feita (Domínio Codigo).
     */
    Codigo codigoHotel;
    /**
     * @brief O número do quarto reservado (Domínio Numero).
     */
    Numero numeroQuarto;

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

    /**
     * @brief Define o email do hóspede.
     * @param emailHospede Um objeto do tipo Email.
     */
    void setEmailHospede(Email emailHospede);
    /**
     * @brief Retorna o email do hóspede.
     * @return Um objeto do tipo Email.
     */
    Email getEmailHospede() const;

    /**
     * @brief Define o código do hotel.
     * @param codigoHotel Um objeto do tipo Codigo.
     */
    void setCodigoHotel(Codigo codigoHotel);
    /**
     * @brief Retorna o código do hotel.
     * @return Um objeto do tipo Codigo.
     */
    Codigo getCodigoHotel() const;

    /**
     * @brief Define o número do quarto.
     * @param numeroQuarto Um objeto do tipo Numero.
     */
    void setNumeroQuarto(Numero numeroQuarto);
    /**
     * @brief Retorna o número do quarto.
     * @return Um objeto do tipo Numero.
     */
    Numero getNumeroQuarto() const;
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

inline void Reserva::setEmailHospede(Email emailHospede) {
    this->emailHospede = emailHospede;
}

inline Email Reserva::getEmailHospede() const {
    return emailHospede;
}

inline void Reserva::setCodigoHotel(Codigo codigoHotel) {
    this->codigoHotel = codigoHotel;
}

inline Codigo Reserva::getCodigoHotel() const {
    return codigoHotel;
}

inline void Reserva::setNumeroQuarto(Numero numeroQuarto) {
    this->numeroQuarto = numeroQuarto;
}

inline Numero Reserva::getNumeroQuarto() const {
    return numeroQuarto;
}

#endif // RESERVA_HPP_INCLUDED
