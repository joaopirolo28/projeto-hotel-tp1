#include "apresentacao/ControladoraAutenticacao.hpp"
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include <utility>

using namespace std;

// --- Construtor ---
ControladoraAutenticacao::ControladoraAutenticacao(
    std::unique_ptr<IServicoAutenticacao> servicoAuth,
    std::unique_ptr<IServicoGerente> servicoGerente)
    : servicoAutenticacao(std::move(servicoAuth)),
      servicoGerente(std::move(servicoGerente))
{

}

// --- Logica de Cadastro  ---
void ControladoraAutenticacao::solicitarCadastro() {
    std::cout << "\n--- CADASTRO DE GERENTE ---" << std::endl;

    string emailStr, nomeStr, ramalStr, senhaStr;
    Gerente novoGerente;
    bool cadastro_sucesso = false;


    while (!cadastro_sucesso) {
        try {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // 1. COLETAR ENTRADAS
            cout << "Nome (Primeira letra maiuscula): ";
            getline(std::cin, nomeStr);

            cout << "Email (Chave Primaria): ";
            std::cin >> emailStr;

            cout << "Ramal: ";
            std::cin >> ramalStr;

            cout << "Senha (5 caracteres. Pelo menos um caractere maiuscula, minuscula, digito e especial): ";
            std::cin >> senhaStr;

            
            Email email(emailStr);
            Nome nome(nomeStr);
            Ramal ramal(stoi(ramalStr));
            Senha senha(senhaStr);

           
            novoGerente.setEmail(email);
            novoGerente.setNome(nome);
            novoGerente.setRamal(ramal);
            novoGerente.setSenha(senha);

            
            if(servicoGerente->cadastrarGerente(novoGerente)){
                cout << "\n Gerente cadastrado com sucesso!" << endl;
                cadastro_sucesso = true;
            }else{
                cout << "\n Falha ao cadastrar. O email pode ja estar em uso." << endl;
                cadastro_sucesso = true;
            }

        } catch (const invalid_argument& e) {
            
            cout << "\n ERRO DE FORMATO: " << e.what() << std::endl;
            cout << "Por favor, tente novamente com os dados corrigidos." << endl;
        } catch (const std::runtime_error& e) {
            
            cout << "\n ERRO NO CADASTRO: " << e.what() << std::endl;
            cadastro_sucesso = true;
        }
    }
}

// --- Logica de Login e Execucao Principal ---
std::string ControladoraAutenticacao::solicitarLogin() {
    std::string emailStr, senhaStr;

    std::cout << "\n--- LOGIN ---\n";
    std::cout << "Email: ";
    std::cin >> emailStr;
    std::cout << "Senha: ";
    std::cin >> senhaStr;

    try {
        Email email(emailStr);
        Senha senha(senhaStr);

        
        if (servicoAutenticacao->autenticar(email, senha)) {

            // 2. BUSCA O OBJETO GERENTE COMPLETO PARA PEGAR O NOME

            Gerente gerenteLogado = servicoGerente->consultarGerente(email);

            // 3. EXIBE A MENSAGEM PERSONALIZADA (NOME)
            std::cout << "\n Login realizado com sucesso! Bem-vindo(a), Gerente "
                      << gerenteLogado.getNome().getNome() << "." << std::endl;

            // 4. RETORNA O EMAIL para o fluxo principal
            return email.getEmail();
        } else {
            std::cout << "\n Credenciais invalidas ou Gerente nao encontrado." << std::endl;
        }

    } catch (const invalid_argument& e) {
        std::cout << "\n ERRO DE FORMATO: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        
        std::cout << "\n ERRO NO SISTEMA: Gerente nao encontrado na base de dados. " << std::endl;
    }

    return "";
}

std::string ControladoraAutenticacao::executar() {
    int opcao;
    std::string emailLogado = "";

    do {
        std::cout << "\n--- MENU INICIAL ---\n";
        std::cout << "1 - Login Gerente\n";
        std::cout << "2 - Cadastrar Gerente\n";
        std::cout << "0 - Sair do Sistema\n";
        std::cout << "Selecione uma opcao: ";

        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                emailLogado = solicitarLogin();
                if (!emailLogado.empty()) return emailLogado;
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

    return "";
}
