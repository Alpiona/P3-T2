#ifndef P3_T2_ARQUIVOVEICULO_H
#define P3_T2_ARQUIVOVEICULO_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Veiculo.h"

class ArquivoVeiculo {
private:
    vector<Veiculo*> veiculos;
    std::ofstream entrada;

public:
    ArquivoVeiculo(std::string pathname);
    void loadDataToMemory();
};


#endif //P3_T2_ARQUIVOVEICULO_H
