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

void RelatorioRecredenciamento::ordenaDocentes() {
    vector<string> nomesOrdenados;
    for (Docente* auxDocente : this->docentes){
        nomesOrdenados.push_back(auxDocente->getNome());
    }
    sort(nomesOrdenados.begin(),nomesOrdenados.end());
    vector<Docente*> docentesOrdenados;
    for (string nome : nomesOrdenados){
        for (Docente* auxDocente : this->docentes){
            if (auxDocente->getNome().compare(nome) == 0){
                docentesOrdenados.push_back(auxDocente);
                break;
            }
        }
    }
    this->docentes = docentesOrdenados;
}

void RelatorioRecredenciamento::write() {
    ordenaDocentes();
    ofstream saida;
    locale mylocale("pt_BR.UTF-8");
    saida.imbue(mylocale);
    saida.open(this->pathname);
    if(!saida.is_open()) {
        cout << "Não criou" << endl;
    }
    saida << "Docente;Pontuação;Recredenciado?\n";
    string especificacao;
    double pontos;
    for (Docente* docente : docentes){
        pontos = 0;
        especificacao = "Não";
//        if (docente->getNome().compare("Jason Sudeikis") == 0){
//            cout << docente->getCodigo()<< " " << docente->getNome()<<endl;
//            cout << "TIPO; SIGLA; QUALIS; PONTUACAO TOTAL; TITULO\n";
//        }
        for (Publicacao* publicacao : docente->getPublicacoes()){
            if (publicacao->getVeiculo()->getTipo() == 'P'){
                int anoRegra;
                try {
                    anoRegra = stoi(regra->getAno());
                } catch (invalid_argument e) {
                    cout << e.what() << endl;
                }
                if(publicacao->getAno() >= (anoRegra - regra->getQtdAnos()) && publicacao->getAno() != anoRegra && publicacao->getAno() < anoRegra) {
                    pontos = pontos + regra->valorQualis(publicacao->getQualis()) * regra->getMultiplicador();
                }

            }
            else{
                pontos += regra->valorQualis(publicacao->getQualis());
            }
        }
        if (docente->isCoordenador()){
            especificacao = "Coordenador";
        }
        else if (docente->isOverSixty(regra->getDataFinal())){
            especificacao = "PPS";
        }
        else if (docente->lessThreeYears(regra->getDataFinal())){
            especificacao = "PPJ";
        }
        else if (pontos >= regra->getPontuacaoMinima()){
            especificacao = "Sim";
        }
        saida << docente->getNome() << ";"<< setprecision(1) << fixed  <<  pontos << ";" << especificacao << "\n";
    }

}