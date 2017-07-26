#include "Docente.h"
#include "Publicacao.h"

using namespace std;

Docente::Docente(string codigo, string nome, bool coordenador, time_t dataNascimento, time_t dataIngresso) {
    this->codigo = codigo;
    this->nome = nome;
    this->dataNascimento = dataNascimento;
    this->dataIngresso = dataIngresso;
    this->coordenador = coordenador;
}

void Docente::adicionarPublicacao(Publicacao *publicacao){
    this->publicacoes.push_back(publicacao);
}

bool Docente::isCoordenador() {
    return this->coordenador;
}

bool Docente::isOverSixty(time_t ano) {

}

string Docente::getNome() {return this->nome;}