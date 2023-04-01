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

int isEmptyList(list L){
    int result = 1;

    if(L.first != NULL){
        result = 0;
    }

    return result;
}

void addFirst(process proses, list *L){

    element *new = (element*) malloc (sizeof(element));

    new->container = proses;

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
    new = NULL;
}

void addBefore(process proses, element* after, list *L){

    if (after != NULL){
        element* new = (element*) malloc (sizeof(element));

        new->container = proses;

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
        new = NULL;
    }
}

void addAfter (process proses, element* before, list *L){

    if (before != NULL){

        element* new = (element*) malloc (sizeof(element));

        new->container = proses;

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

void addLast (process proses, list *L){

    if (L->first == NULL){
        
        addFirst(proses, L);
    }
    else{

        addAfter(proses, L->tail, L);
    }
}

void addSortByBurstTime(process proses, int methode, list *L){

    if(L->first == NULL){
        addFirst(proses, L);
    }
    else if(L->first == L->tail){
        if(methode == 0){
            if(L->first->container.burst_time < proses.burst_time) addLast(proses, L);
            else addFirst(proses, L);
        }
        else{
            if(L->first->container.burst_time > proses.burst_time) addLast(proses, L);
            else addFirst(proses, L);
        }

    }
    else{

        if ((L->first->container.burst_time > proses.burst_time) && (methode == 0)) addFirst(proses, L);
        else if ((L->tail->container.burst_time < proses.burst_time) && (methode == 0)) addLast(proses, L);
        else if ((L->first->container.burst_time < proses.burst_time) && (methode == 1)) addFirst(proses, L);
        else if((L->tail->container.burst_time > proses.burst_time) && (methode == 1)) addLast(proses, L);
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
                if((pointerStart->next->container.burst_time > proses.burst_time) && (methode == 0)){
                    addAfter(proses, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.burst_time < proses.burst_time) && (methode == 0)){
                    addBefore(proses, pointerEnd, L);
                    break;
                }
                else if((pointerStart->next->container.burst_time < proses.burst_time) && (methode == 1)){
                    addAfter(proses, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.burst_time > proses.burst_time) && (methode == 1)){
                    addBefore(proses, pointerEnd, L);
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

void addSortByArrivalTime(process proses, int methode, list *L){

    if(L->first == NULL){
        addFirst(proses, L);
    }
    else if(L->first == L->tail){
        if(methode == 0){
            if(L->first->container.arrival_time < proses.arrival_time) addLast(proses, L);
            else addFirst(proses, L);
        }
        else{
            if(L->first->container.arrival_time > proses.arrival_time) addLast(proses, L);
            else addFirst(proses, L);
        }

    }
    else{

        if ((L->first->container.arrival_time > proses.arrival_time) && (methode == 0)) addFirst(proses, L);
        else if ((L->tail->container.arrival_time < proses.arrival_time) && (methode == 0)) addLast(proses, L);
        else if ((L->first->container.arrival_time < proses.arrival_time) && (methode == 1)) addFirst(proses, L);
        else if((L->tail->container.arrival_time > proses.arrival_time) && (methode == 1)) addLast(proses, L);
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
                if((pointerStart->next->container.arrival_time > proses.arrival_time) && (methode == 0)){
                    addAfter(proses, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.arrival_time < proses.arrival_time) && (methode == 0)){
                    addBefore(proses, pointerEnd, L);
                    break;
                }
                else if((pointerStart->next->container.arrival_time < proses.arrival_time) && (methode == 1)){
                    addAfter(proses, pointerStart, L);
                    break;
                }
                else if((pointerEnd->prev->container.arrival_time > proses.arrival_time) && (methode == 1)){
                    addBefore(proses, pointerEnd, L);
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

element* popFirst(list *L){
    element* pop = NULL;
    if (L->first != NULL){

        pop = L->first;
        if (countElement(*L) == 1){

            L->first = L->tail = NULL;
        }
        else{

            L->first = L->first->next;
            L->first->prev = NULL;
            pop->next = NULL;
        }
    }

    return pop;
}

element* popAfter(element* before, list* L){
    element* pop = NULL;
    if (before != NULL){

        pop = before->next;

        if (pop != NULL){

            if (pop->next == NULL){  //----| Bila yang dihapus di akhir

                before->next = NULL;
                L->tail = before;
            }
            else{

                before->next = pop->next;
                pop->next->prev = before;
                pop->next = NULL;
            }

            pop->prev = NULL;
        }
    }
    return pop;
}

element* popBefore(element* after, list* L){
    element* pop = NULL;
    if (after != NULL){
        if(after == L->first) pop = popFirst(L);
        else pop = popAfter(after->prev, L);
    }
    return pop;
}

element* popLast(list *L){
    element* pop = NULL;
    if (L->first != NULL){
        if (countElement (*L) == 1) pop = popFirst(L);
        else pop = popAfter (L->tail->prev, L);
    }

    return pop;
}

element* popByArrivalTime(int arrival_time, list *L){
    element* pop = NULL;

    if(L->first != NULL){

        if(L->first->container.arrival_time == arrival_time) pop = popFirst(L);
        else if(L->tail->container.arrival_time == arrival_time) pop = popLast(L);
        else{
            element* front_ptr = L->first;
            element* back_ptr = L->tail;
            while((front_ptr != back_ptr) && (front_ptr->prev != back_ptr)){
                if(front_ptr->next->container.arrival_time == arrival_time){
                    pop = popAfter(front_ptr, L);
                    break;
                }
                else if(back_ptr->prev->container.arrival_time == arrival_time){
                    pop = popBefore(back_ptr, L);
                    break;
                }
                else{
                    front_ptr = front_ptr->next;
                    back_ptr = back_ptr->prev;
                }
            }
        }

    }

    return pop;
}

int getShortestBurstTime(list L){
    int result = 999;

    if(L.first != NULL){
        element* front_ptr = L.first;
        element* back_ptr = L.tail;
        while((front_ptr != back_ptr) && (front_ptr->prev != back_ptr)){
            if(front_ptr->container.burst_time < result) result = front_ptr->container.burst_time;
            if(back_ptr->container.burst_time < result) result = back_ptr->container.burst_time;

            front_ptr = front_ptr->next;
            back_ptr = back_ptr->prev;
        }
    }

    return result;
}

void updateWaitingTimeForAllElement(int delta_waiting_time, list *L){

    if(L->first != NULL){
        element* front_ptr = L->first;
        element* back_ptr = L->tail;
        while((front_ptr != back_ptr) && (front_ptr->prev != back_ptr)){
            front_ptr->container.waiting_time += delta_waiting_time;
            back_ptr->container.waiting_time += delta_waiting_time;
            front_ptr = front_ptr->next;
            back_ptr = back_ptr->prev;
        }
    }
}