#include "ArquivoDocente.h"
#include "ExceptionFile.h"
#include "util/DateUtils.h"

using namespace std;
using namespace cpp_util;

ArquivoDocente::ArquivoDocente() {

}

ArquivoDocente::ArquivoDocente(string pathname) {

    this->entrada.open(pathname);
    if (!(this->entrada.is_open())){
        throw new ExceptionFile();
    } else {
        loadDataToMemory();
    }

}

void ArquivoDocente::loadDataToMemory(){
    string line;
    string aux;
    size_t pos = 0;
    string separador = ";";
    getline(this->entrada, line);
    while (getline(this->entrada,line)) {
        if (line != "") {
            bool cord = false;

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string codigo = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            string nome = aux;
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            time_t dNascimento = parseDate(aux, DATE_FORMAT_PT_BR_SHORT);
            line.erase(0, pos + 1);

            pos = line.find(separador);
            aux = line.substr(0, pos);
            time_t dIngresso = parseDate(aux, DATE_FORMAT_PT_BR_SHORT);
            line.erase(0, pos + 1);

            if (line.length()) {
                cord = true;
            }
            Docente *novoDocente = new Docente(codigo, nome, cord, dNascimento, dIngresso);
            this->docentes.push_back(novoDocente);
        }
    }
}

vector<Docente*> ArquivoDocente::getDocentes(){
    return this->docentes;
}

void ArquivoDocente::addDocente (Docente docente){

}