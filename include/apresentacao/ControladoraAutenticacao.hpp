/**
 * @file ControladoraAutenticacao.hpp
 * @brief Definicao da Controladora concreta para Autenticacao.
 */
#ifndef CONTROLADORAAUTENTICACAO_HPP
#define CONTROLADORAAUTENTICACAO_HPP

#include "apresentacao/IControladoraAutenticacao.hpp"
#include <memory>
#include <iostream>

/**
 * @brief Controladora responsavel por receber entrada do usuario para login e cadastro.
 */
class ControladoraAutenticacao : public IControladoraAutenticacao {
    private:
        std::unique_ptr<IServicoAutenticacao> servicoAutenticacao;

    public:
        /**
         * @brief Construtor que recebe e armazena o servico de autenticacao.
         * @param servico Ponteiro para a implementacao da interface ILNAutenticacao.
         */
        ControladoraAutenticacao(std::unique_ptr<IServicoAutenticacao> servico);

        /**
         * @brief Inicia o fluxo de autenticacao.
         * @details Apresenta as opcoes (login ou cadastro) ao usuario.
         * @return Retorna o email do Gerente logado ou um email vazio se o login falhar.
         */
        string executar() override;

    private:
        string solicitarLogin();
        void solicitarCadastro();
};

#endif // CONTROLADORAAUTENTICACAO_HPP
