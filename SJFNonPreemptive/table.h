#include "../header.h"
#include "SJFNonPreemptive.h"
#include <malloc.h>

void printTable(char **colname, process prosesses[]){

    int n_col = sizeof(colname) / sizeof(colname[0]);
    int* max_col_len = (int*)calloc(n_col, sizeof(int));

    for(int i = 0; i < n_col; i++){
        /**
         * get max len of each col
         * 
         */
    }

    /**
     * table printing here
     * 
     */
}