#include "SJFNonPreemptive.h"

int main(){

    table T;
    char colnames[4][15] = {"Prossess ID", "Burst Time", "Arrival Time", "Waiting Time"};
    char* p_array[4];
    for(int i = 0 ; i < 4; i++){
        p_array[i] = colnames[i];
    }
    createTable(p_array, (int)sizeof(p_array)/sizeof(p_array[0]), &T);

    process arr[1];
    arr[0].process_id = 1;
    arr[0].burst_time = 10;
    arr[0].waiting_time = 15;
    arr[0].arrival_time =100;

    for(int i = 0; i < 1; i++){
        char values[4][5];
        char temp[5];
        char* p_val[4];
        itoa(arr[i].process_id, temp, 5);
        strcpy(values[0], temp);
        itoa(arr[i].burst_time, temp, 5);
        strcpy(values[1], temp);
        itoa(arr[i].waiting_time, temp, 5);
        strcpy(values[2], temp);
        itoa(arr[i].arrival_time, temp, 5);
        strcpy(values[3], temp);
        for(int j = 0 ; j < 4; j++){
            p_val[j] = values[j];
        }
        addRow(p_val, &T);
    }
    printTable(&T);
    printf("\n");
    delAllRow(&T);
    char aaa[2][15] = {"Nama", "Nim"};
    char* bbb[2];
    for(int i = 0 ; i < 2; i++){
        bbb[i] = aaa[i];
    }
    createTable(bbb, (int)sizeof(bbb)/sizeof(bbb[0]), &T);
    char values[2][15] = {"Davin", "2100195"};
    char* www[2];
    for(int i = 0 ; i < 2; i++){
        www[i] = values[i];
    }
    addRow(www, &T);

    printTable(&T);

    return 0;
}