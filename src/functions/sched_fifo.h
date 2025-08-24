//FIFO H
#ifndef SCHED_FIFO_H
#define SCHED_FIFO_H

#include <vector>
#include "processo.h"

vector<Processo> schedProcessDefine(int iQtdProcessos);
void schedFIFO(const vector<Processo>& v_Processos);

#endif