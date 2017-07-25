#ifndef P3_T2_VEICULO_H
#define P3_T2_VEICULO_H

#include <vector>
#include "Qualis.h"

using namespace std;

class Veiculo {
private:
    string sigla;
    string nome;
    char tipo;
    double fatorDeImpacto;
    string ISSN;
    vector<Qualis> listaQualis;

public:
    Veiculo(string sigla, string nome, char tipo, double fatorDeImpacto, string ISSN);
};


#endif //P3_T2_VEICULO_H
