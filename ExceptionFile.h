//
// Created by sandor on 26/07/17.
//
#include <exception>
using namespace std;

#ifndef P3_T2_EXCEPTIONFILE_H
#define P3_T2_EXCEPTIONFILE_H

class ExceptionFile: public exception {
public:
    virtual const char* errorMessage() const throw();

};

#endif //P3_T2_EXCEPTIONFILE_H
