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
        cout << codigo << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string nome = aux;
        line.erase(0,pos+1);
        cout << nome << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string dataNascimento = aux;
        line.erase(0,pos+1);
        cout << dataNascimento << " ";

        pos = line.find(separador);
        aux = line.substr(0,pos);
        string dataIngresso = aux;
        line.erase(0,pos+1);
        cout << dataIngresso << " ";

        if (line.length()){
            cord = true;
            cout << "CORD" << endl;
        }
        else{
            cout << endl;
        }

    }
}

vector<Docente> ArquivoDocente::getDocentes(){

}

void ArquivoDocente::addDocente (Docente docente){

}