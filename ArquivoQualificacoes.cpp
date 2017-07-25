#include "ArquivoQualificacoes.h"

using namespace std;

//ArquivoQualificacoes::ArquivoQualificacoes(string pathname, vector<Veiculo*> veiculos) {
ArquivoQualificacoes::ArquivoQualificacoes(string pathname) {
    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        cout << "ERRO " << pathname << endl;
    }
    loadDataToLocalMemory();
}

void ArquivoQualificacoes::loadDataToLocalMemory() {
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (!entrada.eof()) {
        getline(this->entrada, line);

        pos = line.find(separador);
        aux = line.substr(0, pos);
        int ano = atoi(aux.c_str());
        line.erase(0, pos + 1);
        cout << ano << " ";

        pos = line.find(separador);
        aux = line.substr(0, pos);
        string veiculo = aux;
        line.erase(0, pos + 1);
        cout << veiculo << " ";

        pos = line.find(separador);
        aux = line.substr(0, pos);
        string qualis = aux;
        line.erase(0, pos + 1);
        cout << qualis << endl;
    }
}
