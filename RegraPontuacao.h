#ifndef P3_T2_REGRAPONTUACAO_H
#define P3_T2_REGRAPONTUACAO_H

using namespace std;

class RegraPontuacao {
private:
//    Date dataInicio;
//    Date dataFinal;
    string categoriasQualis[8] = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};
    int pontuacaoQualis[8];
    double multiplicador;
    int qtdAnos;
    int pontuacaoMinima;

public:
    RegraPontuacao(int pontuacaoQualis[8], double multiplicador, int qtdAnos, int pontuacaoMinima);
    int valorQualis(string qualis);

};


#endif //P3_T2_REGRAPONTUACAO_H
