#ifndef P3_T2_DOCENTE_H
#define P3_T2_DOCENTE_H

#include "Publicacao.h"

using namespace std;

class Docente {
private:
    string nome;
    //Date dataNascimento;
    //Date dataIngresso;
    bool coordenador;
    vector<Publicacao> publicacoes;

public:
    Docente(long codigo, string nome, bool coordenador);
    void adicionarPublicacao(Publicacao publicacao);
};


#endif //P3_T2_DOCENTE_H
