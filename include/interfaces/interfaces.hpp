/**
 * @file interfaces.hpp
 * @brief Definição de todas as interfaces de Lógica de Negócio (ILN) e Apresentação (UI).
 * @author Tarsila Marques
 * @date 16 de novembro de 2025
 */

#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include <vector>

using namespace std;


// Interfaces de Serviço (ILN - Lógica de Negócio)

/**
 * @brief Interface de Lógica de Negócio para Autenticação.
 * @details Define o contrato para autenticar um gerente no sistema.
 */
class IServicoAutenticacao {
public:
    virtual ~IServicoAutenticacao() {}

    /**
     * @brief Autentica um gerente no sistema.
     * @param email O email do gerente para autenticação.
     * @param senha A senha do gerente para autenticação.
     * @return true se as credenciais estiverem corretas, false caso contrário.
     */
    virtual bool autenticar(Email email, Senha senha) = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Gerenciamento de Gerentes.
 * @details Define o contrato de CRUD (Criar, Ler, Editar, Excluir) para a entidade Gerente.
 */
class IServicoGerente {
public:
    virtual ~IServicoGerente(){}
    /**
     * @brief Cadastra um novo gerente.
     * @param gerente O objeto Gerente a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     */
    virtual bool cadastrarGerente(Gerente gerente) = 0;

    /**
     * @brief Consulta um Gerente pelo email.
     * @param email O email do gerente (chave primária).
     * @return O objeto Gerente encontrado.
     * @throw runtime_error Se o gerente não for encontrado.
     */
    virtual Gerente consultarGerente(Email email) = 0;

    /**
     * @brief Edita os dados de um Gerente existente.
     * @param gerente O objeto Gerente com os dados atualizados.
     * @return true se a edição for bem-sucedida.
     */
    virtual bool editarGerente(Gerente gerente) = 0;

    /**
     * @brief Exclui um Gerente pelo email.
     * @param email O email do Gerente a ser excluído.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirGerente(Email email) = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Gerenciamento de Hóspedes.
 * @details Define o contrato de CRUD (Criar, Ler, Editar, Excluir) e listagem de Hóspedes.
 */
class IServicoHospede {
public:
    virtual ~IServicoHospede() {}

    /**
     * @brief Cadastra um novo hóspede.
     * @param hospede O objeto Hospede a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     */
    virtual bool cadastrarHospede(Hospede hospede) = 0;

    /**
     * @brief Consulta um Hóspede pelo email.
     * @param email O email do hóspede (chave primária).
     * @return O objeto Hospede encontrado.
     * @throw runtime_error Se o hóspede não for encontrado.
     */
    virtual Hospede consultarHospede(Email email) = 0;

    /**
     * @brief Edita os dados de um Hóspede existente.
     * @param hospede O objeto Hospede com os dados atualizados.
     * @return true se a edição for bem-sucedida.
     */
    virtual bool editarHospede(Hospede hospede) = 0;

    /**
     * @brief Exclui um Hóspede pelo email.
     * @param email O email do Hóspede a ser excluído.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirHospede(Email email) = 0;

    /**
     * @brief Retorna a lista de todos os hóspedes.
     * @return Um vetor de objetos Hospede.
     */
    virtual vector<Hospede> listarHospedes() = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Hotelaria (Hoteis).
 * @details Define o contrato de CRUD e listagem para a entidade Hotel.
 */
class IServicoHotel {
public:
    virtual ~IServicoHotel() {}

    /**
     * @brief Cadastra um novo hotel.
     * @param hotel O objeto Hotel a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     */
    virtual bool cadastrarHotel(Hotel hotel) = 0;

    /**
     * @brief Consulta um Hotel pelo código.
     * @param codigo O código do hotel (chave primária).
     * @return O objeto Hotel encontrado.
     * @throw runtime_error Se o hotel não for encontrado.
     */
    virtual Hotel consultarHotel(Codigo codigo) = 0;

    /**
     * @brief Edita os dados de um Hotel existente.
     * @param hotel O objeto Hotel com os dados atualizados.
     * @return true se a edição for bem-sucedida.
     */
    virtual bool editarHotel(Hotel hotel) = 0;

    /**
     * @brief Exclui um Hotel pelo código.
     * @param codigo O código do Hotel a ser excluído.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirHotel(Codigo codigo) = 0;

    /**
     * @brief Retorna a lista de todos os hotéis.
     * @return Um vetor de objetos Hotel.
     */
    virtual vector<Hotel> listarHoteis() = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Quartos.
 * @details Define o contrato de CRUD e listagem para a entidade Quarto.
 */
class IServicoQuarto {
public:
    virtual ~IServicoQuarto(){}
    /**
     * @brief Cadastra um novo quarto.
     * @param codigoHotel O código do hotel ao qual o quarto pertence.
     * @param quarto O objeto Quarto a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     */
    virtual bool cadastrarQuarto(Codigo codigoHotel, Quarto quarto) = 0;

