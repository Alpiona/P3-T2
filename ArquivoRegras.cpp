#include "ArquivoRegras.h"
#include "ExceptionFile.h"
#include "util/DateUtils.h"
#include "util/NumberUtils.h"
#include <locale>

using namespace std;
using namespace cpp_util;

ArquivoRegras::ArquivoRegras(string pathname) {
    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        throw ExceptionFile();
    }
    else{loadDataToMemory();}
}

RegraPontuacao* ArquivoRegras::getRegra(string ano) {

    for(unsigned i=0;i<this->regras.size();i++) {
        if(regras.at(i)->getAno().compare(ano) == 0) {
            return regras.at(i);
        }
    }
}

void ArquivoRegras::loadDataToMemory(){

    string line;
    getline(this->entrada,line);
    getline(this->entrada,line);

    while(getline(this->entrada,line)) {

    }
    string aux;
    size_t pos = 0;
    string separador = ";";

    pos = line.find(separador);
    aux = line.substr(0, pos);
    time_t dInicio;
    if(validDate(aux,DATE_FORMAT_PT_BR_SHORT)) {
        dInicio = parseDate(aux, DATE_FORMAT_PT_BR_SHORT);
    }
    line.erase(0, pos + 1);

    pos = line.find(separador);
    aux = line.substr(0, pos);
    time_t dFinal;
    if(validDate(aux,DATE_FORMAT_PT_BR_SHORT)) {
        dFinal = parseDate(aux, DATE_FORMAT_PT_BR_SHORT);
    }
    line.erase(0, pos + 1);

    pos = line.find(separador);
    aux = line.substr(0, pos);
    string qualis = aux;
    line.erase(0, pos + 1);
    string unicoQualis;


    pos = line.find(separador);
    aux = line.substr(0, pos);
    string pontos = aux;
    line.erase(0, pos + 1);

    array<string,8> categoriasQualis = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
    array<int,8> pontuacaoQualis = {0,0,0,0,0,0,0,0};
    int unicoPonto;
    int i =0;
    while (qualis.find(",") != string::npos) {
        i=0;
        pos = qualis.find(",");
        aux = qualis.substr(0, pos);
        unicoQualis = aux;
        qualis.erase(0, pos + 1);

        pos = pontos.find(",");
        aux = pontos.substr(0, pos);
        unicoPonto = atoi(aux.c_str());
        pontos.erase(0, pos + 1);

        while (categoriasQualis[i].compare(unicoQualis) != 0) {
            if (pontuacaoQualis[i] == 0 && i != 0){
                pontuacaoQualis[i] = pontuacaoQualis[i-1];
            }
            i++;
        }
        pontuacaoQualis[i] = unicoPonto;
    }

    while (categoriasQualis[i].compare(qualis) != 0) {
        if (pontuacaoQualis[i] == 0 && i != 0){
            pontuacaoQualis[i] = pontuacaoQualis[i-1];
        }
        i++;
    }
    while (i<8){
        pontuacaoQualis[i] = atoi(pontos.c_str());
        i++;
    }

    pos = line.find(separador);
    aux = line.substr(0, pos);
    double multiplicador  = atof(aux.c_str()); //pega como float mas n considera a virgula
    line.erase(0, pos + 1);

    pos = line.find(separador);
    aux = line.substr(0, pos);
    int anos = atoi(aux.c_str());
    line.erase(0, pos + 1);

    pos = line.find(separador);
    aux = line.substr(0, pos);
    int pontosMinimos = atoi(aux.c_str());

    RegraPontuacao* regraPontuacao = new RegraPontuacao(pontuacaoQualis, multiplicador, anos, pontosMinimos, dInicio, dFinal);

    this->regras.push_back(regraPontuacao);
}