#include "escalonamento.h"

void RR(vector<processos> &programa, int quantum){
    int tempo_atual = 0, aux, pos = 0, flag = 1;
    vector<int> wt (programa.size(), 0);
    vector<int> tat (programa.size(), 0);
    vector<int> tempo_restante (programa.size(), 0);
    queue<processos*> fila;

    tempo_atual += programa[pos].start_time;
    fila.push(&programa[pos]);
    pos++;

    for (int i = 0; i < (int)programa.size(); i++) tempo_restante[i] = programa[i].duracao;

    while(!fila.empty() || pos != (int) programa.size()){
        aux = fila.front()->id - 1;
        fila.pop();
        
        int execucao = min(quantum, tempo_restante[aux]);
        tempo_restante[aux] -= execucao;
        tempo_atual += execucao;
        
        if(tempo_restante[aux] == 0){
            programa[aux].end_time = tempo_atual;
            tat[aux] = tempo_atual - programa[aux].start_time;
            wt[aux] = tat[aux] - programa[aux].duracao;
            programa[aux].estado = "Finalizado";
            flag = 0;
        }

        for(int i = pos; i < (int)programa.size(); ++i){
            if(programa[i].start_time <= tempo_atual){
                fila.push(&programa[i]);
                programa[i].estado = "Executando";
                pos++;
            }
            else{
                if(fila.empty()){
                    tempo_atual = programa[i].start_time;
                    i--;
                }
                else break;
            }
        }

        if(flag) fila.push(&programa[aux]);
        else flag = 1;
    }

    cout << endl << "   Resultados: " << endl;
    cout << "-----------------------------" << endl;
    cout << "Tempo levado para executar o programa: " << tempo_atual << endl;
    for(int i = 0; i < (int)programa.size(); ++i){
        cout << "Waiting: "<< wt[i] << " || " << "Tat: " << tat[i] << endl;
    }
} 