#include "ArquivoPublicacoes.h"
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
        cout << "ERRO " << pathname << endl;
    }
    loadDataToLocalMemory();
}

void ArquivoPublicacoes::loadDataToLocalMemory() {
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (!entrada.eof()){
        getline(this->entrada, line);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        int ano = atoi(aux.c_str());
        line.erase(0,pos+1);
        cout << ano << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string veiculo = aux;
        line.erase(0,pos+1);
        cout << veiculo << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string titulo = aux;
        line.erase(0,pos+1);
        cout << titulo << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string autores = aux;
        line.erase(0,pos+1);
        cout << autores << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string numero = aux;
        line.erase(0,pos+1);
        cout << numero << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        if (aux.length() >= 0){
            string volume = aux;
            cout << volume << " ";
        }
        line.erase(0,pos+1);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        if (aux.length() >= 0){
            string local= aux;
            cout << local << " ";
        }
        line.erase(0,pos+1);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string pgInicial = aux;
        line.erase(0,pos+1);
        cout << pgInicial << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string pgFinal = aux;
        line.erase(0,pos+1);
        cout << pgFinal << endl;

    }
}
