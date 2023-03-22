#include "../header.h"

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
typedef struct  {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
}process;

void showStrenghtandWeaknesses();