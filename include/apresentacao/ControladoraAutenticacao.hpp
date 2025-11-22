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
        std::unique_ptr<IServicoGerente> servicoGerente;

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
        /**
         * @brief Construtor que recebe e armazena o servico de autenticacao e servico de gerente.
         * @param servico Ponteiro para a implementacao da interface ILNAutenticacao e ILNServico.
         */
        ControladoraAutenticacao(
        std::unique_ptr<IServicoAutenticacao> servicoAuth,
        std::unique_ptr<IServicoGerente> servicoGerente
    );

    private:
        string solicitarLogin();
        void solicitarCadastro();
};

#endif // CONTROLADORAAUTENTICACAO_HPP
