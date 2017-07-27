#include "ArquivoPublicacoes.h"
#include "ExceptionFile.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ArquivoPublicacoes::ArquivoPublicacoes(string pathname, vector<Docente*> docentes, vector<Veiculo*> veiculos ){
    this->entrada.open(pathname);
    if(!(this->entrada.is_open())){
        throw ExceptionFile();
    }
    this->docentes = docentes;
    this->veiculos = veiculos;
    loadDataToLocalMemory();
}

void ArquivoPublicacoes::loadDataToLocalMemory() {
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
            string veiculo = aux;
            Veiculo *auxVeiculo = encontraVeiculo(veiculo);
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string titulo = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string autores = aux;
            vector<Docente*> listaAutores = loadListaAutores(autores);
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            int numero = atoi(aux.c_str());
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            int volume = 0;
            if (aux.length() >= 0) {
                volume = atoi(aux.c_str());
            }
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string local;
            if (aux.length() >= 0) {
                local = aux;
            }
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            int pgInicial = atoi(aux.c_str());
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            int pgFinal = atoi(aux.c_str());
            line.erase(0, pos + 1);

            if (volume == 0){
                PublicacaoConferecia *novaPublicacao = new PublicacaoConferecia(numero,ano,pgInicial, pgFinal, titulo,auxVeiculo,local,listaAutores);
                this->publicacoes.push_back(novaPublicacao);
            }
            else if (local.compare("") == 0){
                PublicacaoPeriodico *novaPublicacao = new PublicacaoPeriodico(numero,ano, volume,pgInicial,pgFinal,titulo,auxVeiculo,listaAutores);
                this->publicacoes.push_back(novaPublicacao);
            }
        }
    }
}

vector<Publicacao*> ArquivoPublicacoes::getPublicacoes() {return this->publicacoes;}

vector<Docente*> ArquivoPublicacoes::loadListaAutores(string autores) {
    vector<Docente*> listaAutores;
    Docente *novoAutor;
    while (autores.find(",") != string::npos) {
        int pos = autores.find(",");
        string aux = autores.substr(0, pos);
        autores.erase(0, pos + 1);
        novoAutor = encontraDocente(aux);
    }
    listaAutores.push_back(novoAutor);
    novoAutor = encontraDocente(autores);
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
    for (vector<Veiculo*>::iterator veiculo = this->veiculos.begin(); veiculo != this->veiculos.end();veiculo++){
        Veiculo *aux = *veiculo;
        if (aux->getSigla().compare(sigla) == 0){
            return aux;
        }
    }
    return NULL;
}