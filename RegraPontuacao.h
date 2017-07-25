#ifndef P3_T2_REGRAPONTUACAO_H
#define P3_T2_REGRAPONTUACAO_H

#include <array>
#include <string>

class RegraPontuacao {
private:
//    Date dataInicio;
//    Date dataFinal;
    std::array<std::string,8> categoriasQualis;
    std::array<int,8> pontuacaoQualis;
    double multiplicador;
    int qtdAnos;
    int pontuacaoMinima;

public:
    RegraPontuacao();
    RegraPontuacao(std::array<int,8> pontuacaoQualis, double multiplicador, int qtdAnos, int pontuacaoMinima);
    int valorQualis(std::string qualis);

};


#endif //P3_T2_REGRAPONTUACAO_H
