/**
 * @file ControladoraAutenticacao.hpp
 * @brief Defini��o da Controladora concreta para Autentica��o.
 */
#ifndef CONTROLADORAAUTENTICACAO_HPP
#define CONTROLADORAAUTENTICACAO_HPP

#include "apresentacao/IControladoraAutenticacao.hpp"
#include <memory>
#include <iostream>

/**
 * @brief Controladora respons�vel por receber entrada do usu�rio para login e cadastro.
 */
class ControladoraAutenticacao : public IControladoraAutenticacao {
    private:
        std::unique_ptr<IServicoAutenticacao> servicoAutenticacao;

    public:
        /**
         * @brief Construtor que recebe e armazena o servi�o de autentica��o.
         * @param servico Ponteiro para a implementa��o da interface ILNAutenticacao.
         */
        ControladoraAutenticacao(std::unique_ptr<IServicoAutenticacao> servico);

        /**
         * @brief Inicia o fluxo de autentica��o.
         * @details Apresenta as op��es (login ou cadastro) ao usu�rio.
         * @return Retorna o email do Gerente logado ou um email vazio se o login falhar.
         */
        string executar() override;

    private:
        string solicitarLogin();
        void solicitarCadastro();
};

#endif // CONTROLADORAAUTENTICACAO_HPP
