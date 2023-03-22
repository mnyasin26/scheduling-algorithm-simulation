#include "listGanda.h"


void createList (list *L){

    L->first = NULL; //--| first dan tail berisi NULL, membuat list kosong
    L->tail = NULL;  //--|
}

int countElement(list L){

    int result = 0;

    if(L.first != NULL){

        element *pointer = L.first;

        while( pointer != NULL){

            result++;
            pointer = pointer->next;
        }

    }

    return result;
}

void addFirst(listVar, list *L){

    element *new = (element*) malloc (sizeof(element));

    new->container.burst_time = burst_time;
    new->container.arrival_time = arrival_time;

    if (L->first == NULL){

        new->prev = NULL;
        new->next = NULL;

        L->tail = new;
    }
    else{

        new->next = L->first;
        new->prev = NULL;

        L->first->prev = new;
    }

    L->first = new;
    new->container.process_id = countElement(*L);
    new = NULL;
}

void addAfter (listVar, element* before, list *L){

    if (before != NULL){

        element* new = (element*) malloc (sizeof(element));

        new->container.burst_time = burst_time;
        new->container.arrival_time = arrival_time;

        if (before->next == NULL){

            new->next = NULL;
            L->tail = new;
        }
        else{

            new->next = before->next;
            new->next->prev = new;
        }

        new->prev = before;
        before->next = new;
        new->container.process_id = countElement(*L);
        new = NULL;
    }
}

void addBefore (listVar, element* after, list *L){

    if (after != NULL){
        element* new = (element*) malloc (sizeof(element));

        new->container.burst_time = burst_time;
        new->container.arrival_time = arrival_time;

        if(after->prev == NULL){

            new->prev = NULL;
            L->first = new;
        }
        else{

            new->prev = after->prev;
            new->prev->next = new;
        }

        new->next = after;
        after->prev = new;
        new->container.process_id = countElement(*L);
        new = NULL;
    }
}

void addLast (listVar, list *L){

    if (L->first == NULL){
        
        addFirst(data1, data2, L);
    }
    else{

        addAfter(data1, data2, L->tail, L);
    }
}

void addSortByBurstTime(listVar, int methode, list *L){

    if(L->first == NULL){
        addFirst(data1, data2, L);
    }
    else if(L->first == L->tail){
        if(methode == 0){
            if(L->first->container.burst_time < burst_time) addLast(data1, data2, L);
            else addFirst(data1, data2, L);
        }
        else{
            if(L->first->container.burst_time > burst_time) addLast(data1, data2, L);
            else addFirst(data1, data2, L);
        }

    }
    else{

        if ((L->first->container.burst_time > burst_time) && (methode == 0)) addFirst(data1, data2, L);
        else if ((L->tail->container.burst_time < burst_time) && (methode == 0)) addLast(data1, data2, L);
        else if ((L->first->container.burst_time < burst_time) && (methode == 1)) addFirst(data1, data2, L);
        else if((L->tail->container.burst_time > burst_time) && (methode == 1)) addLast(data1, data2, L);
        else{
            element* pointerStart = L->first;
            element* pointerEnd = L->tail;

            /**
             * @brief 
             * Ascending
             */
            while(
                (pointerEnd != pointerStart) &&
                (pointerStart->prev != pointerEnd)
            ){
                if((pointerStart->next->container.burst_time > burst_time) && (methode == 0)){
                    addAfter(data1, data2, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.burst_time < burst_time) && (methode == 0)){
                    addBefore(data1, data2, pointerEnd, L);
                    break;
                }
                else if((pointerStart->next->container.burst_time < burst_time) && (methode == 1)){
                    addAfter(data1, data2, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.burst_time > burst_time) && (methode == 1)){
                    addBefore(data1, data2, pointerEnd, L);
                    break;
                }
                else{
                    pointerStart = pointerStart->next;
                    pointerEnd = pointerEnd->prev;
                }
            }
        }

    }
    

}

void delFirst (list *L){

    if (L->first != NULL){

        element* delete = L->first;
        if (countElement(*L) == 1){

            L->first = L->tail = NULL;
        }
        else{

            L->first = L->first->next;
            L->first->prev = NULL;
            delete->next = NULL;
        }

        free(delete);
    }
}

void delAfter (element* before, list *L){

    if (before != NULL){

        element* delete = before->next;

        if (delete != NULL){

            if (delete->next == NULL){  //----| Bila yang dihapus di akhir

                before->next = NULL;
                L->tail = before;
            }
            else{

                before->next = delete->next;
                delete->next->prev = before;
                delete->next = NULL;
            }

            delete->prev = NULL;
            free(delete);
        }
    }
}

void delLast (list *L){

    if (L->first != NULL){
        if (countElement (*L) == 1){  //--| Jika list hanya terdiri dari satu element

            delFirst(L);
        }
        else{ //--------------------------| Jika list terdiri dari banyak element, delete akhir

            delAfter (L->tail->prev, L);
        }
    }
}

void delAll (list *L){

    if (countElement(*L) != 0){

        int i;
        for(i = countElement(*L); i > 0; i--){
            delLast(L);
        }
    }
}

void printElement (list L){

    if (L.first != NULL){

        element* pointer = L.first;
        /*--------*/

        printf("===================\n");
        while ( pointer != NULL){

            
            printf("%s %s %s\n", pointer->container.data1, pointer->container.data2, pointer->container.data3);

            pointer = pointer->next;
        }
    }
    else{

        printf("===================\n");
        printf("List Kosong\n");
    }
}

void printElementRev(list L){

    if (L.first != NULL){

        element* pointer = L.tail;

        printf("===================\n");
        while (pointer != NULL){
            
            printf("%s %s %s\n", pointer->container.data1, pointer->container.data2, pointer->container.data3);

            pointer = pointer->prev;
        }
    }
    else{

        printf("===================\n");
        printf("List Kosong\n");
    }
}
/*
void containerSwap (datas *a, datas *b){
    datas temp = *a;
    *a = *b;
    *b = temp;
}

void inputSwicth(list *L){

    char input1[nData1];
    char input2[nData2];
    char input3[nData3];

    scanf("%s ", input1);
    while(strcmp(input1, "-") != 0){

        scanf("%s %s", input2, input3);

        if(L->first == NULL){

            addFirst(input1, input2, input3, L);
        }
        else{
            if(countElement(*L) == 1){

                addLast(input1, input2, input3, L);
            }
            else{

                element* front = L->first;
                element* back = L->tail;
                
                while (front->next != L->tail){
                    front = front->next;
                }

                while (back->prev != front){
                    back = back->prev;
                }

                if (countElement(*L) % 2 == 0){

                    addAfter(input1, input2, input3, front, L);
                }
                else{

                    addBefore(input1, input2, input3, back, L);
                }
            }
        }

        scanf("%s", input1);
    }   
}
*/
