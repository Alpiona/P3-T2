#include "Publicacao.h"

using namespace std;

Publicacao::Publicacao(int numero, int ano, int pgInicial, int pgFinal, Veiculo* veiculo,
                       vector<Docente*> autores, string titulo) {
    this->numero = numero;
    this->ano = ano;
    this->pgInicial = pgInicial;
    this->pgFinal = pgFinal;
    this->veiculo = veiculo;
    this->autores = autores;
    this->titulo = titulo;
}

string Publicacao::getNome() {return this->titulo;}