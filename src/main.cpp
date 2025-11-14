#include <iostream>
#include<stdexcept>
#include "dominios/dominios.hpp" //juntei em dominios para ficar mais limpo -Tarsila
                                //todo novo dominio ir para dominios.hpp
#include "entidades/entidades.hpp"
#include<iomanip>


using namespace std;

int main()
{
    Data data;

    try{
        data.setData(12, "DEZ", 2017);
        cout << "Data: " << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        data.setData(30, "FEV", 2025);
        cout << "Data: " << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }

    Capacidade capacidade;

    try{
        capacidade.setValor(4);
        cout << "Capacidade: " << capacidade.getValor() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        capacidade.setValor(5);
        cout << capacidade.getValor() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }

    Endereco casinha;

    try{
        casinha.setEndereco("Pequepe, lote 21, apt. 666");
        cout << "Endereco: " << casinha.getEndereco() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        casinha.setEndereco("Pequepe, lote 21, apt. 666 ");
        cout << "Endereco: " << casinha.getEndereco() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }

    Ramal ramal;

    try{
        ramal.setValor(43);
        cout << "Ramal: " << ramal.getValor() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        ramal.setValor(55);
        cout << ramal.getValor() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }

    try{
        Codigo codigo("HotelAB123");
        cout<<"Codigo criado com sucesso: "<<codigo.getValor()<< endl;
        Codigo codigoInvalido("H@tel!");
    }catch(const invalid_argument &exp){
        cout<<"Erro ao criar codigo: "<<exp.what()<<endl;
    }

    try{
        Email email("nome123@gmail.com");
        cout<<"Email criado: "<<email.getEmail()<<endl;
    } catch(const invalid_argument& exp){
        cout<<"Erro: "<<exp.what()<<endl;
    }
    try{
        Email email_invalido(".comeca@componto.com");
    }catch(const invalid_argument &exp){
        cout<<"Erro: "<< exp.what()<<endl;
    }

    try{
        Numero numero(20);
        cout<<"Numero cadastrado com sucesso: "<< numero.getValor()<<endl;
        Numero numeroInvalido(1000);
    }
     catch(const invalid_argument&exp){
        cout<<"Erro: "<<exp.what()<<endl;
        }

    try{
        Telefone telefone("+61996098513");
        cout<<"Telefone cadastrado: "<<telefone.getValor()<<endl;
        Telefone telefoneInvalido("*61996098513");
    }catch(const invalid_argument&exp){
        cout<<"Erro: "<<exp.what()<<endl;
    }

    Cartao cartao;

    try{
        cartao.setValor("5423573294061746");
        cout<<"Cartao cadastrado"<<cartao.getValor()<<endl;
        //Cartao cartao_invalido("1234567891011122");
    }catch(const invalid_argument&exp){
        cout<<"Erro: "<<exp.what()<<endl;
    }

    Dinheiro dinheiro;

    try{
        //Dinheiro dinheiro(868000.85);
        dinheiro.setValor(8680.85);
        cout<<"Dinheiro armazenado: "<<dinheiro.getValor()<<endl;
        //Dinheiro dinheiroInvalido(0.0);
    }catch(const invalid_argument&exp){
        cout<<"Erro: "<<exp.what()<<endl;
    }

    Nome nome;

    try{
        nome.setNome("Abigail Silva");
        cout << nome.getNome() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        nome.setNome("Abigail  Silva");
        cout << nome.getNome() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }

    Senha senha;

    try{
        senha.setSenha("S3s%$");
        cout << senha.getSenha() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }
    try{
        senha.setSenha("SSSSS");
        cout << senha.getSenha() << endl;
    }
    catch(invalid_argument &exp){
        cout << "Erro: " << exp.what() << endl;
    }


    // --- Teste das Classes de Entidade ---

    cout << "\n--- TESTE DAS ENTIDADES ---\n";

    // 1. CENÁRIO DE SUCESSO: Instanciar e atribuir Gerente
    try {
        Gerente g;
        Nome nomeGerente;
        Email emailGerente;
        Ramal ramalGerente;
        Senha senhaGerente;

        // Define Domínios válidos
        nomeGerente.setNome("Jairo Gerente");
        emailGerente.setEmail("jairo@hotel.com");
        ramalGerente.setValor(15);
        senhaGerente.setSenha("G4r%$"); // Assumindo este é válido

        // Atribui Domínios à Entidade (Pessoa e Gerente)
        g.setNome(nomeGerente);
        g.setEmail(emailGerente);
        g.setRamal(ramalGerente);
        g.setSenha(senhaGerente);

        cout << "Gerente criado e configurado com sucesso:\n";
        cout << " - Nome: " << g.getNome().getNome() << endl;
        cout << " - Ramal: " << g.getRamal().getValor() << endl;

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO no Gerente (Sucesso): " << exp.what() << endl;
    }

    // 2. CENÁRIO DE FALHA: Testar a propagação da exceção do Domínio (Hóspede)
    try {
        Hospede h;
        Endereco enderecoHospede;
        Cartao cartaoHospede;

        // Tenta atribuir um Endereço Inválido (começando/terminando com espaço)
        // Assume que a validação de Endereco.cpp falhará aqui
        enderecoHospede.setEndereco("Rua 1, Apto 2 ");

        // Se a linha acima for bem-sucedida, o código abaixo será executado
        cout << "ERRO: Endereço inválido foi aceito!\n";

    } catch (const invalid_argument& exp) {
        cout << "Hospede: Exceção de Endereco capturada com sucesso: " << exp.what() << endl;
    }

    // 3. CENÁRIO DE SUCESSO: Instanciar Hóspede completo
    try {
        Hospede h2;
        Nome nomeHospede;
        Endereco endHospede;
        Cartao cartaoHospede;

        // Define Domínios válidos
        nomeHospede.setNome("Maria Hospede");
        endHospede.setEndereco("Rua 1, Apto 2");
        cartaoHospede.setValor("5423573294061746"); // Assumindo Luhn válido

        // Atribui Domínios à Entidade
        h2.setNome(nomeHospede);
        h2.setEndereco(endHospede);
        h2.setCartao(cartaoHospede);

        cout << "Hospede 2 criado e configurado com sucesso: " << h2.getNome().getNome() << endl;

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO no Hospede (Sucesso): " << exp.what() << endl;
    }

    // --- Fim dos Testes de Entidades ---



    return 0;

}
