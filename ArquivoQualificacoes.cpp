#include "ArquivoQualificacoes.h"
#include "ExceptionFile.h"

using namespace std;

ArquivoQualificacoes::ArquivoQualificacoes(string pathname, vector<Veiculo*> veiculos) {
    this->veiculos = veiculos;
    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        throw ExceptionFile();
    } else {
        loadDataToLocalMemory();
    }
}

void ArquivoQualificacoes::loadDataToLocalMemory() {
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (getline(this->entrada, line)) {
        if (line != "") {

            pos = line.find(separador);
            aux = line.substr(0, pos);
            int ano = atoi(aux.c_str());
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            cout << aux << endl;
            Veiculo *veiculo = encontraVeiculo(aux);
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string qualis = aux;
            line.erase(0, pos + 1);

            Qualis *novoQualis = new Qualis(ano, qualis);
            veiculo->getListaQualis().push_back(novoQualis);
        }
    }
}

Veiculo* ArquivoQualificacoes::encontraVeiculo(string aux) {
    for (vector<Veiculo*>::iterator veiculo = this->veiculos.begin(); veiculo != this->veiculos.end();veiculo++){
        Veiculo *auxVeiculo = *veiculo;
        if (auxVeiculo->getSigla().compare(aux) == 0){
            return auxVeiculo;
        }
    }
    return NULL;
}

vector<Qualis*> ArquivoQualificacoes::getListaQualis() {return this->qualificacoes;}

void ArquivoQualificacoes::setRegra(RegraPontuacao* regraPontuacao) {
    this->regra = regraPontuacao;

}

void ArquivoQualificacoes::colocarPontuacaoQualis() {
    for(unsigned i=0;i<this->qualificacoes.size();i++) {
        this->qualificacoes.at(i)->setPontuacao(this->regra->valorQualis(qualificacoes.at(i)->getQualis()));
    }
}