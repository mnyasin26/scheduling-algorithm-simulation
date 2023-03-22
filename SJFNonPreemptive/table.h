#pragma once

#include "../header.h"
#include <malloc.h>

void printTable(char *colname[], process prosesses[]);

void printTableForProcesses(process *Processes, int n_processes);

void printTableLine(int *max_col_len, int n_col);


