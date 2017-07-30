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
        for (Publicacao* publicacao : docente->getPublicacoes()){
            if (publicacao->getVeiculo()->getTipo() == 'P'){
                pontos += regra->valorQualis(publicacao->getQualis()) * regra->getMultiplicador();
            }
            else{
                pontos += regra->valorQualis(publicacao->getQualis());
            }
        }
        if (docente->isCoordenador()){
            especificacao = "Coordenador";
        }
        else if (docente->isOverSixty(hoje)){
            especificacao = "PPS";
        }
        else if (docente->lessThreeYears(hoje)){
            especificacao = "PPJ";
        }
        else if (pontos >= regra->getPontuacaoMinima()){
            especificacao = "Sim";
        }
        saida << docente->getNome() << ";" << pontos << ";" << especificacao << "\n";
    }

}