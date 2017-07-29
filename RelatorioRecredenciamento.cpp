#include "RelatorioRecredenciamento.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

RelatorioRecredenciamento::RelatorioRecredenciamento(string pathname, std::vector<Docente*> docentes,
                                                     RegraPontuacao* regra) {
    this->docentes = docentes;
    this->pathname = pathname;
    this->regra = regra;
    time(&hoje); //NUMERO DE SEGUNDOS DESDE 00:00 hours, Jan 1, 1970 UTC
}

bool RelatorioRecredenciamento::ordenaDocentes(Docente* doc1, Docente* doc2) {
    if (doc1->getNome().compare(doc2->getNome()) < 0)
        return true;
    else
        return false;
}

long RelatorioRecredenciamento::diferencaDatas(time_t data1, time_t data2) {
    return (data1-data2);
}

void RelatorioRecredenciamento::write() {
    cout << hoje << " " << (hoje/31622400);
}