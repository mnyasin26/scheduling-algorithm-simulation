#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void cetakTape(int index, char arr[], char state);
void output(int index, char tape[], char state);

void FCFS();
void SJFPreemptive();
void SJFNonPreemptive();
void RoundRobin();
void PrioSchedulingPreemptive();
void PrioSchedulingNonPreemptive();