#ifndef P3_T2_ARQUIVOREGRAS_H
#define P3_T2_ARQUIVOREGRAS_H

#include "RegraPontuacao.h"
#include <iostream>
#include <fstream>
#include <string>

class RegraPontuacao;
class ArquivoRegras {
private:
    std::ifstream entrada;
    RegraPontuacao regra;

public:
    ArquivoRegras(std::string pathname);
    void loadDataToMemory();
};


#endif //P3_T2_ARQUIVOREGRAS_H
