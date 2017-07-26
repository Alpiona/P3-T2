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

using namespace std;

vector<Docente*> docentes;
vector<Publicacao*> publicacoes;
vector<Qualis*> listaQualis;
vector<Veiculo*> veiculos;
RegraPontuacao regra;

int main() {
    ArquivoDocente *arqDocente = new ArquivoDocente("docentes.csv");
    docentes = arqDocente->getDocentes();

    ArquivoVeiculo *arqVeiculo = new ArquivoVeiculo("veiculos.csv");
    veiculos = arqVeiculo->getVeiculos();
//    for (vector<Veiculo*>::iterator veiculo = veiculos.begin(); veiculo != veiculos.end();veiculo++){
//        Veiculo *aux = *veiculo;
//        cout<< aux->getNome() << endl;
//    }
//    ArquivoPublicacoes *teste2 = new ArquivoPublicacoes("publicacoes.csv");

//    ArquivoQualificacoes *teste3 = new ArquivoQualificacoes("qualis.csv");
//    ArquivoRegras *teste4 = new ArquivoRegras("regras.csv");
    return 0;
}