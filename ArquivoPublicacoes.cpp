#include "ArquivoPublicacoes.h"

using namespace std;

ArquivoPublicacoes::ArquivoPublicacoes(string pathname, vector<Docente*> docentes, vector<Veiculo*> veiculos ){
    this->entrada.open(pathname);
    this->docentes = docentes;
    this->veiculos = veiculos;
    this->publicacoes = publicacoes;
}
