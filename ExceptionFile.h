//
// Created by sandor on 26/07/17.
//
#include <exception>
#include <string>

using namespace std;

#ifndef P3_T2_EXCEPTIONFILE_H
#define P3_T2_EXCEPTIONFILE_H

class ExceptionFile: public exception {
    const string message = "Erro de I/O";
public:
    ExceptionFile();
    const string errorMessage() const;
    void docenteRepetido(std::string codigo);


};

#endif //P3_T2_EXCEPTIONFILE_H
