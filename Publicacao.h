#ifndef P3_T2_PUBLICACAO_H
#define P3_T2_PUBLICACAO_H

#include <string>
#include <vector>
#include "Veiculo.h"
#include "Docente.h"

using namespace std;

class Publicacao {
private:
    int numero;
    int ano;
    int pgInicial, pgFinal;
    string titulo;
    Veiculo veiculo;
    vector<Docente> autores;
    string qualis;

public:
    Publicacao();
    Publicacao(int numero, int ano, int pgInicial, int pgFinal, Veiculo veiculo, vector<Docente> autores, string titulo);
    void setQualis (string qualis);
};


#endif //P3_T2_PUBLICACAO_H