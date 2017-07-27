#include "Qualis.h"

using namespace std;

Qualis::Qualis(int ano, string qualis) {
    this->ano = ano;
    this->qualis = qualis;
}

void Qualis::setRegra(RegraPontuacao regra) {this->regra = regra;}