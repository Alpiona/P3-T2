#include "ArquivoPublicacoes.h"
#include "ExceptionFile.h"
#include "util/StringUtils.h"
#include "util/Tokenizer.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using namespace cpp_util;

ArquivoPublicacoes::ArquivoPublicacoes(string pathname, vector<Docente*> docentes, vector<Veiculo*> veiculos ){
    this->entrada.open(pathname);
    if(!(this->entrada.is_open())){
        throw ExceptionFile();
    } else {
        this->docentes = docentes;
        this->veiculos = veiculos;
        loadDataToLocalMemory();
    }
}

void ArquivoPublicacoes::loadDataToLocalMemory() {
    string line;
    getline(this->entrada, line);
    while (getline(this->entrada, line)) {
        if (line != "") {

            cpp_util::Tokenizer splitter(line,';');
            vector<string> dados = splitter.remaining();
            for(unsigned i=0;i<dados.size();i++) {
                dados[i] = trim(dados[i]);
            }
            int ano = stoi(dados[0]);
            string siglaVeiculo = dados[1];
            string titulo = dados[2];
            int numero = stoi(dados[4]);
            int pgInicial = stoi(dados[7]);
            int pgFinal = stoi(dados[8]);

            // CRIAR EXCEÇÃO
            Veiculo* v = encontraVeiculo(siglaVeiculo);
            if(v==NULL) {
                cout << "veiculo nulo" << endl;
            } else {
                Tokenizer autoresToken(dados[3],',');
                vector<string> codigoAutores = autoresToken.remaining();
                for(unsigned i=0;i<codigoAutores.size();i++) {
                    codigoAutores[i] = trim(codigoAutores[i]);
                }
                vector<Docente*> autores = loadListaAutores(codigoAutores);
                if(dados[6].compare("") != 0) {
                    string local = dados[6];
                    PublicacaoConferecia* publicacaoConferecia = new PublicacaoConferecia(numero, ano, pgInicial, pgFinal, titulo, v, local, autores);
                    publicacoes.push_back(publicacaoConferecia);
                }
                if(dados[5].compare("") != 0) {
                    int volume = stoi(dados[5]);
                    PublicacaoPeriodico* publicacaoPeriodico = new PublicacaoPeriodico(numero, ano, volume, pgInicial, pgFinal, titulo, v, autores);
                    publicacoes.push_back(publicacaoPeriodico);
                }
            }
        }
    }
}

vector<Publicacao*> ArquivoPublicacoes::getPublicacoes() { return this->publicacoes; }

vector<Docente*> ArquivoPublicacoes::loadListaAutores(vector<string> autores) {
    vector<Docente*> listaAutores;
    Docente *novoAutor;
    for(string codigo: autores) {
        novoAutor = encontraDocente(codigo);
        listaAutores.push_back(novoAutor);
    }
    return listaAutores;
}

Docente* ArquivoPublicacoes::encontraDocente(string codigo) {
    for (vector<Docente*>::iterator docente = this->docentes.begin(); docente != this->docentes.end();docente++){
        Docente *aux = *docente;
        if (aux->getCodigo().compare(codigo) == 0){
            return aux;
        }
    }
    return NULL;
}

Veiculo* ArquivoPublicacoes::encontraVeiculo(string sigla) {
    for(Veiculo* v: veiculos) {
        if(v->getSigla().compare(sigla) == 0) {
            return v;
        }
    }
    return NULL;
}