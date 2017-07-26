#include "ArquivoPublicacoes.h"
#include "ExceptionFile.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ArquivoPublicacoes::ArquivoPublicacoes(string pathname, vector<Docente*> docentes, vector<Veiculo*> veiculos ){
    this->entrada.open(pathname);
    this->docentes = docentes;
    this->veiculos = veiculos;
    this->publicacoes = publicacoes;
}

ArquivoPublicacoes::ArquivoPublicacoes(string pathname) {
    this->entrada.open(pathname);
    if(!(this->entrada.is_open())){
        throw ExceptionFile();
    }
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
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string titulo = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string autores = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string numero = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string volume;
            if (aux.length() >= 0) {
                volume = aux;
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
            string pgInicial = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string pgFinal = aux;
            line.erase(0, pos + 1);

//            if (volume.compare("") == 0){
//                PublicacaoConferecia *novaPublicacao = new PublicacaoConferecia(numero,ano,pgInicial,titulo );
//                this->publicacoes.push_back(novaPublicacao);
//            }
//            else if (local.compare("") == 0){
//                PublicacaoPeriodico *novaPublicacao = new PublicacaoPeriodico(numero,ano,pgInicial,....)
//                this->publicacoes.push_back(novaPublicacao);
//            }
        }
    }
}

vector<Publicacao*> ArquivoPublicacoes::getPublicacoes() {return this->publicacoes;}
