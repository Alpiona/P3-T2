#ifndef P3_T2_DOCENTE_H
#define P3_T2_DOCENTE_H

#include "Publicacao.h"

using namespace std;

class Publicacao;

class Docente {
private:
    string codigo;
    string nome;
    //Date dataNascimento;
    //Date dataIngresso;
    bool coordenador;
    vector<Publicacao*> publicacoes;

public:
    Docente(string codigo, string nome, bool coordenador);
    void adicionarPublicacao(Publicacao *publicacao);
    string getNome();
};


#endif //P3_T2_DOCENTE_H
