/**
 * @file ControladoraAutenticacao.hpp
 * @brief Definicao da Controladora concreta para Autenticacao.
 */

#ifndef CONTROLADORAAUTENTICACAO_HPP
#define CONTROLADORAAUTENTICACAO_HPP

#include "apresentacao/IControladoraAutenticacao.hpp"
#include "interfaces/interfaces.hpp"
#include <memory>
#include <string>

using namespace std;

/**
 * @brief Controladora responsavel por receber entrada do usuario para login e cadastro.
 * @details Esta controladora assume a propriedade dos servicos injetados (unique_ptr) e coordena
 * a navegacao inicial do sistema e a validacao dos dados de entrada (Dominios).
 */
class ControladoraAutenticacao : public IControladoraAutenticacao {
private:

    std::unique_ptr<IServicoAutenticacao> servicoAutenticacao;
    std::unique_ptr<IServicoGerente> servicoGerente;

    string solicitarLogin();
    void solicitarCadastro();

public:
    /**
     * @brief Construtor que recebe e armazena os servicos necessarios.
     * @details Assume a propriedade (unique_ptr) dos servicos injetados.
     * @param servicoAuth Ponteiro para a implementacao da interface de Autenticacao.
     * @param servicoGerente Ponteiro para a implementacao da interface de Gerente (CRUD).
     */
    ControladoraAutenticacao(
        std::unique_ptr<IServicoAutenticacao> servicoAuth,
        std::unique_ptr<IServicoGerente> servicoGerente
    );

    /**
     * @brief Inicia o fluxo de autenticacao.
     * @details Apresenta as opcoes (login ou cadastro) ao usuario em um loop de navegacao.
     * @return Retorna o email do Gerente logado ou um email vazio se o login falhar.
     */
    string executar() override;
};

#endif // CONTROLADORAAUTENTICACAO_HPP
