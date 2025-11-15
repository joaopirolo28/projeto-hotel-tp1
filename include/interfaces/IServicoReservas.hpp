/**
 * @file IServicoReservas.hpp
 * @brief Definição da interface para os serviços de reserva.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef ISERVICORESERVAS_HPP
#define ISERVICORESERVAS_HPP

#include <vector>
#include "entidades/reserva.hpp"
#include "dominios/codigo.hpp"
#include "dominios/email.hpp"

/**
 * @brief Interface que define os serviços de CRUD para Reservas.
 */
class IServicoReservas {
public:
    virtual ~IServicoReservas() {}

    virtual bool cadastrarReserva(Reserva reserva) = 0;
    virtual Reserva consultarReserva(Codigo codigo) = 0;
    virtual bool editarReserva(Reserva reserva) = 0;
    virtual bool excluirReserva(Codigo codigo) = 0;
    virtual std::vector<Reserva> listarReservas(Email emailHospede) = 0;
};

#endif // ISERVICORESERVAS_HPP