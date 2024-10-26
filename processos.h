#ifndef _processos_h_
#define _processos_h_

#include <bits/stdc++.h>
using namespace std;

/**
 * Definição da struct processos
 * 
 * 
 * 
 */
struct processos{
    int id;
    int duracao;
    int start_time;
    int end_time;
    string estado;

    processos(int duracao, int inicio) : duracao(duracao), start_time(inicio), estado("Pronto") {};
};

/**
 * @brief 
 * @details 
 * @return 
 */
processos cria_process(int duracao, int inicio);

/**
 * @brief 
 * @details 
 * @return 
 */
vector<processos> inicia_programa(int quantidade_procesoss);

#endif 