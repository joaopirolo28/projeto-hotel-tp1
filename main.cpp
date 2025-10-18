#include <iostream>
#include<stdexcept>
#include "dominios.hpp" //juntei em dominios para ficar mais limpo -Tarsila
//todo novo dominio ir para dominios.hpp
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
        Email email("nome-123@gmail.com");
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

    try{
        Cartao cartao("5423573294061746");
        cout<<"Cartao cadastrado"<<cartao.getValor()<<endl;
        Cartao cartao_invalido("1234567891011122");
    }catch(const invalid_argument&exp){
        cout<<"Erro: "<<exp.what()<<endl;
    }

    try{
        Dinheiro dinheiro(868000.85);
        cout<<"Dinheiro armazenado"<<dinheiro.getValor()<<endl;
        Dinheiro dinheiroInvalido(0.0);
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
    
    return 0;

}
