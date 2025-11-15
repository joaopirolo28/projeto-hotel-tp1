/**
 * @file IFabricaServicos.hpp
 * @brief Definição da interface da Fábrica Abstrata de Serviços.
 * @author Tarsila Marques
 * @date 15 de novembro de 2025
 */

#ifndef IFABRICASERVICOS_HPP
#define IFABRICASERVICOS_HPP

// Inclui as definições de todas as interfaces de serviço
#include "IServicoAutenticacao.hpp"
#include "IServicoGerenciamentoContas.hpp"
#include "IServicoHotelaria.hpp"
#include "IServicoReservas.hpp"

/**
 * @brief Interface da Fábrica Abstrata (Abstract Factory).
 * @details Define métodos para criar a família de serviços do sistema,
 * escondendo as implementações concretas da Camada de Apresentação.
 */
class IFabricaServicos {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IFabricaServicos() {}

    /**
     * @brief Cria ou retorna uma instância do serviço de autenticação.
     * @return Ponteiro para a interface IServicoAutenticacao.
     */
    virtual IServicoAutenticacao* criarServicoAutenticacao() = 0;

    /**
     * @brief Cria ou retorna uma instância do serviço de gerenciamento de contas.
     * @return Ponteiro para a interface IServicoGerenciamentoContas.
     */
    virtual IServicoGerenciamentoContas* criarServicoGerenciamentoContas() = 0;

    /**
     * @brief Cria ou retorna uma instância do serviço de hotelaria.
     * @return Ponteiro para a interface IServicoHotelaria.
     */
    virtual IServicoHotelaria* criarServicoHotelaria() = 0;

    /**
     * @brief Cria ou retorna uma instância do serviço de reservas.
     * @return Ponteiro para a interface IServicoReservas.
     */
    virtual IServicoReservas* criarServicoReservas() = 0;
};

#endif // IFABRICASERVICOS_HPP