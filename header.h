#pragma once

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/**
 * @brief 
 * 
 * process, struct untuk
 * menampung data-data yang dimiliki
 * sebuah proses.
 * Variabel tidak perlu diisi semua,
 * isi / pakai yang dibutuhkan saja
 * - Dai Fuin
 */
typedef struct {
    int process_id;
    int priority; // prioritas proses
    int burst_time;
    int burstTimeLeft; // buat priority scheduling
    int arrival_time;
    int waiting_time;
    int turnaround_time;
}process;

void cetakTape(int index, char arr[], char state);
void output(int index, char tape[], char state);

void FCFS();
void SJFPreemptive();
void SJFNonPreemptive();
void RoundRobin();
void PrioSchedulingPreemptive();
void PrioSchedulingNonPreemptive();