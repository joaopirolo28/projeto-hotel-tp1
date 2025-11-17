#include <iostream>
#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include <iomanip>
#include "servico/FabricaServicoImpl.hpp"

using namespace std;

int main()
{
    Data data;

    try {
        data.setData(12, "DEZ", 2017);
        cout << "Data: " << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        data.setData(30, "FEV", 2025);
        cout << "Data: " << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Capacidade capacidade;

    try {
        capacidade.setValor(4);
        cout << "Capacidade: " << capacidade.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        capacidade.setValor(5);
        cout << capacidade.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Endereco casinha;

    try {
        casinha.setEndereco("Pequepe, lote 21, apt. 666");
        cout << "Endereco: " << casinha.getEndereco() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        casinha.setEndereco("Pequepe, lote 21, apt. 666 ");
        cout << "Endereco: " << casinha.getEndereco() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Ramal ramal;

    try {
        ramal.setValor(43);
        cout << "Ramal: " << ramal.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        ramal.setValor(55);
        cout << ramal.getValor() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    try {
        Codigo codigo("HotelAB123");
        cout << "Codigo criado com sucesso: " << codigo.getValor() << endl;
        Codigo codigoInvalido("H@tel!");
    } catch(const invalid_argument &exp) {
        cout << "Erro ao criar codigo: " << exp.what() << endl;
    }

    try {
        Email email("nome123@gmail.com");
        cout << "Email criado: " << email.getEmail() << endl;
    } catch(const invalid_argument& exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        Email email_invalido(".comeca@componto.com");
    } catch(const invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    try {
        Numero numero(20);
        cout << "Numero cadastrado com sucesso: " << numero.getValor() << endl;
        Numero numeroInvalido(1000);
    }
    catch(const invalid_argument& exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    try {
        Telefone telefone("+61996098513");
        cout << "Telefone cadastrado: " << telefone.getValor() << endl;
        Telefone telefoneInvalido("*61996098513");
    } catch(const invalid_argument& exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Cartao cartao;

    try {
        cartao.setValor("5423573294061746");
        cout << "Cartao cadastrado" << cartao.getValor() << endl;
    } catch(const invalid_argument& exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Dinheiro dinheiro;

    try {
        dinheiro.setValor(8680.85);
        cout << "Dinheiro armazenado: " << dinheiro.getValor() << endl;
    } catch(const invalid_argument& exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Nome nome;

    try {
        nome.setNome("Abigail Silva");
        cout << nome.getNome() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        nome.setNome("Abigail  Silva");
        cout << nome.getNome() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    Senha senha;

    try {
        senha.setSenha("S3s%$");
        cout << senha.getSenha() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }
    try {
        senha.setSenha("SSSSS");
        cout << senha.getSenha() << endl;
    }
    catch(invalid_argument &exp) {
        cout << "Erro: " << exp.what() << endl;
    }

    cout << "\n--- TESTE DAS ENTIDADES ---\n";

    try {
        Gerente g;
        Nome nomeGerente;
        Email emailGerente;
        Ramal ramalGerente;
        Senha senhaGerente;

        nomeGerente.setNome("Jairo Gerente");
        emailGerente.setEmail("jairo@hotel.com");
        ramalGerente.setValor(15);
        senhaGerente.setSenha("G4r%$");

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

    try {
        Hospede h;
        Endereco enderecoHospede;
        Cartao cartaoHospede;

        enderecoHospede.setEndereco("Rua 1, Apto 2 ");

        cout << "ERRO: Endereco invalido foi aceito!\n";

    } catch (const invalid_argument& exp) {
        cout << "Hospede: Excecao de Endereco capturada com sucesso: " << exp.what() << endl;
    }

    try {
        Hospede h2;
        Nome nomeHospede;
        Endereco endHospede;
        Cartao cartaoHospede;

        nomeHospede.setNome("Maria Hospede");
        endHospede.setEndereco("Rua 1, Apto 2");
        cartaoHospede.setValor("5423573294061746");

        h2.setNome(nomeHospede);
        h2.setEndereco(endHospede);
        h2.setCartao(cartaoHospede);

        cout << "Hospede 2 criado e configurado com sucesso: " << h2.getNome().getNome() << endl;
        if (h2.getEndereco().getEndereco() != "Rua 1, Apto 2") {
             cout << "FALHA NO GET/SET DE ENDERECO DO HOSPEDE!" << endl;
        }

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO no Hospede (Sucesso): " << exp.what() << endl;
    }

    cout << "\n--- TESTE DA ENTIDADE HOTEL ---\n";

    try {
        Hotel h;
        Nome nomeHotel;
        Endereco enderecoHotel;
        Telefone telefoneHotel;
        Codigo codigoHotel;

        nomeHotel.setNome("Grand Palace Hotel");
        enderecoHotel.setEndereco("Avenida Principal, 100");
        telefoneHotel.setValor("+5561987654321");
        codigoHotel.setValor("HOTEL123AB");

        h.setNome(nomeHotel);
        h.setEndereco(enderecoHotel);
        h.setTelefone(telefoneHotel);
        h.setCodigo(codigoHotel);

        cout << "Hotel criado com sucesso:\n";
        cout << " - Nome: " << h.getNome().getNome() << endl;
        cout << " - Codigo: " << h.getCodigo().getValor() << endl;

        if(h.getEndereco().getEndereco() != "Avenida Principal, 100") {
             cout << "FALHA NO GET/SET DE ENDERECO DO HOTEL!" << endl;
        }

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO no Hotel (Sucesso): " << exp.what() << endl;
    }

    try {
        Hotel h_falha;
        Telefone tel_invalido;

        tel_invalido.setValor("*5561987654321");

        h_falha.setTelefone(tel_invalido);
        cout << "ERRO: Hotel aceitou Telefone invalido!\n";

    } catch (const invalid_argument& exp) {
        cout << "Hotel: Excecao de Telefone capturada com sucesso: " << exp.what() << endl;
    }

    cout << "\n--- TESTE DA ENTIDADE QUARTO ---\n";

    try {
        Quarto q;
        Numero numeroQuarto;
        Capacidade capacidadeQuarto;
        Dinheiro diariaQuarto;
        Ramal ramalQuarto;

        numeroQuarto.setValor(501);
        capacidadeQuarto.setValor(2);
        diariaQuarto.setValor(350.50);
        ramalQuarto.setValor(10);

        q.setNumero(numeroQuarto);
        q.setCapacidade(capacidadeQuarto);
        q.setDiaria(diariaQuarto);
        q.setRamal(ramalQuarto);

        cout << "Quarto criado com sucesso:\n";
        cout << " - Numero: " << q.getNumero().getValor() << endl;
        cout << " - Diaria: " << fixed << setprecision(2) << q.getDiaria().getValor() << endl;

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO no Quarto (Sucesso): " << exp.what() << endl;
    }

    cout << "\n--- TESTE DA ENTIDADE RESERVA ---\n";

    try {
        Reserva r;
        Data chegada;
        Data partida;
        Dinheiro valorReserva;
        Codigo codigoReserva;

        chegada.setData(10, "DEZ", 2025);
        partida.setData(15, "DEZ", 2025);
        valorReserva.setValor(1500.00);
        codigoReserva.setValor("RESV777XAB");

        r.setChegada(chegada);
        r.setPartida(partida);
        r.setValor(valorReserva);
        r.setCodigo(codigoReserva);

        cout << "Reserva criada com sucesso:\n";
        cout << " - Chegada: " << r.getChegada().getDia() << "/" << r.getChegada().getMes() << endl;
        cout << " - Valor: " << fixed << setprecision(2) << r.getValor().getValor() << endl;

    } catch (const invalid_argument& exp) {
        cout << "ERRO INESPERADO na Reserva (Sucesso): " << exp.what() << endl;
    }

    cout << "\n--- TESTE FABRICA ---\n";

    FabricaServicoImpl fabrica;

    ILNAutenticacao* servicoAutenticacao = fabrica.criarServicoAutenticacao();

    delete servicoAutenticacao;

    return 0;
}
