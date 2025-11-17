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

    /**
     * @brief Cria e retorna uma instância do Serviço de Autenticação.
     * @return Ponteiro para a interface ILNAutenticacao.
     */
    virtual ILNAutenticacao* criarServicoAutenticacao() = 0;
};

#endif // FABRICASERVICO_HPP
