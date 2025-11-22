/**
 * @file ControladoraGerente.hpp
 * @brief Definição da classe concreta para a Controladora do Menu Principal do Gerente.
 * @author João Pedro
 * @date 22/11/2025
 */
#ifndef CONTROLADORAGERENTE_HPP
#define CONTROLADORAGERENTE_HPP

#include "apresentacao/IControladoraGerente.hpp"
#include "apresentacao/IControladoraHotel.hpp"
#include "apresentacao/IControladoraQuarto.hpp"
#include "interfaces/interfaces.hpp"

#include <memory>
#include <iostream>

/**
 * @brief Implementação concreta da interface IControladoraGerente.
 * @details Esta controladora atua como o **Menu Principal** do gerente após o login.
 * Ela exibe as opções de gerenciamento (Hotéis, Quartos, Hóspedes, Reservas) e
 * delega as interações do usuário para as controladoras de CRUD específicas.
 */
class ControladoraGerente : public IControladoraGerente {
private:

    /**
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Hotéis.
     * @details A posse do unique_ptr garante o ciclo de vida do serviço.
     */
    std::unique_ptr<IServicoHotel> servicoHotel;

    /**
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Quartos.
     * @details A posse do unique_ptr garante o ciclo de vida do serviço.
     */
    std::unique_ptr<IServicoQuarto> servicoQuarto;

    /**
     * @brief Ponteiro para a Controladora responsável pelo CRUD de Hotéis.
     * @details Usado para delegar a exibição do menu de Hotéis.
     */
    IControladoraHotel* controladoraHotel;

    /**
     * @brief Ponteiro para a Controladora responsável pelo CRUD de Quartos.
     * @details Usado para delegar a exibição do menu de Quartos.
     */
    IControladoraQuarto* controladoraQuarto;

public:
    /**
     * @brief Construtor da ControladoraGerente.
     * * @details Implementa o padrão de Injeção de Dependência (DI). Esta controladora
     * recebe a posse (via unique_ptr) dos Serviços de negócio que ela não delega
     * (e.g., Gerente, se aplicável, mas aqui são Hotéis e Quartos), e recebe a
     * referência (raw pointer) das Controladoras que ela deve delegar a execução (Hotéis e Quartos).
     * * @param sHotel Ponteiro inteligente (std::unique_ptr) para o Serviço de Hotéis. A posse deste objeto é transferida.
     * @param sQuarto Ponteiro inteligente (std::unique_ptr) para o Serviço de Quartos. A posse deste objeto é transferida.
     * @param cHotel Ponteiro (raw pointer) para a Controladora de Hotéis. Usado para delegação do fluxo de execução.
     * @param cQuarto Ponteiro (raw pointer) para a Controladora de Quartos. Usado para delegação do fluxo de execução.
     */
    ControladoraGerente(
        unique_ptr<IServicoHotel> sHotel,
        unique_ptr<IServicoQuarto> sQuarto,
        IControladoraHotel* cHotel,
        IControladoraQuarto* cQuarto
    );



    /**
     * @brief Exibe o menu principal de opções para o Gerente.
     * @details Implementa o loop principal de interação do Gerente, chamando
     * as controladoras de CRUD (ex: controladoraHotel->executar()) conforme a opção selecionada.
     */
    void executar() override;
};

#endif // CONTROLADORAGERENTE_HPP
