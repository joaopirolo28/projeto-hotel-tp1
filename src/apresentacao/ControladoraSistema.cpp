#include "apresentacao/ControladoraSistema.hpp"
#include <iostream>
#include <memory>

using namespace std;

ControladoraSistema::ControladoraSistema(FabricaServico* f) : fabrica(f), ControladoraAutenticacao(nullptr){
    carregarControladoras();
}

void ControladoraSistema::carregarControladoras(){
    // A Fabrica cria a implementacao do Serviao Autenticacao e a injeta na Controladora.

    // 1. OBTeM O SERVIcO: Usa a Fabrica para obter a interface ILNAutenticacao*
    IServicoAutenticacao* servicoAutenticacao = fabrica->criarServicoAutenticacao();

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
    // Fluxo principal de execucao do sistema

    cout << "\n--- SISTEMA DE GESTAO DE HOTEIS ---\n";

    // 1. Tenta fazer o Login/Cadastro
    // emailGerenteLogado = controladoraAutenticacao->executar();

    // 2. Se o Login foi bem-sucedido, apresenta o Menu Principal
    // if (!emailGerenteLogado.empty()) {
    //    apresentarMenuPrincipal();
    // }
}

void ControladoraSistema::apresentarMenuPrincipal() {
    cout << "\nBem-vindo(a), Gerente " << emailGerenteLogado << "!\n";
    // Logica para apresentar o menu principal (CRUDs)
}