    /**
     * @brief Consulta um Quarto pelo número.
     * @param numero O número do quarto (identificador único dentro do hotel).
     * @return O objeto Quarto encontrado.
     * @throw runtime_error Se o quarto não for encontrado.
     */
    virtual Quarto consultarQuarto(Codigo codigoHotel, Numero numero) = 0;

    /**
     * @brief Edita os dados de um Quarto existente.
     * @param quarto O objeto Quarto com os dados atualizados.
     * @return true se a edição for bem-sucedida.
     */
    virtual bool editarQuarto(Codigo codigoHotel, Quarto quarto) = 0;

    /**
     * @brief Exclui um Quarto pelo número.
     * @param numero O número do Quarto a ser excluído.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirQuarto(Codigo codigoHotel, Numero numero) = 0;

    /**
     * @brief Retorna a lista de todos os quartos de um hotel específico.
     * @param codigoHotel O código do hotel para filtrar os quartos.
     * @return Um vetor de objetos Quarto.
     */
    virtual vector<Quarto> listarQuartos(Codigo codigoHotel) = 0;
};

/**
 * @brief Interface de Lógica de Negócio para Reservas.
 * @details Define o contrato de CRUD e listagem para a entidade Reserva.
 */
class IServicoReserva {
public:
    virtual ~IServicoReserva() {}

    /**
     * @brief Cadastra uma nova reserva.
     * @param reserva O objeto Reserva a ser cadastrado.
     * @return true se o cadastro for bem-sucedido.
     * @throw runtime_error Se houver conflito de datas.
     */
    virtual bool cadastrarReserva(Reserva reserva) = 0;

    /**
     * @brief Consulta uma Reserva pelo código.
     * @param codigo O código da reserva (chave primária).
     * @return O objeto Reserva encontrado.
     * @throw runtime_error Se a reserva não for encontrada.
     */
    virtual Reserva consultarReserva(Codigo codigo) = 0;

    /**
     * @brief Edita os dados de uma Reserva existente.
     * @param reserva O objeto Reserva com os dados atualizados.
     * @return true se a edição for bem-sucedida.
     */
    virtual bool editarReserva(Reserva reserva) = 0;

    /**
     * @brief Exclui uma Reserva pelo código.
     * @param codigo O código da Reserva a ser excluída.
     * @return true se a exclusão for bem-sucedida.
     */
    virtual bool excluirReserva(Codigo codigo) = 0;

    /**
     * @brief Retorna a lista de todas as reservas de um hóspede específico.
     * @param emailHospede O email do hóspede para filtrar as reservas.
     * @return Um vetor de objetos Reserva.
     */
    virtual vector<Reserva> listarReservas(Email emailHospede) = 0;
};


// Interfaces de Apresentação

/**
 * @brief Interface para o fluxo de autenticação e login na Camada de Apresentação.
 */
class IApresentacaoAutenticacao {
public:
    virtual ~IApresentacaoAutenticacao() = default;

    /**
     * @brief Inicia o fluxo de interação do usuário para login ou cadastro de gerente.
     */
    virtual void executar() = 0;
};

/**
 * @brief Interface para o menu de Gerente na Camada de Apresentação.
 * @details Define o contrato para exibir o menu principal após o login.
 */
class IApresentacaoGerente {
public:
    virtual ~IApresentacaoGerente() = default;

    /**
     * @brief Exibe o menu de opções para o gerente.
     */
    virtual void menuGerente() = 0;
};

/**
 * @brief Interface para a gestão de Hotéis na Camada de Apresentação.
 */
class IApresentacaoHotel {
public:
    virtual ~IApresentacaoHotel() = default;

    /**
     * @brief Exibe o menu de gestão e CRUD para hotéis.
     */
    virtual void menuHotel() = 0;
};

/**
 * @brief Interface para a gestão de Quartos na Camada de Apresentação.
 */
class IApresentacaoQuarto {
public:
    virtual ~IApresentacaoQuarto() = default;

    /**
     * @brief Exibe o menu de gestão e CRUD para quartos.
     */
    virtual void menuQuarto() = 0;
};

/**
 * @brief Interface para a gestão de Reservas na Camada de Apresentação.
 */
class IApresentacaoReserva {
public:
    virtual ~IApresentacaoReserva() = default;

    /**
     * @brief Exibe o menu de gestão e CRUD para reservas.
     */
    virtual void menuReserva() = 0;
};

/**
 * @brief Interface para a gestão de Hóspedes na Camada de Apresentação.
 */
class IApresentacaoHospede {
public:
    virtual ~IApresentacaoHospede() = default;

    /**
     * @brief Exibe o menu de gestão e CRUD para hóspedes.
     */
    virtual void menuHospede() = 0;
};

#endif // INTERFACES_HPP_INCLUDED
