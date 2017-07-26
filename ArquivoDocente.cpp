#include "ArquivoDocente.h"
#include <iostream>
#include <fstream>

using namespace std;

ArquivoDocente::ArquivoDocente() {

}

ArquivoDocente::ArquivoDocente(string pathname){
    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        cout<<"ERRO "<<pathname<<endl;
    }
    loadDataToMemory();
}

void ArquivoDocente::loadDataToMemory(){
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (!entrada.eof()){
        getline(this->entrada, line);

        bool cord = false;

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string codigo = aux;
        line.erase(0,pos+1);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string nome = aux;
        line.erase(0,pos+1);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string dataNascimento = aux;
        line.erase(0,pos+1);

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string dataIngresso = aux;
        line.erase(0,pos+1);

        if (line.length()){
            cord = true;
        }
        Docente *novoDocente = new Docente(codigo, nome, cord);    //FALTA DATAS
        this->docentes.push_back(novoDocente);
    }
    this->docentes.pop_back();
}

vector<Docente*> ArquivoDocente::getDocentes(){
    return this->docentes;
}

void ArquivoDocente::addDocente (Docente docente){

}