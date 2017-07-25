#include "ArquivoRegras.h"

using namespace std;

ArquivoRegras::ArquivoRegras(string pathname) {
    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        cout << "ERRO " << pathname << endl;
    }
    else{loadDataToMemory();}
}

void ArquivoRegras::loadDataToMemory() {
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    getline(this->entrada, line);

    pos = line.find(separador);
    aux = line.substr(0, pos);
    string inicio = aux;
    line.erase(0, pos + 1);
    cout << inicio << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    string fim = aux;
    line.erase(0, pos + 1);
    cout << fim << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    string qualis = aux;
    line.erase(0, pos + 1);
    string unicoQualis;
    while (qualis.length() > 2){
        pos = qualis.find(",");
        aux = qualis.substr(0,pos);
        unicoQualis = aux;
        qualis.erase(0,pos+1);
        cout << unicoQualis << " ";
    }
    cout << unicoQualis << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    string pontos = aux;
    line.erase(0, pos + 1);
    while (pontos.length()>2){
        pos = pontos.find(",");
        aux = pontos.substr(0,pos);
        int unicoPonto = atoi(aux.c_str());
        pontos.erase(0,pos+1);
        cout << unicoPonto << " ";
    }
    cout << pontos << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    float multiplicador  =atof(aux.c_str()); //pega como float mas n considera a virgula
    line.erase(0, pos + 1);
    cout << multiplicador << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    int anos = atoi(aux.c_str());
    line.erase(0, pos + 1);
    cout << anos << " ";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    int pontosMinimos = atoi(aux.c_str());
    line.erase(0, pos + 1);
    cout << pontosMinimos << endl;

}