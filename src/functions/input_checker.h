//INPUT_CHECKER.H
#ifndef INPUT_CHECKER_H
#define INPUT_CHECKER_H

#include <iostream>
using namespace std;

template<typename T>
void input_checking(T& var) {
	while (!(cin >> var)) {
		cout << "Entrada invalida! Insira o solicitado!" << endl;
		cin.clear();
		cin.ignore(40, '\n');
	}
}

#endif