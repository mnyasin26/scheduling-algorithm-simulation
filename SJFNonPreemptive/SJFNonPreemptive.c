#include <stdio.h>
#include <stdlib.h>

// Definisikan struktur Process untuk menyimpan informasi setiap proses
struct Process {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Fungsi untuk mengurutkan proses berdasarkan waktu pemrosesan terpendek
void sort_processes(struct Process processes[], int num_processes);

// Fungsi untuk menghitung waktu tunggu dan waktu putaran untuk setiap proses
void calculate_times(struct Process processes[], int num_processes);

int main() {
    int num_processes;
    printf("Masukkan jumlah proses: ");
    scanf("%d", &num_processes);

    // Alokasikan memori untuk array processes
    struct Process *processes = (struct Process*)malloc(num_processes * sizeof(struct Process));

    // Masukkan detail proses
    for(int i = 0; i < num_processes; i++) {
        printf("Masukkan waktu burst untuk proses %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i+1;
    }

    // Urutkan proses berdasarkan waktu burst
    sort_processes(processes, num_processes);

    // Hitung waktu tunggu dan waktu putaran untuk setiap proses
    calculate_times(processes, num_processes);

    // Tampilkan detail proses
    printf("\nProses\tWaktu Burst\tWaktu Tunggu\tWaktu Putaran\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // cleaning
    free(processes);
    return 0;
}

void sort_processes(struct Process processes[], int num_processes) {
    struct Process temp;
    for(int i = 0; i < num_processes; i++) {
        for(int j = i+1; j < num_processes; j++) {
            if(processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void calculate_times(struct Process processes[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time = 0;

    for(int i = 0; i < num_processes; i++) {
        completion_time += processes[i].burst_time;
        processes[i].turnaround_time = completion_time;
        processes[i].waiting_time = total_waiting_time;
        total_waiting_time += processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Rata-rata waiting time: %.2f\n", (float)total_waiting_time / num_processes);
    printf("Rata-rata waktu turnaround time: %.2f\n", (float)total_turnaround_time / num_processes);
}
