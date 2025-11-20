/**
 * @file FabricaServicoImpl.hpp
 * @brief Implementação concreta da interface FabricaServico.
 */
#ifndef FABRICASERVICOIMPL_HPP
#define FABRICASERVICOIMPL_HPP

#include "servico/FabricaServico.hpp"

// Classes concretas de Serviço que a fábrica irá construir
#include "servico/ServicoAutenticacao.hpp" 
#include "servico/ServicoGerente.hpp"
#include "servico/ServicoHospede.hpp"
#include "servico/ServicoHotel.hpp"
#include "servico/ServicoQuarto.hpp"
#include "servico/ServicoReservas.hpp"

// Interfaces de Persistência (para que o método de injeção funcione)
#include "servico/IPersistenciaGerente.hpp" 
#include "servico/IPersistenciaHospede.hpp" 
#include "servico/IPersistenciaHotel.hpp" 
#include "servico/IPersistenciaQuarto.hpp" 
#include "servico/IPersistenciaReserva.hpp" 
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
    IServiçoAutenticacao* criarServicoAutenticacao() override;
    
    /**
     * @brief Cria e retorna uma instância do Serviço de Gerentes.
     * @return Ponteiro para a interface IServiçoGerente.
     */
    IServiçoGerente* criarServicoGerente() override;
    
    /**
     * @brief Cria e retorna uma instância do Serviço de Hóspedes.
     * @return Ponteiro para a interface IServiçoHospede.
     */
    IServiçoHospede* criarServicoHospede() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Hotéis.
     * @return Ponteiro para a interface IServiçoHotel.
     */
    IServiçoHotel* criarServicoHotel() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Quartos.
     * @return Ponteiro para a interface IServiçoQuarto.
     */
    IServiçoQuarto* criarServicoQuarto() override;

    /**
     * @brief Cria e retorna uma instância do Serviço de Reservas.
     * @return Ponteiro para a interface IServiçoReservas.
     */
    IServiçoReservas* criarServicoReservas() override;
};

#endif // FABRICASERVICOIMPL_HPP