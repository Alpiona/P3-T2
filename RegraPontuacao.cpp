#include <iostream>
#include "RegraPontuacao.h"
#include "util/DateUtils.h"

using namespace std;
using namespace cpp_util;


RegraPontuacao::RegraPontuacao() {}

RegraPontuacao::RegraPontuacao(array<int,8> pontuacaoQualis, double multiplicador, int qtdAnos, int pontuacaoMinima,
                               time_t dataInicio, time_t dataFinal) {
    this->categoriasQualis = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
    this->dataInicio = dataInicio;
    this->dataFinal = dataFinal;
    this->pontuacaoQualis = pontuacaoQualis;
    this->multiplicador = multiplicador;
    this->qtdAnos = qtdAnos;
    this->pontuacaoMinima = pontuacaoMinima;
}

string RegraPontuacao::getAno() {
    string dInicio = formatDate(this->dataInicio,DATE_FORMAT_PT_BR_SHORT);
    string ano = dInicio.substr(6,9);
    cout << ano << endl;
    return ano;
}

int RegraPontuacao::valorQualis(string qualis) {
    for (int i =0; i<8; i++){
        if (this->categoriasQualis[i].compare(qualis) == 0){
            return (pontuacaoQualis[i]);
        }
    }
    return 0;
}
