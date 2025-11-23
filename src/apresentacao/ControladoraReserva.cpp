#include "apresentacao/ControladoraReserva.hpp"
#include "interfaces/interfaces.hpp"

#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

ControladoraReserva::ControladoraReserva(
    IServicoReserva* sReserva,
    IServicoHotel* sHotel,
    IServicoHospede* sHospede)
    : servicoReserva(sReserva),
      servicoHotel(sHotel),
      servicoHospede(sHospede)
{
    // Armazena as referências raw dos serviços. A posse é da ControladoraGerente.
}

// --- Método Auxiliar de Coleta ---

Reserva ControladoraReserva::coletarDadosReserva() {
    string codigoStr, diaChegadaStr, mesChegadaStr, anoChegadaStr;
    string diaPartidaStr, mesPartidaStr, anoPartidaStr;
    string valorStr;

    // Limpeza inicial do buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Codigo da Reserva (10 caracteres): ";
    cin >> codigoStr;

    // Datas de Chegada
    cout << "\n--- Data de Chegada (Dia Mes Ano) ---" << endl;
    cout << "Dia (1-31): "; cin >> diaChegadaStr;
    cout << "Mes (JAN-DEZ): "; cin >> mesChegadaStr;
    cout << "Ano (2000-2999): "; cin >> anoChegadaStr;

    // Datas de Partida
    cout << "\n--- Data de Partida (Dia Mes Ano) ---" << endl;
    cout << "Dia (1-31): "; cin >> diaPartidaStr;
    cout << "Mes (JAN-DEZ): "; cin >> mesPartidaStr;
    cout << "Ano (2000-2999): "; cin >> anoPartidaStr;

    cout << "\nValor da Reserva (ex: 1200.00): ";
    cin >> valorStr;

    // --- VALIDAÇÃO DE DOMÍNIO ---

    // Converte e valida Datas (assumindo que o Domínio Data lida com bissextos e validade)
    Data chegada(stoi(diaChegadaStr), mesChegadaStr, stoi(anoChegadaStr));
    Data partida(stoi(diaPartidaStr), mesPartidaStr, stoi(anoPartidaStr));

    Dinheiro valor(stod(valorStr));
    Codigo codigo(codigoStr);

    Reserva novaReserva;
    novaReserva.setCodigo(codigo);
    novaReserva.setChegada(chegada);
    novaReserva.setPartida(partida);
    novaReserva.setValor(valor);

    return novaReserva;
}

// --- Métodos Privados de CRUD ---

