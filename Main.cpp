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
#include "RelatorioPublicacao.h"

using namespace std;

// ios::binary - treating the file as binary

vector<Docente*> docentes;
vector<Publicacao*> publicacoes;
vector<Qualis*> listaQualis;
vector<Veiculo*> veiculos;
RegraPontuacao* regra;



int main() {


    ArquivoDocente *arqDocente;
    ArquivoVeiculo *arqVeiculo;
    ArquivoPublicacoes *arqPublicacoes;
    ArquivoQualificacoes *arqQualificacoes; // implementar getQualificacoes
    ArquivoRegras *arqRegras; // implementar getRegra

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

    try {
        arqRegras = new ArquivoRegras("regras.csv");
        regra = arqRegras->getRegra("2017");
    } catch(ExceptionFile e) {
        cout << e.errorMessage() << endl;
    }


    try {
        arqQualificacoes = new ArquivoQualificacoes("qualis.csv", veiculos);
        //arqQualificacoes->setRegra(regra);
        listaQualis = arqQualificacoes->getListaQualis();
    } catch(ExceptionFile e) {
        cout << e.errorMessage() << endl;
    }

    cout << "gente???" << endl;


    //Gerando Relatórios

    for(Publicacao* publicacao : publicacoes) {
        cout << publicacao->getNome() << endl;
    }

    //RelatorioPublicacao* relatorioPublicacao = new RelatorioPublicacao("relatoriopublicacao.csv", publicacoes);
    //relatorioPublicacao->write();

    return 0;
}