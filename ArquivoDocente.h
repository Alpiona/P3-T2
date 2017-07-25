#ifndef P3_T2_ARQUIVODOCENTE_H
#define P3_T2_ARQUIVODOCENTE_H

#include <string>
#include <vector>
#include <fstream>
#include "Docente.h"

using namespace std;

class ArquivoDocente {
private:
    vector<Docente> docentes;
//    string pathname;
    ifstream entrada;

public:
    ArquivoDocente();
    ArquivoDocente(string pathname);
    void loadDataToMemory();
    vector<Docente> getDocentes();
    void addDocente (Docente docente);
};


#endif //P3_T2_ARQUIVODOCENTE_H
