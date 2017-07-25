#include "Docente.h"
#include "Publicacao.h"

using namespace std;

Docente::Docente(long codigo, string nome, boolean coordenador) {
    this->codigo = codigo;
    this->nome = nome;
//    this->dataNascimento = dataNascimento;
//    this->dataIngresso = dataIngresso;
    this->coordenador = coordenador;
}

void Docente::adicionarPublicacao(Publicacao publicacao){
    this->publicacoes.push_back(publicacao);
}
