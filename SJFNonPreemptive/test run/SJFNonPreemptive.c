
#include "SJFNonPreemptive.h"

void insert_sjf_Process(int* n,list *L){
    int n_process;
    printf("Masukkan jumlah process\n");
    scanf("%d", &n_process);
    process input;
    for(int i = 0 ; i < n_process; i++){
        printf("Masukkan burst-time dan arrival-time proses ke-%d\n", i+1);
        printf("burst-time: "); scanf("%d", &input.burst_time);
        printf("arrival-time: "); scanf("%d", &input.arrival_time);
        input.process_id = i+1;
        input.waiting_time = 0;
        input.turnaround_time = 0;
        if(input.arrival_time < 1){
            printf("Gak boleh lebih kecil sama dengan 0");
            break;
        }
        else{
            addSortByArrivalTime(input, 0, L);
        }
    }
    *n = n_process;
}

void sort_processes(process** processes, int num_processes) {
    process* temp;
    for(int i = 0; i < num_processes; i++) {
        for(int j = i+1; j < num_processes; j++) {
            if(processes[i]->burst_time > processes[j]->burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    free(temp);
}

void simulate_sjf_process_execution(list p, int n_process){

    int time_tracker = 0;
    element* cur_process = NULL;
    list processes_list = p;
    list ready_queue;
    list finished_queque;
    createList(&ready_queue);
    createList(&finished_queque);

    while(countElement(finished_queque) != n_process){
        Sleep(1000);
        time_tracker++;
        printf("Time:  %d\n", time_tracker);

        element* check = NULL;
        do{
            check = popByArrivalTime(time_tracker, &processes_list);
            if(check != NULL){
                addSortByBurstTime(check->container, 0, &ready_queue);
            }
        }while(check != NULL);

        if(cur_process == NULL){
            cur_process = popFirst(&ready_queue);
        }
        else{
            if(cur_process->container.burst_time > 0) cur_process->container.burst_time -= 1;
            else{
                cur_process->container.turnaround_time = time_tracker - cur_process->container.arrival_time;
                addLast(cur_process->container, &finished_queque);
                cur_process = NULL;
            }
        }

        if(cur_process != NULL){
            char cur_table_col[2][25] = {"Current process", "Remaining burst time"};
            char* ptr_cur_table[2];

            char temp_val[5];
            char cur_table_val[2][5];
            char* ptr_cur_table_val[2];

            for(int i = 0 ; i < 2; i++){
                ptr_cur_table[i] = cur_table_col[i];
                strcpy(cur_table_val[i], itoa(cur_process->container.process_id, temp_val, 5));
                ptr_cur_table_val[i] = cur_table_val[i]; 
            }
            table cur_pro_table;
            createTable(ptr_cur_table, 2, &cur_pro_table);
            addRow(ptr_cur_table_val, &cur_pro_table);
            printTable(&cur_pro_table);
        }
        //
        // problems starts here
        //
        printf("\nProses dalam ready\n");
        if(isEmpty(ready_queue) == 0){
            table ready_table;
            createProsessTable(ready_queue, &ready_table);
            printTable(&ready_table);
        }
        else{
            printf("Queue sedang kosong\n");
        }

        printf("\nProses yang sudah selesai\n");
        if(isEmpty(finished_queque) == 1) printf("belum ada proses yang selesai\n");
        else{
            table finished_table;
            createProsessTable(finished_queque, &finished_table);
            printTable(&finished_table);
        }
        printf("\n");

        updateWaitingTimeForAllElement(1, &ready_queue);
    }

    

}
