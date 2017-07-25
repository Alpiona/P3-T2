#ifndef P3_T2_ARQUIVOPUBLICACOES_H
#define P3_T2_ARQUIVOPUBLICACOES_H

#include <string>
#include <fstream>
#include "Docente.h"
#include "Veiculo.h"
#include "Publicacao.h"

using namespace std;

class Docente;
class ArquivoPublicacoes {
private:
    ifstream entrada;
    vector<Docente*> docentes;
    vector<Veiculo*> veiculos;
    vector<Publicacao*> publicacoes;
    Veiculo containsVeiculoDeSigla(string pTitulo, string sigla);
    //vector<Docente> loadListaAutoires(string[] autores, string pTitulo);
    Docente isCodigoDocenteValid (string codigo);

public:
    ArquivoPublicacoes(string pathname, vector<Docente*> docentes, vector<Veiculo*> veiculos);
    void loadDataToLocalMemory();
    vector<Publicacao*> getPublicacoes();
    void adicionarPubAoAutor (Publicacao p, vector<Docente*> autores);

};


#endif //P3_T2_ARQUIVOPUBLICACOES_H
