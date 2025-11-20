/**
 * @file FabricaServicoImpl.hpp
 * @brief Implementação concreta da interface FabricaServico.
 */
#ifndef FABRICASERVICOIMPL_HPP
#define FABRICASERVICOIMPL_HPP

#include "servico/FabricaServico.hpp"
#include "servico/ServicoAutenticacao.hpp"
#include "servico/PersistenciaGerente.hpp"
#include <memory>

/**
 * @brief Fábrica concreta que implementa a criação dos serviços.
 */
class FabricaServicoImpl : public FabricaServico {
public:
    /**
     * @brief Cria e retorna uma nova instância do Serviço de Autenticação.
     * @details Esta é a única classe que sabe como criar e injetar a dependência de Persistência.
     * @return Ponteiro para a interface ILNAutenticacao (Polimorfismo).
     */
    IServicoAutenticacao* criarServicoAutenticacao() override;
};

#endif // FABRICASERVICOIMPL_HPP