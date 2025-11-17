/**
 * @file interfaces.hpp
 * @brief Definição de todas as interfaces de Lógica de Negócio (ILN).
 * @author Tarsila Marques
 * @date 16 de novembro de 2025
 */

#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include <vector>

using namespace std;

/**
 * @brief Interface de Lógica de Negócio para Autenticação.
 * @details Define o contrato para autenticar e gerenciar contas de Gerente.
 */
class ILNAutenticacao {
public:
    virtual ~ILNAutenticacao() {}
    virtual bool autenticar(Email email, Senha senha) = 0;
    virtual bool cadastrarGerente(Gerente gerente) = 0;
    virtual Gerente consultarGerente(Email email) = 0;
    virtual bool editarGerente(Gerente gerente) = 0;
    virtual bool excluirGerente(Email email) = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Gerenciamento de Hóspedes.
 */
class ILNGerenciamentoHospedes {
public:
    virtual ~ILNGerenciamentoHospedes() {}
    virtual bool cadastrarHospede(Hospede hospede) = 0;
    virtual Hospede consultarHospede(Email email) = 0;
    virtual bool editarHospede(Hospede hospede) = 0;
    virtual bool excluirHospede(Email email) = 0;
    virtual vector<Hospede> listarHospedes() = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Hotelaria (Hoteis e Quartos).
 */
class ILNHotelaria {
public:
    virtual ~ILNHotelaria() {}
    virtual bool cadastrarHotel(Hotel hotel) = 0;
    virtual Hotel consultarHotel(Codigo codigo) = 0;
    virtual bool editarHotel(Hotel hotel) = 0;
    virtual bool excluirHotel(Codigo codigo) = 0;
    virtual vector<Hotel> listarHoteis() = 0;

    virtual bool cadastrarQuarto(Codigo codigoHotel, Quarto quarto) = 0;
    virtual Quarto consultarQuarto(Numero numero) = 0;
    virtual bool editarQuarto(Quarto quarto) = 0;
    virtual bool excluirQuarto(Numero numero) = 0;
    virtual vector<Quarto> listarQuartos(Codigo codigoHotel) = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Reservas.
 */
class ILNReservas {
public:
    virtual ~ILNReservas() {}
    virtual bool cadastrarReserva(Reserva reserva) = 0;
    virtual Reserva consultarReserva(Codigo codigo) = 0;
    virtual bool editarReserva(Reserva reserva) = 0;
    virtual bool excluirReserva(Codigo codigo) = 0;
    virtual vector<Reserva> listarReservas(Email emailHospede) = 0;
};

#endif // INTERFACES_HPP_INCLUDED
