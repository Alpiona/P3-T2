#include "RelatorioEstatisticas.h"
#include <iostream>
#include <fstream>

#include <vector>

using namespace std;

EstatisticaQualis::EstatisticaQualis(std::string qualis, int nArtigos, double nArtigosPorDocente){
    this->qualis = qualis;
    this->nArtigos = nArtigos;
    this->nArtigosPorDocente = nArtigosPorDocente;
}

string EstatisticaQualis::getQualis() {return this->qualis;}

int EstatisticaQualis::getNArtigos() {return this->nArtigos;}

double EstatisticaQualis::returnArtigosPorDocente() {return this->nArtigosPorDocente;}

RelatorioEstatisticas::RelatorioEstatisticas(string pathname, vector<Publicacao*> publicacoes){
    this->pathname = pathname;
    this->publicacoes = publicacoes;
    this->getEstatisticaAllQualis();
}

void RelatorioEstatisticas::getEstatisticaAllQualis() {
    for (int i =0; i<8;i++){
        this->getEstatisticasDeQualis(this->categoriasQualis[i]);
    }
}

void RelatorioEstatisticas::getEstatisticasDeQualis(string qualis) {
    int auxNArtigos = 0;
    double nArtigosPorDocente =0;
    for (Publicacao* p : publicacoes){
        if (p->getQualis().compare(qualis) == 0){
            auxNArtigos++;
            double auxNArtigosPorDocente = 1/ (double)p->getAutores().size();
            nArtigosPorDocente += auxNArtigosPorDocente;
        }
    }
    EstatisticaQualis *novaEstatistica = new EstatisticaQualis(qualis, auxNArtigos, nArtigosPorDocente);
    this->estatisticas.push_back(novaEstatistica);
}

void RelatorioEstatisticas::write() {
    ofstream relatorioCSV;
    relatorioCSV.open(this->pathname);
    if(!relatorioCSV.is_open()) {
        cout << "Não criou" << endl;
    }
    relatorioCSV << "Qualis;Qtd. Artigos;Média Artigos / Docente\n";
    for(EstatisticaQualis* e : this->estatisticas){
        relatorioCSV << e->getQualis() << ";" << e->getNArtigos() << ";" << e->returnArtigosPorDocente()<<endl;
    }

}