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
    while (getline(this->entrada, line)) {
        if (line != "") {
            pos = line.find(separador);
            aux = line.substr(0, pos);
            string sigla = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string nome = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            char tipo = aux.at(0);
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            double impacto = atof(aux.c_str());  //transforma em float mas n pega depois da virgula
            line.erase(0, pos + 1);

            Veiculo *novoVeiculo;
            if (line.length() > 0) {
                pos = line.find(separador);
                aux = line.substr(0, pos);
                string ISSN = aux;
                line.erase(0, pos + 1);
                novoVeiculo = new Veiculo(sigla, nome, tipo, impacto, ISSN);
            } else {
                string ISSN = "";
                novoVeiculo = new Veiculo(sigla, nome, tipo, impacto, ISSN);
            }
            this->veiculos.push_back(novoVeiculo);
        }
    }
}

vector<Veiculo*> ArquivoVeiculo::getVeiculos() {return this->veiculos;}
