#include "apresentacao/ControladoraSistema.hpp"
#include <iostream>
#include <memory>

using namespace std;

ControladoraSistema::ControladoraSistema(FabricaServico* f) : fabrica(f), ControladoraAutenticacao(nullptr){
    carregarControladoras();
}

void ControladoraSistema::carregarControladoras(){
    // A F�brica cria a implementa��o do Servi�o Autentica��o e a injeta na Controladora.

    // 1. OBT�M O SERVI�O: Usa a F�brica para obter a interface ILNAutenticacao*
    IServicoAutenticacao* servicoAutenticacao = fabrica->criarServicoAutenticacao();

    // 2. CRIA A CONTROLADORA: Cria a Controladora de Autentica��o, injetando o servi�o.
    // Usamos 'new' aqui, e a Controladora Geral ser� respons�vel por deletar o servi�o.

    // NOTA: Para simplificar o gerenciamento de mem�ria no C++, o ServicoAutenticacao � alocado com new na F�brica.
    // A ControladoraAutenticacao precisa ser ajustada para receber ILNAutenticacao*

    // Exemplo ajustado (Assumindo que ControladoraAutenticacao.hpp foi alterada para receber o ponteiro raw):
    // controladoraAutenticacao = new ControladoraAutenticacao(servicoAutenticacao);

    // Vamos usar a inje��o via smart pointer (unique_ptr) que voc� j� estava usando, mas adaptando o fluxo da F�brica.
    // No seu caso: ServicoAutenticacao recebe unique_ptr, mas a F�brica retorna um ponteiro raw (ILNAutenticacao*).

    // Vamos usar um construtor que aceita o ponteiro raw para simplificar o fluxo de delete:
    // **� NECESS�RIO AJUSTAR O CONSTRUTOR DE ControladoraAutenticacao.hpp para aceitar ILNAutenticacao* raw pointer**

    // Por enquanto, apenas inicializamos a controladora de Autentica��o
    // O fluxo real depende da Controladora Autenticacao ser capaz de receber o servi�o corretamente.

    // Para simplificar o teste, vamos criar o Servico Autenticacao como ponteiro raw para facilitar o delete.
}

void ControladoraSistema::executar() {
    // Fluxo principal de execu��o do sistema

    cout << "\n--- SISTEMA DE GEST�O DE HOT�IS ---\n";

    // 1. Tenta fazer o Login/Cadastro
    // emailGerenteLogado = controladoraAutenticacao->executar();

    // 2. Se o Login foi bem-sucedido, apresenta o Menu Principal
    // if (!emailGerenteLogado.empty()) {
    //    apresentarMenuPrincipal();
    // }
}

void ControladoraSistema::apresentarMenuPrincipal() {
    cout << "\nBem-vindo(a), Gerente " << emailGerenteLogado << "!\n";
    // L�gica para apresentar o menu principal (CRUDs)
}
