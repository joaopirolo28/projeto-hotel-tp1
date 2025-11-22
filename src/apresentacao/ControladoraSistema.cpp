#include "apresentacao/ControladoraSistema.hpp"
#include "apresentacao/ControladoraAutenticacao.hpp"
#include "interfaces/interfaces.hpp"
#include "dominios/dominios.hpp"
#include "servico/FabricaServico.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

ControladoraSistema::ControladoraSistema(FabricaServico* f) : fabrica(f), controladoraAutenticacao(nullptr){
    carregarControladoras();
}

void ControladoraSistema::carregarControladoras(){

    IServicoAutenticacao* servicoRawAuth = fabrica->criarServicoAutenticacao();
    IServicoGerente* servicoRawGerente = fabrica->criarServicoGerente();

    std::unique_ptr<IServicoAutenticacao> temp_unique_auth(servicoRawAuth);
    std::unique_ptr<IServicoGerente> temp_unique_gerente(servicoRawGerente);


    //controladoraAutenticacao = new ControladoraAutenticacao(std::move(temp_unique));
    controladoraAutenticacao = new ControladoraAutenticacao(move(temp_unique_auth), move(temp_unique_gerente));

    // 2. CRIA A CONTROLADORA: Cria a Controladora de Autenticacao, injetando o servico.
    // Usamos 'new' aqui, e a Controladora Geral sera responsavel por deletar o servico.

    // NOTA: Para simplificar o gerenciamento de memoria no C++, o ServicoAutenticacao a alocado com new na Fabrica.
    // A ControladoraAutenticacao precisa ser ajustada para receber ILNAutenticacao*

    // Exemplo ajustado (Assumindo que ControladoraAutenticacao.hpp foi alterada para receber o ponteiro raw):
    // controladoraAutenticacao = new ControladoraAutenticacao(servicoAutenticacao);

    // Vamos usar a injejao via smart pointer (unique_ptr) que voce ja estava usando, mas adaptando o fluxo da Fabrica.
    // No seu caso: ServicoAutenticacao recebe unique_ptr, mas a Fabrica retorna um ponteiro raw (ILNAutenticacao*).

    // Vamos usar um construtor que aceita o ponteiro raw para simplificar o fluxo de delete:
    // ** NECESSaRIO AJUSTAR O CONSTRUTOR DE ControladoraAutenticacao.hpp para aceitar ILNAutenticacao* raw pointer**

    // Por enquanto, apenas inicializamos a controladora de Autenticacao
    // O fluxo real depende da Controladora Autenticacao ser capaz de receber o servico corretamente.

    // Para simplificar o teste, vamos criar o Servico Autenticacao como ponteiro raw para facilitar o delete.
}

void ControladoraSistema::executar() {

    cout << "\n--- SISTEMA DE GESTAO DE HOTEIS ---\n";

    emailGerenteLogado = controladoraAutenticacao->executar();

    if (!emailGerenteLogado.empty()) {
        apresentarMenuPrincipal();
    }else{
        std::cout << "Nenhum gerente logado. Encerrando o sistema." << std::endl;
    }
}

void ControladoraSistema::apresentarMenuPrincipal() {
    cout << "\nBem-vindo(a), Gerente " << emailGerenteLogado << "!\n";
    // Logica para apresentar o menu principal (CRUDs)
    cout << "Logado com sucesso. Logica do Meno Principal Gerente Pendente." << endl;
}
