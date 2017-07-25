#ifndef P3_T2_QUALIS_H
#define P3_T2_QUALIS_H

#include <string>

using namespace std;

class Qualis {
private:
    int ano;
    int pontuacao;
    string qualis;
    string categoriasQualis[8] = {"A1", "A2", "B1", "B2", "B3", "B4", "B5", "C"};

public:
    Qualis(int ano, string qualis);
    void setPontuacao(int pontuacao);
    bool isValidQualis();
};


#endif //P3_T2_QUALIS_H
