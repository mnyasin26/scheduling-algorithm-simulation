
#include "SJFNonPreemptive.h"

void showUpAndDownside(){

    table T;
    char colnames[2][100] = {"Kelebihan", "Kekurangan"};
    char* ptr_colnames[2];
    for(int i = 0 ; i < 2; i++){
        ptr_colnames[i] = colnames[i];
    }
    createTable(ptr_colnames, 2, &T);

    // reuse colnames as row values;
    strcpy(colnames[0], "Rata-rata waiting time paling minimum");
    strcpy(colnames[1], "Dapat terjadi kelaparan (starvation)");
    addRow(ptr_colnames, &T);

    strcpy(colnames[0], "diantara seluruh algoritma penjadwalan");
    strcpy(colnames[1], "bila proses lebih pendek terus berdatangan");
    addRow(ptr_colnames, &T);

    printTable(&T);
}

int insert_sjf_process(list *L){
    int n_process;
    printf("Masukkan jumlah process\n");
    scanf("%d", &n_process);
    process input;
    for(int i = 0 ; i < n_process; i++){
        printf("Masukkan burst-time dan arrival-time proses ke-%d\n", i+1);
        printf("burst-time  : ");
        scanf("%d", &input.burst_time);
        printf("arrival-time: ");
        scanf("%d", &input.arrival_time);
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

    table outputTable;

    int temp_burst;

    while(countElement(finished_queque) != n_process){
        Sleep(1000);
        time_tracker++;
        printf("Time:  %d\n", time_tracker);

        // Add element into the ready queue
        element* check = NULL;
        do{
            check = popByArrivalTime(time_tracker, &processes_list);
            if(check != NULL){
                addSortByBurstTime(check->container, 0, &ready_queue);
            }
        }while(check != NULL);

        //insert process into the running-state
        if(cur_process == NULL){
            cur_process = popFirst(&ready_queue);
            temp_burst = cur_process->container.burst_time;
        }
        // Process the state inside the running state
        else{
            if(cur_process->container.burst_time != 0) cur_process->container.burst_time -= 1;
            else{
                cur_process->container.turnaround_time = time_tracker - cur_process->container.arrival_time;
                cur_process->container.burst_time = temp_burst;
                addLast(cur_process->container, &finished_queque);
                cur_process = NULL;
            }
        }

        updateWaitingTimeForAllElement(1, &ready_queue);

        // If there's a process inisde running-state
        if(cur_process != NULL){
            char cur_table_col[2][25] = {"Current process", "Remaining burst time"};
            char* ptr_cur_table[2];
            char temp_val[5];
            char cur_table_val[2][5];
            char* ptr_cur_table_val[2];
            for(int i = 0 ; i < 2; i++){
                ptr_cur_table[i] = cur_table_col[i];
                strcpy(cur_table_val[0], itoa(cur_process->container.process_id, temp_val, 5));
                strcpy(cur_table_val[1], itoa(cur_process->container.burst_time, temp_val, 5));
                ptr_cur_table_val[i] = cur_table_val[i]; 
            }
            createTable(ptr_cur_table, 2, &outputTable);
            addRow(ptr_cur_table_val, &outputTable);
            printTable(&outputTable);
        }

        //Output the process in ready-state
        delAllRow(&outputTable);
        printf("\nProses dalam ready\n");
        if(isEmpty(ready_queue) == 1) printf("Ready Queue kosong\n");
        else{
            createProsessTable(ready_queue, &outputTable);
            printTable(&outputTable);
        }

        printf("\nProses yang sudah selesai\n");
        if(isEmpty(finished_queque) == 1) printf("belum ada proses yang selesai\n");
        else{
            createProsessTable(finished_queque, &outputTable);
            printTable(&outputTable);
        }

    }
    printf("Pemrosesan selesai\n");

    showStatistic(finished_queque, time_tracker);

}

void showStatistic(list processes, int waktu){

    printf("Statistic\n");

    table T;
    list L;

    char colnames[3][25] = {
        "Average Turn Around Time",
        "Average Wait Time",
        "Throughput"
    };
    char* ptr_colnames[3];
    for(int i = 0 ; i < 3; i++){
        ptr_colnames[i] = colnames[i];
    }

    createTable(ptr_colnames, 3,&T);

    L = processes;
    int n_process = 0;
    int turn_around_time = 0;
    int wait_time = 0;
    while(isEmpty(L) == 0){
        process temp = popFirst(&L)->container;
        n_process++;
        turn_around_time += temp.turnaround_time;
        wait_time += temp.waiting_time;
    }

    double thoughput = (double)n_process / waktu;

    char row_val[3][10];
    char* ptr_row_val[3];
    for(int i = 0 ; i < 3 ; i++){
        ptr_row_val[i] = row_val[i];
    }

    char temp[5];
    itoa(turn_around_time / n_process, temp, 4);
    strcpy(row_val[0], temp);

    itoa(wait_time / n_process, temp, 4);
    strcpy(row_val[1], temp);

    snprintf(temp, 10, "%0.2f", thoughput);
    strcpy(row_val[2], temp);

    addRow(ptr_row_val, &T);
    
    printTable(&T);
    
}
