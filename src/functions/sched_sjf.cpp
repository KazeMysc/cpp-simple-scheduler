//SCHED_SJF CPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include "../utils/scr_utils.h"
#include "processo.h"		//pra classe
#include "sched_fifo.h" 	//pro vetor
#include "menus.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

//tambem utiliza o objeto-vetor de processos
void schedSJF(vector<Processo>& v_Processos) {
	
	sort(v_Processos.begin(), v_Processos.end(), [](const Processo& a, const Processo& b) {
		return a.iUnidadeTempo < b.iUnidadeTempo;
	});	
	//sort em ordem crescente
	
	cout << "Lendo processos." << endl;
	sleep_for(seconds(1));
	clscreen();
	cout << "Lendo processos.." << endl;
	sleep_for(seconds(1));
	clscreen();
	cout << "Lendo processos..." << endl;
	sleep_for(seconds(1));
	
	cout << "Selecionando processo mais curto. (menor Unidade de Tempo)" << endl;
	sleep_for(seconds(1));
	clscreen();
	cout << "Selecionando processo mais curto.. (menor Unidade de Tempo)" << endl;
	sleep_for(seconds(2));
	clscreen();
	
	cout << "Iniciando menor processo.." << endl;
	sleep_for(seconds(1));
	clscreen();
	cout << "Iniciando menor processo..." << endl;
	sleep_for(seconds(2));
	clscreen();
	cout << "Fila de processos: " << endl;
	
	int iNumProcesso = 1;
	for (const auto& pr : v_Processos)
	{
		cout << iNumProcesso << " - Processo: " << pr.sNome << '\n';
		cout << "Unidade de tempo: " << pr.iUnidadeTempo << '\n';
		iNumProcesso++;
	}
	sleep_for(seconds(3));
	
	for (int e = 0; e < v_Processos.size(); e++) 
		{
			cout << "Chamando menor processo: " << v_Processos[e].sNome << '\n';
			sleep_for(seconds(3));
			clscreen();
			
			int iTempoRestante = v_Processos[e].iUnidadeTempo;				
			while (iTempoRestante >= 0) 
			{
				cout << "Executando processo: " << v_Processos[e].sNome << '\n';
				cout << "Tempo para finalizar: " << iTempoRestante << endl;
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

