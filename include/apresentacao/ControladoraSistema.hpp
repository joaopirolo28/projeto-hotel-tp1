/**
 * @file ControladoraSistema.hpp
 * @brief Implementação da Controladora Principal do Sistema.
 * @author João Pedro
 * @date 23/11/2025
 */
#ifndef CONTROLADORASISTEMA_HPP_INCLUDED
#define CONTROLADORASISTEMA_HPP_INCLUDED

#include "apresentacao/IControladoraSistema.hpp"
#include "apresentacao/IControladoraAutenticacao.hpp"
#include "apresentacao/IControladoraGerente.hpp"
#include "servico/FabricaServico.hpp"
#include <iostream>
#include <string> // Necessário para a string do email logado

/**
 * @brief Controladora principal que gerencia o fluxo de execução do sistema.
 * @details Recebe a Fabrica e a usa para criar as controladoras específicas (Autenticação, Menus).
 * Atua como o ponto de entrada da aplicação e gerencia a transição entre os menus.
 */
class ControladoraSistema : public IControladoraSistema {
private:
    /**
     * @brief Ponteiro para a Fabrica de Serviços. Usado para criar instancias de controladoras.
     */
    FabricaServico* fabrica;

    /**
     * @brief Ponteiro para a Controladora de Autenticação (login/cadastro).
     */
    IControladoraAutenticacao* controladoraAutenticacao;
    
    /**
     * @brief Ponteiro para a Controladora do Menu Gerente (pós-login).
     */
    IControladoraGerente* controladoraGerente;

    /**
     * @brief Armazena o email do gerente logado (chave de sessão).
     */
    string emailGerenteLogado = "";

    /**
     * @brief Carrega (instancia) e injeta as controladoras de Apresentação.
     */
    void carregarControladoras();

    /**
     * @brief Apresenta o menu principal após o login.
     */
    void apresentarMenuPrincipal();

public:
    /**
     * @brief Construtor da Controladora Geral.
     * @param f Ponteiro para a Fábrica de Serviços.
     */
    ControladoraSistema(FabricaServico* f);

    /**
     * @brief Destrutor padrão.
     */
    virtual ~ControladoraSistema();

    /**
     * @brief Inicializa a aplicação e gerencia o fluxo de login/menu.
     * @details Implementa o loop principal de interação do usuário, chamando
     * as controladoras de nível superior.
     */
    void executar() override;
};

#endif // CONTROLADORASISTEMA_HPP_INCLUDED