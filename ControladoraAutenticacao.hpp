/**
 * @file ControladoraAutenticacao.hpp
 * @brief Definição da Controladora concreta para Autenticação.
 */
#ifndef CONTROLADORAAUTENTICACAO_HPP
#define CONTROLADORAAUTENTICACAO_HPP

#include "apresentacao/IControladoraAutenticacao.hpp"
#include <memory>
#include <iostream>

/**
 * @brief Controladora responsável por receber entrada do usuário para login e cadastro.
 */
class ControladoraAutenticacao : public IControladoraAutenticacao {
    private:
        std::unique_ptr<ILNAutenticacao> servicoAutenticacao;

    public:
        /**
         * @brief Construtor que recebe e armazena o serviço de autenticação.
         * @param servico Ponteiro para a implementação da interface ILNAutenticacao.
         */
        ControladoraAutenticacao(std::unique_ptr<ILNAutenticacao> servico);

        /**
         * @brief Inicia o fluxo de autenticação.
         * @details Apresenta as opções (login ou cadastro) ao usuário.
         * @return Retorna o email do Gerente logado ou um email vazio se o login falhar.
         */
        string executar() override;

    private:
        string solicitarLogin();
        void solicitarCadastro();
};

#endif // CONTROLADORAAUTENTICACAO_HPP
