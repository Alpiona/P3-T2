cmake_minimum_required(VERSION 3.7)
project(P3_T2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main.cpp
        Docente.h Docente.cpp ArquivoDocente.cpp ArquivoDocente.h
        Publicacao.cpp Publicacao.h ArquivoPublicacoes.cpp ArquivoPublicacoes.h
        PublicacaoConferecia.cpp PublicacaoConferecia.h PublicacaoPeriodico.cpp PublicacaoPeriodico.h
        Qualis.cpp Qualis.h ArquivoQualificacoes.cpp ArquivoQualificacoes.h
        Veiculo.cpp Veiculo.h ArquivoVeiculo.cpp ArquivoVeiculo.h
        RegraPontuacao.cpp RegraPontuacao.h ArquivoRegras.cpp ArquivoRegras.h ExceptionFile.cpp ExceptionFile.h
        util/DateUtils.cpp util/DateUtils.h util/NumberUtils.cpp util/NumberUtils.h util/NumPunctPTBR.cpp util/NumPunctPTBR.h util/StringUtils.cpp util/StringUtils.h
        util/Tokenizer.cpp util/Tokenizer.h RelatorioPublicacao.cpp RelatorioPublicacao.h RelatorioEstatisticas.cpp RelatorioEstatisticas.h RelatorioRecredenciamento.cpp RelatorioRecredenciamento.h)
add_executable(P3_T2 ${SOURCE_FILES})