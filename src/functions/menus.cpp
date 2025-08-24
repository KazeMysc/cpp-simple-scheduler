//MENU.CPP
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include "sched_fifo.h"
#include "sched_sjf.h"
#include "processo.h"
#include "menus.h"
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

/*
Os menus ficam aqui porque sao apenas representacoes graficas
pra guiar o usuario.
Deixa-los separados aqui deixa o main mais limpo do que juntar tudo sem
modularizacao
*/
void schedMainMenu() {
	int iInput; 	    //entrada
	int iQtdProcessos;	//pra iniciar o programa
	cout << "+----------------------------+\n";
	cout << "|     Escalonador Simples    |\n";
	cout << "+----------------------------+\n";
	cout << "|   Selecione um algoritmo   |\n";
	cout << "|                            |\n";
	cout << "| 1. FIFO                    |\n";
	cout << "| 2. SJF                     |\n";
	cout << "| 3. Sobre                   |\n";
	cout << "| 4. Sair                    |\n";
	cout << "|                            |\n";
	cout << "| Build: 0.1.0               |\n";
	cout << "+----------------------------+\n";
	cout << "> ";
	cin >> iInput;
	
	
	switch (iInput) {
		case 1: //FIFO
			system("cls");
			cout << "Digite o numero de processos: ";
			cin >> iQtdProcessos;
				if (iQtdProcessos > 0) {
					auto aProcessos = schedProcessDefine(iQtdProcessos); //inicio
					schedFIFO(aProcessos);
				}
				else {
					cout << "Insira ao menos 1 processo!!" << endl;
				}
		break;
		
		case 2: //SJF
			system("cls");
			cout << "Digite o numero de processos: ";
			cin >> iQtdProcessos;
				if (iQtdProcessos > 0) {
					auto aProcessos = schedProcessDefine(iQtdProcessos); //inicio
					schedSJF(aProcessos);
				}
				else {
					cout << "Insira ao menos 1 processo!!" << endl;
				}
		break;
		
		case 3: //SOBRE
			system("cls");
			schedAboutLang();
		break;
		
		case 4: //SAIR
			cout << "Saindo.." << endl;
			sleep_for(seconds(2));
			exit(0);
		break;
	}	
	
}

void schedAboutLang() {
	int iInput;
	cout << "+----------------------------+\n";
	cout << "|     Escalonador Simples    |\n";
	cout << "+----------------------------+\n";
	cout << "| Selecione um idioma:       |\n";
	cout << "|                            |\n";
	cout << "| 1. Portugues-BR            |\n";
	cout << "| 2. English-US              |\n";
	cout << "+----------------------------+\n";
	cout << "> ";
	cin >> iInput;
	
	
	switch (iInput) {
		case 1:
			system("cls");
			schedAboutMenuBR();
		break;
		
		case 2:
			system("cls");
			schedAboutMenuEN();
		break;
	}	
	
}

int schedAboutMenuBR() {
	string sLinha;
	
	cout << "Escalonador Simples em C++" << endl;
	cout << "\n";
	ifstream sobre("./src/sobre.txt");
	
    if (!sobre) { //caso de erros
        cerr << "Erro ao tentar abrir arquivo." << endl;
        return 1;
    }	
	
	//exibe caractere por caractere no for
    while (getline(sobre, sLinha)) {
       for (char c : sLinha) {
            cout << c;
            cout.flush();
            sleep_for(milliseconds(10));
        }      
        cout << endl;
    }	
	
	cout << endl;
    sobre.close();
    system("pause");
    system("cls");
    schedMainMenu();
    return 0;
}

int schedAboutMenuEN() {
	string sLinha;
	
	cout << "Simple Scheduler in C++" << endl;
	cout << "\n";
	ifstream sobre("./src/about-en.txt");
	
    if (!sobre) { //caso de erros
        cerr << "ERR when trying to open txt file." << endl;
        return 1;
    }	
	
	//exibe caractere por caractere no for
    while (getline(sobre, sLinha)) {
       for (char c : sLinha) {
            cout << c;
            cout.flush();
            sleep_for(milliseconds(10));
        }      
        cout << endl;
    }	
	
	cout << endl;
    sobre.close();
    system("pause");
    system("cls");
    schedMainMenu();
    return 0;
}