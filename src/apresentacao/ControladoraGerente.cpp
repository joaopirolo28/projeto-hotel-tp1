#include "apresentacao/ControladoraGerente.hpp"
#include "apresentacao/IControladoraHotel.hpp"
#include "interfaces/interfaces.hpp"

#include <iostream>
#include <limits>

using namespace std;

ControladoraGerente::ControladoraGerente(
    std::unique_ptr<IServicoHotel> sHotel,
    std::unique_ptr<IServicoQuarto> sQuarto,
    IControladoraHotel* cHotel,
    IControladoraQuarto* cQuarto)
    : servicoHotel(std::move(sHotel)),
      servicoQuarto(std::move(sQuarto)),
      controladoraHotel(cHotel),
      controladoraQuarto(cQuarto)
{ }

// Menu Principal do Gerente
void ControladoraGerente::executar() {
    int opcao;

    do {
        cout << "\n--- MENU GERENTE ---" << endl;
        cout << "1 - Gerenciar Hoteis" << endl;
        cout << "2 - Gerenciar Quartos" << endl;
        cout << "3 - Gerenciar Hospedes" << endl;
        cout << "4 - Gerenciar Reservas" << endl;
        cout << "0 - Logout / Retornar" << endl;
        cout << "Selecione uma opcao: ";

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao) {
            case 1:
                controladoraHotel->executar();
                break;
            case 2:
                controladoraQuarto->executar();
                break;
            case 0:
                cout << "Retornando ao Menu Principal (Logout)..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
}
