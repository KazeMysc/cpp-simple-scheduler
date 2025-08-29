//FIFO
#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "../utils/scr_utils.h"
#include "sched_fifo.h"
#include "menus.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

vector<Processo> schedProcessDefine(int iQtdProcessos) {
	
	vector<Processo> v_Processos(iQtdProcessos); //tam. qtd processos
	
	clscreen();
	
	for (int i = 0; i < iQtdProcessos; i++)  //pede nome e ut dos processos (qtdprocessos)
	{
		cout << "Digite o nome do processo " << i+1 << " (A, B, C)\n";
		cout << "Nome (string/int): ";
		cin >> v_Processos[i].sNome;
		
		cout << "Digite a unidade de tempo do processo: " << v_Processos[i].sNome << '\n';
		cout << "UT (int): ";
		cin >> v_Processos[i].iUnidadeTempo;
	} // loop pra armazenar nas classes o nome do processo e a ut

	clscreen();
	
	for (const auto& pr : v_Processos) //exibe nome e ut dos processos
	{
		cout << "Processo: " << pr.sNome << '\n';
		cout << "Unidade de Tempo (UT): " << pr.iUnidadeTempo << '\n';
	}
	
	sleep_for(seconds(3));
	clscreen();
	
	return v_Processos; // retorna o vetor pra usar no FIFO e no SJF
}

void schedFIFO(const vector<Processo>& v_Processos) {
//FIFO
		
		//loop pra "executar" os processos
		//utilizando o vetor que retornamos acima
		for (int e = 0; e < v_Processos.size(); e++) 
		{
			cout << "Chamando processo: " << v_Processos[e].sNome << '\n';
			sleep_for(seconds(3));
			clscreen();
			
			int iTempoRestante = v_Processos[e].iUnidadeTempo;				
			while (iTempoRestante >= 0) 
			{
				cout << "Executando processo: " << v_Processos[e].sNome << '\n';
				cout << "Tempo para finalizar: " << iTempoRestante;
				iTempoRestante--;		
				sleep_for(seconds(1));	
				clscreen();			
			}
			
			cout << "Processo " << v_Processos[e].sNome << " terminou de rodar.\n";
       	 	sleep_for(seconds(3));
        	clscreen();
		}
		cout << "Sem mais processos a serem executados." << endl; 
		//quando qtd de processos acabar, finaliza o programa
		
		//retorna pro menu principal quando pressionar qualquer tecla
    	waitscreen();
    	clscreen();
    	schedMainMenu();
		
}
