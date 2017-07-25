#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "ArquivoDocente.h"
#include "ArquivoPublicacoes.h"
#include "Docente.h"
#include "Publicacao.h"

using namespace std;

int main() {
    ArquivoDocente *teste = new ArquivoDocente("docentes.csv");
//    ArquivoPulicacoes *teste2 = new ArquivoPublicacoes("publicacoes.csv");
    return 0;
}