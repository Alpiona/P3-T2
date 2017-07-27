#include "RegraPontuacao.h"
#include <array>

using namespace std;

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

int RegraPontuacao::valorQualis(string qualis) {
    for (int i =0; i<8; i++){
        if (this->categoriasQualis[i].compare(qualis) == 0){
            return (pontuacaoQualis[i]);
        }
    }
    return 0;
}
