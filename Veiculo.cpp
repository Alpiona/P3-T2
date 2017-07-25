#include "Veiculo.h"

Veiculo::Veiculo(){}

Veiculo::Veiculo(string sigla, string nome, char tipo, double fatorDeImpacto, string ISSN) {
    this->sigla = sigla;
    this->nome = nome;
    this->tipo = tipo;
    this->fatorDeImpacto = fatorDeImpacto;
    this->ISSN = ISSN;
}
