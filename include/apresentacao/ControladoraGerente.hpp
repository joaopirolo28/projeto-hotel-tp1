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
#include "apresentacao/IControladoraHospede.hpp"
#include "apresentacao/IControladoraReserva.hpp"

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
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Hospedes.
     * @details A posse do unique_ptr garante o ciclo de vida do serviço.
     */
    std::unique_ptr<IServicoHospede> servicoHospede;
    /**
     * @brief Ponteiro inteligente para o Serviço de Gerenciamento de Reserva.
     * @details A posse do unique_ptr garante o ciclo de vida do serviço.
     */
    std::unique_ptr<IServicoReserva> servicoReserva;

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

    /**
     * @brief Ponteiro para a Controladora responsável pelo CRUD de Hospedes.
     * @details Usado para delegar a exibição do menu de Hospedes.
     */
    IControladoraHospede* controladoraHospede;

    /**
     * @brief Ponteiro para a Controladora responsável pelo CRUD de Reserva.
     * @details Usado para delegar a exibição do menu de Reserva.
     */
    IControladoraReserva* controladoraReserva;

public:
    /**
     * @brief Construtor da ControladoraGerente.
     * @details Implementa o padrão de Injeção de Dependência, recebendo a posse
     * dos serviços (unique_ptr) e a referência das controladoras de CRUD.
     * @param sHotel Ponteiro inteligente (unique_ptr) para o Serviço de Hotéis. A posse é transferida.
     * @param sQuarto Ponteiro inteligente (unique_ptr) para o Serviço de Quartos. A posse é transferida.
     * @param sHospede Ponteiro inteligente (unique_ptr) para o Serviço de Hóspedes. A posse é transferida.
     * @param sReserva Ponteiro inteligente (unique_ptr) para o Serviço de Reservas. A posse é transferida.
     * @param cHotel Ponteiro raw para a Controladora de Hotéis (apenas referência).
     * @param cQuarto Ponteiro raw para a Controladora de Quartos (apenas referência).
     * @param cHospede Ponteiro raw para a Controladora de Hóspedes (apenas referência).
     * @param cReserva Ponteiro raw para a Controladora de Reservas (apenas referência).
     */
    ControladoraGerente(
        std::unique_ptr<IServicoHotel> sHotel,
        std::unique_ptr<IServicoQuarto> sQuarto,
        std::unique_ptr<IServicoHospede> sHospede,
        std::unique_ptr<IServicoReserva> sReserva,
        IControladoraHotel* cHotel,
        IControladoraQuarto* cQuarto,
        IControladoraHospede* cHospede,
        IControladoraReserva* cReserva
    );

    virtual ~ControladoraGerente();

    /**
     * @brief Exibe o menu principal de opções para o Gerente.
     * @details Implementa o loop principal de interação do Gerente, chamando
     * as controladoras de CRUD (ex: controladoraHotel->executar()) conforme a opção selecionada.
     */
    void executar() override;
};

#endif // CONTROLADORAGERENTE_HPP
