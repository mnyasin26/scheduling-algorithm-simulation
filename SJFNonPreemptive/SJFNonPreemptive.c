
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

void insert_sjf_process(list *L){
    int n_process;
    printf("Masukkan jumlah process\n");
    scanf("%d", &n_process);
    process input;
    for(int i = 0 ; i < n_process; i++){
        printf("Masukkan burst-time dan arrival-time proses ke-%d", i+1);
        scanf("burst-time  : %d", &input.burst_time);
        scanf("arrival-time: %d", &input.arrival_time);
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
            if(cur_process->container.burst_time != 0) cur_process->container.burst_time -= 1;
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
            createTable(ptr_cur_table, 2, &outputTable);
            addRow(ptr_cur_table_val, &outputTable);
            printTable(&outputTable);
        }

        delAllRow(&outputTable);
        printf("\nProses dalam ready\n");
        createProsessTable(ready_queue, &outputTable);
        printTable(&outputTable);

        printf("\nProses yang sudah selesai\n");
        if(isEmptyList(finished_queque) == 0) printf("belum ada proses yang selesai");
        else{
            createProsessTable(finished_queque, &outputTable);
            printTable(&outputTable);
        }

        updateWaitingTimeForAllElement(1, &ready_queue);
    }

    

}

void showStatistic(list processes, int time){

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

    createTable(ptr_colnames, 4,&T);

    L = processes;
    int n_process = 0;
    int turn_around_time = 0;
    int wait_time = 0;
    while(isEmptyList(L) == 0){
        process temp = popFirst(&L)->container;
        n_process++;
        turn_around_time += temp.turnaround_time;
        wait_time += temp.waiting_time;
    }

    double thoughput = n_process / time;

    char row_val[3][5];
    char* ptr_row_val[3];
    for(int i = 0 ; i < 3 ; i++){
        ptr_row_val[i] = row_val[i];
    }

    char temp[5];
    itoa(turn_around_time, temp, 4);
    strcpy(row_val[0], temp);

    itoa(wait_time, temp, 4);
    strcpy(row_val[1], temp);

    itoa(thoughput, temp, 4);
    strcpy(row_val[2], temp);

    addRow(ptr_row_val, &T);
    
    printTable(&T);
    
}