void ControladoraReserva::realizarReserva() {
    cout << "\n--- REALIZAR RESERVA ---" << endl;
    string emailHospedeStr, codigoHotelStr, numeroQuartoStr;

    try {
        // 1. Coleta e Validação dos dados básicos da Reserva
        Reserva novaReserva = coletarDadosReserva();

        // 2. Coleta de dados de vínculo (Hóspede e Quarto)
        cout << "\n--- VINCULO DA RESERVA ---" << endl;
        cout << "Email do Hospede Responsavel: "; cin >> emailHospedeStr;
        cout << "Codigo do Hotel: "; cin >> codigoHotelStr;
        cout << "Numero do Quarto Desejado: "; cin >> numeroQuartoStr;

        // 3. Validação de Vínculo e Existência (Camada de Apresentação e Serviço)
        Email emailHospede(emailHospedeStr);
        Codigo codigoHotel(codigoHotelStr);
        Numero numeroQuarto(stoi(numeroQuartoStr));

        // Verifica se o Hóspede existe (Chamada ao IServicoHospede)
        servicoHospede->consultarHospede(emailHospede);

        // 4. Chamada ao Serviço de Reserva
        // O IServicoReservas deve internamente:
        // a) Verificar se o quarto existe (usando IServicoHotel)
        // b) Verificar conflito de datas para aquele quarto.
        // c) Persistir o registro, vinculando Email e Quarto/Hotel.

        if (servicoReserva->cadastrarReserva(novaReserva, emailHospede, codigoHotel, numeroQuarto)) {
            cout << "\n Reserva cadastrada com sucesso! Codigo: " << novaReserva.getCodigo().getValor() << endl;
        } else {
            cout << "\n Falha ao cadastrar Reserva. Quarto pode estar ocupado nas datas, ou conflito de PK." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        // Captura erro de Hóspede inexistente, Hotel inexistente, ou falha de negócio
        cout << "\n ERRO NA RESERVA: " << e.what() << endl;
    }
}

void ControladoraReserva::consultarReserva() {
    cout << "\n--- CONSULTA DE RESERVA ---" << endl;
    string codigoStr;
    cout << "Digite o Codigo da Reserva: "; cin >> codigoStr;

    try {
        Codigo codigo(codigoStr);
        Reserva reserva = servicoReserva->consultarReserva(codigo);

        cout << "\n RESERVA ENCONTRADA:" << endl;
        cout << "   Codigo: " << reserva.getCodigo().getValor() << endl;
        cout << "   Chegada: " << reserva.getChegada().getDia() << "/" << reserva.getChegada().getMes() << "/" << reserva.getChegada().getAno() << endl;
        cout << "   Partida: " << reserva.getPartida().getDia() << "/" << reserva.getPartida().getMes() << "/" << reserva.getPartida().getAno() << endl;
        cout << "   Valor: R$ " << fixed << setprecision(2) << reserva.getValor().getValor() << endl;
        // ... (Seria ideal mostrar o Hóspede e o Quarto vinculado)

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Codigo invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO DE CONSULTA: Reserva nao encontrada. " << e.what() << endl;
    }
}

void ControladoraReserva::editarReserva() {
    cout << "\n--- EDICAO DE RESERVA ---" << endl;
    // O ideal seria consultar primeiro.
    try {
        Reserva reservaAtualizada = coletarDadosReserva(); // Coleta dados (incluindo o Código de Reserva)

        // Chamada ao Serviço: O IServicoReservas deve verificar se a edição causa conflitos de data.
        if (servicoReserva->editarReserva(reservaAtualizada)) {
            cout << "\n Reserva com Codigo '" << reservaAtualizada.getCodigo().getValor() << "' editada com sucesso!" << endl;
        } else {
            cout << "\n Falha ao editar Reserva. Novo período pode estar indisponivel." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n️ ERRO DE FORMATO: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EDICAO: " << e.what() << endl;
    }
}

void ControladoraReserva::excluirReserva() {
    cout << "\n--- EXCLUSÃO DE RESERVA ---" << endl;
    string codigoStr;
    cout << "Digite o Codigo da Reserva a ser excluida: "; cin >> codigoStr;

    try {
        Codigo codigo(codigoStr);

        if (servicoReserva->excluirReserva(codigo)) {
            cout << "\n Reserva com Codigo '" << codigo.getValor() << "' excluida com sucesso." << endl;
        } else {
            cout << "\n Falha ao excluir Reserva. O codigo pode ser invalido." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n️ ERRO DE FORMATO: Código invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA EXCLUSAO: " << e.what() << endl;
    }
}

void ControladoraReserva::listarReservas() {
    cout << "\n--- LISTAGEM DE RESERVAS POR HÓSPEDE ---" << endl;
    string emailHospedeStr;
    cout << "Digite o Email do Hospede para listar as reservas: "; cin >> emailHospedeStr;

    try {
        Email emailHospede(emailHospedeStr);
        vector<Reserva> reservas = servicoReserva->listarReservas(emailHospede);

        if (reservas.empty()) {
            cout << "Nenhuma reserva encontrada para este hospede." << endl;
            return;
        }

        cout << "\nRESERVAS ENCONTRADAS PARA " << emailHospede.getEmail() << ":" << endl;
        for (const auto& reserva : reservas) {
            cout << "---------------------------------" << endl;
            cout << "Codigo: " << reserva.getCodigo().getValor() << endl;
            cout << "Chegada: " << reserva.getChegada().getDia() << "/" << reserva.getChegada().getMes() << endl;
            cout << "Partida: " << reserva.getPartida().getDia() << "/" << reserva.getPartida().getMes() << endl;
        }
        cout << "---------------------------------" << endl;

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: Email invalido. " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "\n ERRO NA LISTAGEM: " << e.what() << endl;
    }
}

// --- Método Público de Execução ---

void ControladoraReserva::executar() {
    int opcao;

    do {
        cout << "\n--- GERENCIAR RESERVAS (CRUD) ---" << endl;
        cout << "1 - Realizar Nova Reserva" << endl;
        cout << "2 - Consultar Reserva (por Codigo)" << endl;
        cout << "3 - Editar Reserva" << endl;
        cout << "4 - Excluir Reserva" << endl;
        cout << "5 - Listar Reservas por Hospede" << endl;
        cout << "0 - Voltar ao Menu Gerente" << endl;
        cout << "Selecione uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1: realizarReserva(); break;
            case 2: consultarReserva(); break;
            case 3: editarReserva(); break;
            case 4: excluirReserva(); break;
            case 5: listarReservas(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
