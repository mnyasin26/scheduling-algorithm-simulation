#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "../header.h"
#include "listGanda.h"
#include "table.h"

void showUpAndDownside();

int insert_sjf_process(list *L);

/**
 * @brief mengurutkan array of processes
 * 
 * @param processes 
 * @param num_processes 
 * @author Ridho
 */
void sort_processes(process** processes, int num_processes);

void simulate_sjf_process_execution(list p, int n_process);

void showStatistic(list processes, int time);