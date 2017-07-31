#include "ExceptionFile.h"
#include <string>
#include <fstream>
#include <iostream>
ExceptionFile::ExceptionFile() {}
const string ExceptionFile::errorMessage() const {
    return this->message;
}

void ExceptionFile::docenteRepetido(std::string codigo) {
    cout<<"Código repetido para docente: "<<codigo<<"."<<endl;
    exit(0);
}