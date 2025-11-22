#include "apresentacao/ControladoraAutenticacao.hpp"
#include "dominios/dominios.hpp"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ControladoraAutenticacao::ControladoraAutenticacao(
    std::unique_ptr<IServicoAutenticacao> servicoAuth,
    std::unique_ptr<IServicoGerente> servicoGerente)
    : servicoAutenticacao(std::move(servicoAuth)),
      servicoGerente(std::move(servicoGerente))
{
    // O construtor está vazio, mas inicializa os membros corretamente
}

void ControladoraAutenticacao::solicitarCadastro() {
    std::cout << "\n--- CADASTRO DE GERENTE ---" << std::endl;

    string emailStr, nomeStr, ramalStr, senhaStr;

    cout << "Nome: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nomeStr);

    cout << "Email (Chave Primaria): ";
    cin >> emailStr;

    cout << "Ramal: ";
    cin >> ramalStr;

    cout << "Senha (5 caracteres, maiuscula/minuscula/digito/especial): ";
    cin >> senhaStr;

    try{
        Email email(emailStr);
        Nome nome(nomeStr);
        Ramal ramal(stoi(ramalStr));
        Senha senha(senhaStr);

        Gerente novoGerente;
        novoGerente.setEmail(email);
        novoGerente.setNome(nome);
        novoGerente.setRamal(ramal);
        novoGerente.setSenha(senha);

        if(servicoGerente->cadastrarGerente(novoGerente)){
            cout << "\n Gerente cadastrado com sucesso!" << endl;
        }else{
            cout << "\n Falha ao cadastrar. O email pode ja estar em uso." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "\n ERRO DE FORMATO: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        cout << "\n ERRO NO CADASTRO: " << e.what() << std::endl;
    }
    // Para simplificar, por enquanto, apenas simule o processo.
    // A logica completa de coleta de dados de Nome, Ramal, Email, Senha e chamada ao
    // IServicoGerente precisa ser implementada aqui.
    std::cout << "Funcionalidade de Cadastro pendente de implementacao completa." << std::endl;
}

std::string ControladoraAutenticacao::solicitarLogin() {
    std::string emailStr, senhaStr;

    std::cout << "\n--- LOGIN ---" << std::endl;
    std::cout << "Email: ";
    std::cin >> emailStr;
    std::cout << "Senha: ";
    std::cin >> senhaStr;

    try {
        // Validação de Domínio (Requisito 4.6): Tenta criar o objeto Domínio.
        // Se o formato for inválido, o construtor lança std::invalid_argument.
        Email email(emailStr);
        Senha senha(senhaStr);

        // Chamada ao Serviço (Camada de Negócio):
        if (servicoAutenticacao->autenticar(email, senha)) {
            std::cout << "\n Login realizado com sucesso! " << std::endl;
            return email.getEmail(); // Retorna o email em caso de sucesso
        } else {
            std::cout << "\n Credenciais invalidas ou Gerente nao encontrado." << std::endl;
        }

    } catch (const std::invalid_argument& e) {
        // Captura e exibe erro de formato
        std::cout << "\n ERRO DE FORMATO: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        // Captura e exibe erro de sistema/persistência
        std::cout << "\n ERRO NO SISTEMA: " << e.what() << std::endl;
    }

    return ""; // Login falhou
}

std::string ControladoraAutenticacao::executar() {
    int opcao;
    std::string emailLogado = "";

    do {
        std::cout << "\n--- MENU INICIAL ---" << std::endl;
        std::cout << "1 - Login Gerente" << std::endl;
        std::cout << "2 - Cadastrar Gerente" << std::endl;
        std::cout << "0 - Sair do Sistema" << std::endl;
        std::cout << "Selecione uma opcao: ";

        // Tratamento simples de erro de entrada (ignorado por simplicidade de console)
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                emailLogado = solicitarLogin();
                if (!emailLogado.empty()) return emailLogado; // Login bem-sucedido, retorna o email
                break;
            case 2:
                solicitarCadastro();
                break;
            case 0:
                std::cout << "Encerrando o sistema." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    } while (opcao != 0);

    return ""; // Retorna string vazia se o usuário sair
}
