#ifndef P3_T2_QUALIS_H
#define P3_T2_QUALIS_H

#include <string>
#include <array>
#include "RegraPontuacao.h"

class Qualis {
private:
    int ano;
    int pontuacao;
    std::string qualis;
    std::array<std::string,8> categoriasQualis;
    RegraPontuacao *regra;

public:
    Qualis(int ano, std::string qualis);
    void setRegra (RegraPontuacao *regra);
    std::string getQualis();
    void setPontuacao(int pontuacao);
    bool isValidQualis();
};


#endif //P3_T2_QUALIS_H
