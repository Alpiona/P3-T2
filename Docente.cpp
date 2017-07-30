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

vector<Publicacao*> Docente::getPublicacoes() {return this->publicacoes;}

time_t Docente::getDataIngresso(){return this->dataIngresso;}

string Docente::getNome() {return this->nome;}

bool Docente::isOverSixty(time_t hoje) {
    long diferenca = hoje-(this->dataNascimento);
    if (diferenca >= (86400*365.25*60))
        return true;
    else{
        return false;
    }
}

bool Docente::lessThreeYears(time_t hoje) {
    long diferenca = hoje-(this->dataIngresso);
    if (diferenca < (86400*365.25*3))
        return true;
    else{
        return false;
    }
}

string Docente::getCodigo() {return this->codigo;}