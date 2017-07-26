#ifndef P3_T2_DOCENTE_H
#define P3_T2_DOCENTE_H

#include "Publicacao.h"

using namespace std;

class Publicacao;

class Docente {
private:
    string codigo;
    string nome;
    time_t dataNascimento;
    time_t dataIngresso;
    bool coordenador;
    vector<Publicacao*> publicacoes;

public:
    Docente(string codigo, string nome, bool coordenador, time_t dataNascimento, time_t dataIngresso);
    void adicionarPublicacao(Publicacao *publicacao);
    string getNome();
    bool isCoordenador();
    bool lessThreeYears(time_t ano);
    bool isOverSixty(time_t ano);
};


#endif //P3_T2_DOCENTE_H
