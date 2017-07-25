#include "ArquivoVeiculo.h"

using namespace std;

ArquivoVeiculo::ArquivoVeiculo(string pathname) {
    this->entrada.open(pathname);
    if(!(this->entrada.is_open())){
        cout<< "ERRO " << pathname << endl;
    }
    else{
        loadDataToMemory();
    }
}

void ArquivoVeiculo::loadDataToMemory() {
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (!entrada.eof()) {
        getline(this->entrada, line);

        pos = line.find(separador);
        aux = line.substr(0, pos);
        string sigla = aux;
        line.erase(0, pos + 1);
        cout << sigla << " ";

        pos = line.find(separador);
        aux = line.substr(0, pos);
        string nome = aux;
        line.erase(0, pos + 1);
        cout << nome << " ";

        pos = line.find(separador);
        aux = line.substr(0, pos);
        string tipo = aux;
        line.erase(0, pos + 1);
        cout << tipo << " ";

        pos = line.find(separador);
        aux = line.substr(0, pos);
        float impacto = atof(aux.c_str());  //transforma em float mas n pega depois da virgula
        line.erase(0, pos + 1);
        cout << impacto << " ";

        if (line.length()>1){
            pos = line.find(separador);
            aux = line.substr(0, pos);
            string ISSN = aux;
            line.erase(0, pos + 1);
            cout << ISSN << endl;
        }
        else{
            cout << endl;
        }


    }
}
