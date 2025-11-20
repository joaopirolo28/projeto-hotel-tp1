/**
 * @file ControladoraGeral.hpp
 * @brief Implementação da Controladora Principal do Sistema.
 */
#ifndef CONTROLADORASISTEMA_HPP_INCLUDED
#define CONTROLADORASISTEMA_HPP_INCLUDED

#include "apresentacao/IControladoraSistema.hpp"
#include "apresentacao/ControladoraAutenticacao.hpp"
#include "servico/FabricaServico.hpp"

/**
 * @brief Controladora principal que gerencia o fluxo de execução do sistema.
 * @details Recebe a Fábrica e a usa para criar as controladoras específicas (Autenticação, Menus).
 */

 class ControladoraSistema : public IControladoraSistema{
    private:
        FabricaServico* fabrica;

        IControladoraAutenticacao* ControladoraAutenticacao;

        string emailGerenteLogado = "";

        void carregarControladoras();
        void apresentarMenuPrincipal();

    public:
         /**
         * @brief Construtor da Controladora Geral.
         * @param f Ponteiro para a Fábrica de Serviços.
         */
        ControladoraSistema(FabricaServico* f);

        /**
         * @brief Inicializa a aplicação e gerencia o fluxo de login/menu.
         */
        void executar() override;
 };

#endif // CONTROLADORASISTEMA_HPP_INCLUDED
