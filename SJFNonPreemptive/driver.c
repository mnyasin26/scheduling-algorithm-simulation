#include "SJFNonPreemptive.h"

// Fungsi untuk menghitung waktu tunggu dan waktu putaran untuk setiap proses
void calculate_times(process processes[], int num_processes);

void SJFNonPreemptive()
{
    int num_processes;
    printf("Masukkan jumlah proses: ");
    scanf("%d", &num_processes);

    // Alokasikan memori untuk array processes
    process *processes = (process *)malloc(num_processes * sizeof(process));

    // Masukkan detail proses
    for (int i = 0; i < num_processes; i++)
    {
        printf("Masukkan waktu burst untuk proses %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i + 1;
    }

    // Urutkan proses berdasarkan waktu burst
    sort_processes(&processes, num_processes);

    // Hitung waktu tunggu dan waktu putaran untuk setiap proses
    calculate_times(processes, num_processes);

    // Tampilkan detail proses
    printf("\nProses\tWaktu Burst\tWaktu Tunggu\tWaktu Putaran\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // cleaning
    free(processes);
    // return 0;
}

void calculate_times(process processes[], int num_processes)
{
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time = 0;

    for (int i = 0; i < num_processes; i++)
    {
        completion_time += processes[i].burst_time;
        processes[i].turnaround_time = completion_time;
        processes[i].waiting_time = total_waiting_time;
        total_waiting_time += processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Rata-rata waiting time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Rata-rata waktu turnaround time: %.2f\n", (float)total_turnaround_time / num_processes);
}

int main (){

    showUpAndDownside();

    list L;
    createList(&L);

    int n;
    n = insert_sjf_process(&L);

    simulate_sjf_process_execution(L, n);
}