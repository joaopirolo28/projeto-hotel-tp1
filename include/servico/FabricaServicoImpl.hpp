/**
 * @file FabricaServicoImpl.hpp
 * @brief Implementação concreta da interface FabricaServico.
 */
#ifndef FABRICASERVICOIMPL_HPP
#define FABRICASERVICOIMPL_HPP

#include "servico/FabricaServico.hpp"

#include "servico/ServicoAutenticacao.hpp"
#include "servico/ServicoGerente.hpp"
#include "servico/ServicoHospede.hpp"
#include "servico/ServicoHotel.hpp"
#include "servico/ServicoQuarto.hpp"
#include "servico/ServicoReservas.hpp"

#include "persistencias/IPersistenciaGerente.hpp"
#include "persistencias/IPersistenciaHospede.hpp"
#include "persistencias/IPersistenciaHotel.hpp"
#include "persistencias/IPersistenciaQuarto.hpp"
#include "persistencias/IPersistenciaReserva.hpp"
#include <memory>
#include <utility>

/**
 * @brief Fábrica concreta que implementa a criação dos serviços.
 * @details Esta classe é a única que conhece as classes concretas de Serviço e Persistência
 * e é responsável por criar a instância correta.
 */
class FabricaServicoImpl : public FabricaServico {
public:

    /**
     * @brief Cria e retorna uma nova instância do Serviço de Autenticação.
     * @details Esta é a única classe que sabe como criar e injetar a dependência de Persistência.
     * @return Ponteiro para a interface IServiçoAutenticacao (Polimorfismo).
     */
    IServicoAutenticacao* criarServicoAutenticacao() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Gerentes.
     * @return Ponteiro para a interface IServiçoGerente.
     */
    IServicoGerente* criarServicoGerente() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Hóspedes.
     * @return Ponteiro para a interface IServiçoHospede.
     */
    IServicoHospede* criarServicoHospede() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Hotéis.
     * @return Ponteiro para a interface IServiçoHotel.
     */
    IServicoHotel* criarServicoHotel() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Quartos.
     * @return Ponteiro para a interface IServiçoQuarto.
     */
    IServicoQuarto* criarServicoQuarto() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Reservas.
     * @return Ponteiro para a interface IServiçoReservas.
     */
    IServicoReservas* criarServicoReservas() override;
};

#endif // FABRICASERVICOIMPL_HPP
