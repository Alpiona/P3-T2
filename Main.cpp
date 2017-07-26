#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "ArquivoDocente.h"
#include "ArquivoPublicacoes.h"
#include "ArquivoQualificacoes.h"
#include "Docente.h"
#include "Publicacao.h"
#include "ArquivoRegras.h"
#include "ArquivoVeiculo.h"
#include "ExceptionFile.h"

using namespace std;

// ios::binary - treating the file as binary

vector<Docente*> docentes;
vector<Publicacao*> publicacoes;
vector<Qualis*> listaQualis;
vector<Veiculo*> veiculos;
RegraPontuacao regra;

void lerArquivos() {
    ArquivoDocente *arqDocente;
    ArquivoVeiculo *arqVeiculo;
    ArquivoPublicacoes *arqPublicacoes;
    ArquivoRegras *arqRegras; // implementar getRegra
    ArquivoQualificacoes *arqQualificacoes; // implementar getQualificacoes

    try {
        arqDocente = new ArquivoDocente("docentes.csv");
        docentes = arqDocente->getDocentes();
    } catch (ExceptionFile e) {
        cout << e.errorMessage() << endl;
    }

    try {
        arqVeiculo = new ArquivoVeiculo("veiculos.csv");
        veiculos = arqVeiculo->getVeiculos();
    } catch( ExceptionFile e) {
        cout << e.errorMessage() << endl;
    }

    try {
        arqPublicacoes = new ArquivoPublicacoes("publicacoes.csv", docentes, veiculos);
        publicacoes = arqPublicacoes->getPublicacoes();
    } catch (ExceptionFile e) {
        cout << e.errorMessage() << endl;
    }

//    try {
//        arqRegras = new ArquivoRegras("regras.csv");
//        regra = arqRegras->getRegra();
//    } catch(ExceptionFile e) {
//        cout << e.errorMessage() << endl;
//    }
//
//    try {
//        arqQualificacoes = new ArquivoQualificacoes("regras.csv", veiculos);
//        arqQualificacoes->setRegra(regra);
//        listaQualis = arqQualificacoes->getQualis();
//    } catch(ExceptionFile e) {
//        cout << e.errorMessage() << endl;
//    }
}

int main() {

    lerArquivos();


//    ArquivoDocente *arqDocente = new ArquivoDocente("docentes.csv");
//    docentes = arqDocente->getDocentes();
//    for (vector<Docente*>::iterator docente = docentes.begin(); docente != docentes.end();docente++){
//        Docente *aux = *docente;
//        cout<< aux->getNome() << endl;
//    }

//    ArquivoVeiculo *arquivoVeiculo = new ArquivoVeiculo("veiculos.csv");
//    veiculos = arquivoVeiculo->getVeiculos();
//    for(unsigned i = 0; i < veiculos.size(); i++) {
//        Veiculo *auxVeiculo = veiculos.at(i);
//        cout << auxVeiculo->getNome() << endl;
//    }

//    ArquivoVeiculo *arqVeiculo = new ArquivoVeiculo("veiculos.csv");
//    veiculos = arqVeiculo->getVeiculos();
//    for (vector<Veiculo*>::iterator veiculo = veiculos.begin(); veiculo != veiculos.end();veiculo++){
//        Veiculo *aux = *veiculo;
//        cout<< aux->getNome() << endl;
//    }

//    ArquivoPublicacoes *arqPublicacoes = new ArquivoPublicacoes("publicacoes.csv");
//    publicacoes = arqPublicacoes->getPublicacoes();
//
//    for(unsigned i=0;i<veiculos.size();i++) {
//        Veiculo *aux = veiculos.at(i);
//        cout << aux->getNome() << endl;
//    }

//    for (vector<Publicacao*>::iterator iterPublicacao = publicacoes.begin(); iterPublicacao != veiculos.end();iterPublicacao++){
//        Veiculo *aux = veiculos
//        cout<< aux->getNome() << endl;
//    }

//    ArquivoQualificacoes *arqQaulificacoes = new ArquivoQualificacoes("qualis.csv");

//    ArquivoRegras *arqRegras = new ArquivoRegras("regras.csv");
    return 0;
}