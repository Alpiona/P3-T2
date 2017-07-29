#include "RelatorioEstatisticas.h"

#include <vector>

using namespace std;

EstatisticaQualis::EstatisticaQualis(std::string qualis, int nArtigos, double nArtigosPorDocente){
    this->qualis = qualis;
    this->nArtigos = nArtigos;
    this->nArtigosPorDocente = nArtigosPorDocente;
}

RelatorioEstatisticas::RelatorioEstatisticas(string pathname, std::vector<Publicacao*> publicacoes){
    this->pathname = pathname;
    this->publicacoes = publicacoes;
}

void RelatorioEstatisticas::getEstatisticaAllQualis() {
    for (int i =0; i<8;i++){
        this->getEstatisticasUmQualis(this->categoriasQualis[i]);
    }
}

void RelatorioEstatisticas::getEstatisticasUmQualis(string qualis) {
    int auxNArtigos = 0;
    double nArtigosPorDocente =0;
    for (Publicacao* p : publicacoes){
        if (p->getQualis().compare(qualis) == 0){
            auxNArtigos++;
            double auxNArtigosPorDocente = 1/p->getFormatListaAutores().size();
            nArtigosPorDocente += auxNArtigosPorDocente;
        }
    }
    EstatisticaQualis *novaEstatistica = new EstatisticaQualis(qualis, auxNArtigos, nArtigosPorDocente);
    this->estatisticas.push_back(novaEstatistica);
}