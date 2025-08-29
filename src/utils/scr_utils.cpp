//SCREEN CLEANER CPP
/*
Função específica para limpar e pausar o console
dependendo do sistema operacional.
A checagem é feita em tempo de compilação.
*/
#include <iostream>
#include <cstdlib>
#include "scr_utils.h"
using namespace std;

void clscreen() {
	
	#ifdef _WIN32
	system("cls");
	
	#else 
	system("clear");
	
	#endif
} 

void waitscreen() {
	
	#ifdef _WIN32
	system("pause");
	
	#else 
	system("read -n 1 -s -r -p \"Press any key to proceed...\"");
	
	#endif
} 