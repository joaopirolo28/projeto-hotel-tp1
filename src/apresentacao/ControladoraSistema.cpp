#include "apresentacao/ControladoraSistema.hpp"
#include <iostream>
#include <memory>

using namespace std;

ControladoraSistema::ControladoraSistema(FabricaServico* f) : fabrica(f), ControladoraAutenticacao(nullptr){
    carregarControladoras();
}

void ControladoraSistema::carregarControladoras(){
    // A Fábrica cria a implementação do Serviço Autenticação e a injeta na Controladora.

    // 1. OBTÉM O SERVIÇO: Usa a Fábrica para obter a interface ILNAutenticacao*
    ILNAutenticacao* servicoAutenticacao = fabrica->criarServicoAutenticacao();

    // 2. CRIA A CONTROLADORA: Cria a Controladora de Autenticação, injetando o serviço.
    // Usamos 'new' aqui, e a Controladora Geral será responsável por deletar o serviço.

    // NOTA: Para simplificar o gerenciamento de memória no C++, o ServicoAutenticacao é alocado com new na Fábrica.
    // A ControladoraAutenticacao precisa ser ajustada para receber ILNAutenticacao*

    // Exemplo ajustado (Assumindo que ControladoraAutenticacao.hpp foi alterada para receber o ponteiro raw):
    // controladoraAutenticacao = new ControladoraAutenticacao(servicoAutenticacao);

    // Vamos usar a injeção via smart pointer (unique_ptr) que você já estava usando, mas adaptando o fluxo da Fábrica.
    // No seu caso: ServicoAutenticacao recebe unique_ptr, mas a Fábrica retorna um ponteiro raw (ILNAutenticacao*).

    // Vamos usar um construtor que aceita o ponteiro raw para simplificar o fluxo de delete:
    // **É NECESSÁRIO AJUSTAR O CONSTRUTOR DE ControladoraAutenticacao.hpp para aceitar ILNAutenticacao* raw pointer**

    // Por enquanto, apenas inicializamos a controladora de Autenticação
    // O fluxo real depende da Controladora Autenticacao ser capaz de receber o serviço corretamente.

    // Para simplificar o teste, vamos criar o Servico Autenticacao como ponteiro raw para facilitar o delete.
}

void ControladoraSistema::executar() {
    // Fluxo principal de execução do sistema

    cout << "\n--- SISTEMA DE GESTÃO DE HOTÉIS ---\n";

    // 1. Tenta fazer o Login/Cadastro
    // emailGerenteLogado = controladoraAutenticacao->executar();

    // 2. Se o Login foi bem-sucedido, apresenta o Menu Principal
    // if (!emailGerenteLogado.empty()) {
    //    apresentarMenuPrincipal();
    // }
}

void ControladoraSistema::apresentarMenuPrincipal() {
    cout << "\nBem-vindo(a), Gerente " << emailGerenteLogado << "!\n";
    // Lógica para apresentar o menu principal (CRUDs)
}
