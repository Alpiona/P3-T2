#ifndef P3_T2_ARQUIVOQUALIFICACOES_H
#define P3_T2_ARQUIVOQUALIFICACOES_H

#include <string>
#include <fstream>
#include <iostream>
#include "Qualis.h"
#include "RegraPontuacao.h"
#include "Veiculo.h"

class Qualis;
class RegraPontuacao;
class Veiculo;
class ArquivoQualificacoes {
private:
    ifstream entrada;
    vector<Qualis*> qualificacoes;
    vector<Veiculo*> veiculos;
    vector<Veiculo*> novosVeiculos;
    RegraPontuacao regra;
public:
    ArquivoQualificacoes(std::string pathname, vector<Veiculo*> veiculos);
    ArquivoQualificacoes(std::string pathname);
    void loadDataToLocalMemory();
};


#endif //P3_T2_ARQUIVOQUALIFICACOES_H
