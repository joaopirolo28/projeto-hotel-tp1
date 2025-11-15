/**
 * @file IServicoHotelaria.hpp
 * @brief Definição da interface para os serviços de hotelaria (Hotel e Quarto).
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef ISERVICOHOTELARIA_HPP
#define ISERVICOHOTELARIA_HPP

#include <vector>
#include "entidades/hotel.hpp"
#include "entidades/quarto.hpp"
#include "dominios/codigo.hpp"

/**
 * @brief Interface que define os serviços de CRUD para Hotéis e Quartos.
 */
class IServicoHotelaria {
public:
    virtual ~IServicoHotelaria() {}

    // --- Métodos para Hotel ---
    virtual bool cadastrarHotel(Hotel hotel) = 0;
    virtual Hotel consultarHotel(Codigo codigo) = 0;
    virtual bool editarHotel(Hotel hotel) = 0;
    virtual bool excluirHotel(Codigo codigo) = 0;
    virtual std::vector<Hotel> listarHoteis() = 0;

    // --- Métodos para Quarto ---
    virtual bool cadastrarQuarto(Codigo codigoHotel, Quarto quarto) = 0;
    virtual Quarto consultarQuarto(Numero numero) = 0;
    virtual bool editarQuarto(Quarto quarto) = 0;
    virtual bool excluirQuarto(Numero numero) = 0;
    virtual std::vector<Quarto> listarQuartos(Codigo codigoHotel) = 0;
};

#endif // ISERVICOHOTELARIA_HPP