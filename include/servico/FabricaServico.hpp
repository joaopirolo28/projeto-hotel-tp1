/**
 * @file FabricaServico.hpp
 * @brief Interface de Fábrica para criação de Serviços de Lógica de Negócio (ILN).
 */
#ifndef FABRICASERVICO_HPP
#define FABRICASERVICO_HPP

#include "interfaces/interfaces.hpp"

/**
 * @brief Interface para o padrão Fábrica.
 * @details Define os métodos para criar as instâncias concretas
 * dos serviços de Lógica de Negócio (ILN).
 */
class FabricaServico {
public:
    virtual ~FabricaServico() {}

    // --- MÉTODOS EXISTENTES (Autenticação) ---
    /**
     * @brief Cria e retorna uma instância do Serviço de Autenticação.
     * @return Ponteiro para a interface IServicoAutenticacao.
     */
    virtual IServicoAutenticacao* criarServicoAutenticacao() = 0;

    /**
     * @brief Cria e retorna uma instância do Serviço de Gerenciamento de Gerentes (CRUD).
     * @return Ponteiro para a interface IServiçoGerente.
     */
    virtual IServicoGerente* criarServicoGerente() = 0;

    /**
     * @brief Cria e retorna uma instância do Serviço de Gerenciamento de Hóspedes.
     * @return Ponteiro para a interface IServiçoHospede.
     */
    virtual IServicoHospede* criarServicoHospede() = 0;

    /**
     * @brief Cria e retorna uma instância do Serviço de Hotéis.
     * @return Ponteiro para a interface IServiçoHotel.
     */
    virtual IServicoHotel* criarServicoHotel() = 0;

    /**
     * @brief Cria e retorna uma instância do Serviço de Quartos.
     * @return Ponteiro para a interface IServiçoQuarto.
     */
    virtual IServicoQuarto* criarServicoQuarto() = 0;

    /**
     * @brief Cria e retorna uma instância do Serviço de Reservas.
     * @return Ponteiro para a interface IServiçoReservas.
     */
    virtual IServicoReserva* criarServicoReservas() = 0;
};

#endif // FABRICASERVICO_HPP
