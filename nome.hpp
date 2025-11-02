/**
 * @file Nome.hpp
 * @brief Definição da classe de domínio Nome.
 * @author Tarsila Marques
 * @date 18 de outubro de 2025
 */

#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

/**
 * @brief Classe para armazenar e validar um nome de pessoa.
 * @details O nome deve seguir as seguintes regras de formatação:
 * - Ter entre 5 e 20 caracteres.
 * - Conter apenas letras e espaços.
 * - Cada termo (palavra) deve começar com letra maiúscula.
 * - Não pode haver espaços em sequência.
 * - O primeiro e o último caractere não podem ser espaços.
 */
class Nome {
private:
    /**
     * @brief Armazena o valor do nome.
     */
    string nome;

    /**
     * @brief Valida um nome de acordo com as regras de negócio.
     * @param nome A string contendo o nome a ser validado.
     * @throw invalid_argument se o nome for inválido.
     */
    void validar(string nome);

public:
    /**
     * @brief Retorna o valor do nome.
     * @return Uma string contendo o nome armazenado.
     */
    string getNome();

    /**
     * @brief Define o valor do nome após validá-lo.
     * @param nome A string contendo o nome a ser definido.
     * @throw invalid_argument Se o nome não atender aos critérios de validação.
     */
    void setNome(string nome);
};

/**
 * @brief Implementação inline do método getNome.
 * @return O valor do atributo 'nome' da classe.
 */
inline string Nome::getNome() {
    return nome;
}

#endif // NOME_HPP_INCLUDED