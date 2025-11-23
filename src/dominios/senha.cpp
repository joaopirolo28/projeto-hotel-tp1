#include "dominios/senha.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


void Senha::validar(string valor) {
    if (valor.length() != 5) {
        throw invalid_argument("Tamanho incorreto. A senha deve ter 5 caracteres.");
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;


    const string especiais = "!\"#$%&?";


    int seqTracker = 0;

    for (size_t i = 0; i < valor.length(); ++i) {
        char c = valor[i];

        if (isalpha(c)) {
            if (seqTracker == 1) {
                throw invalid_argument("Letra nao pode ser seguida por outra letra.");
            }
            if (isupper(c)) hasUpper = true;
            else hasLower = true;
            seqTracker = 1;
        }
        else if (isdigit(c)) {
            if (seqTracker == 2) {
                throw invalid_argument("Digito nao pode ser seguido por outro digito.");
            }
            hasDigit = true;
            seqTracker = 2;
        }
        else if (especiais.find(c) != string::npos) {
            hasSpecial = true;
            seqTracker = 0;
        }
        else {
            throw invalid_argument("Caracter invalido ou nao permitido na sequencia.");
        }
    }


    if (!hasUpper) throw invalid_argument("A senha deve ter pelo menos uma maiuscula.");
    if (!hasLower) throw invalid_argument("A senha deve ter pelo menos uma minuscula.");
    if (!hasDigit) throw invalid_argument("A senha deve ter pelo menos um digito.");
    if (!hasSpecial) throw invalid_argument("A senha deve ter pelo menos um caractere especial.");
}

void Senha::setSenha(string valor) {
    validar(valor);
    this->senha = valor;
}

Senha::Senha() {}

Senha::Senha(string valor) {
    this->setSenha(valor);
}
