#ifndef P3_T2_RELATORIORECREDENCIAMENTO_H
#define P3_T2_RELATORIORECREDENCIAMENTO_H

#include "Docente.h"
#include "util/DateUtils.h"
#include <algorithm>
#include <string>
#include <vector>
#include <time.h>

class RelatorioRecredenciamento {
private:
    std::vector<Docente*> docentes;
    std::string pathname;
    RegraPontuacao* regra;
    time_t hoje;
public:
    RelatorioRecredenciamento (string pathname, std::vector<Docente*> docentes, RegraPontuacao* regra);
    void ordenaDocentes();
    long diferencaDatas(time_t data1, time_t data2);
    void write();
    bool ordenaDocentes(Docente* doc1, Docente* doc2);
};


#endif //P3_T2_RELATORIORECREDENCIAMENTO_H