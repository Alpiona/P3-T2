#include <histedit.h>
#include "ArquivoQualificacoes.h"
#include "ExceptionFile.h"
#include "util/StringUtils.h"
#include "util/Tokenizer.h"

using namespace std;
using namespace cpp_util;

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
    getline(this->entrada,line);
    while (getline(this->entrada, line)) {
        if (line != "") {

            cpp_util::Tokenizer tok(line, ';');
            vector<string> tokens = tok.remaining();
            for(unsigned i=0;i<tokens.size();i++) {
                tokens[i] = trim(tokens[i]);
                //cout << tokens[i] << endl;
            }

            int ano;
            try {
                ano = stoi(tokens[0]);
            } catch (invalid_argument &e) {
                cout << e.what() << endl;
            }

            string siglaVeiculo = tokens[1];
            string qualis = tokens[2];

            Qualis *novoQualis = new Qualis(ano, qualis);
            qualificacoes.push_back(novoQualis);
            Veiculo *veiculo = this->encontraVeiculo(siglaVeiculo); // CRIAR EXCEÇÃO SIGLA VALIDA
            veiculo->getListaQualis().push_back(novoQualis); // CRIAR EXCEÇÃO VALIDA QUALIS
            novosVeiculos.push_back(veiculo);
        }
    }
}

Veiculo* ArquivoQualificacoes::encontraVeiculo(string sigla) {
    Veiculo* veiculo = NULL;
    for(Veiculo* v: this->veiculos) {
        if(v->getSigla().compare(sigla) == 0) {
            return v;
        }
    }
    return veiculo;
}

vector<Qualis*> ArquivoQualificacoes::getListaQualis() {return this->qualificacoes;}

void ArquivoQualificacoes::setRegra(RegraPontuacao* regraPontuacao) {
    this->regra = regraPontuacao;
    this->colocarPontuacaoQualis();
}

void ArquivoQualificacoes::colocarPontuacaoQualis() {
    for(unsigned i=0;i<this->qualificacoes.size();i++) {
        this->qualificacoes.at(i)->setPontuacao(this->regra->valorQualis(qualificacoes.at(i)->getQualis()));
    }
}