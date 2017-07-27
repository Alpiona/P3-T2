#ifndef P3_T2_REGRAPONTUACAO_H
#define P3_T2_REGRAPONTUACAO_H

#include <array>
#include <string>
#include "util/DateUtils.h"

class RegraPontuacao {
private:
    cpp_util::time_t dataInicio;
    cpp_util::time_t dataFinal;
    std::array<std::string,8> categoriasQualis;
    std::array<int,8> pontuacaoQualis;
    double multiplicador;
    int qtdAnos;
    int pontuacaoMinima;

public:
    RegraPontuacao();
    RegraPontuacao(std::array<int,8> pontuacaoQualis, double multiplicador, int qtdAnos, int pontuacaoMinima, time_t dataInicio, time_t dataFinal);
    int valorQualis(std::string qualis);

};


#endif //P3_T2_REGRAPONTUACAO_H
