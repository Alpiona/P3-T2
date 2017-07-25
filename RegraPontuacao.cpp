#include "RegraPontuacao.h"

RegraPontuacao::RegraPontuacao(int *pontuacaoQualis, double multiplicador, int qtdAnos, int pontuacaoMinima) {
//    this->dataInicio = dataInicio;
//    this->dataFinal = dataFinal;
    this->pontuacaoQualis = pontuacaoQualis;
    this->multiplicador = multiplicador;
    this->qtdAnos = qtdAnos;
    this->pontuacaoMinima = pontuacaoMinima;
}

int RegraPontuacao::valorQualis(string qualis) {
    for (int i =0; i<8; i++){
        if (categoriaQualis[i] == qualis){
            return (pontuacaoQualis[i]);
        }
    }
    return 0;
}
