#include "header.h"

void cetakTape(int index, char arr[], char state){

    printf("----------------------------------\n   [");
    for (int i = 0; i < 7 - index; i++){
        printf("#");
    }
    printf("%s", arr);
    for(int i = 0; i < index ; i++){
        printf("#");
    }
    printf("]\n");
    printf("        ^\n");
    printf("      [State %c]", state);
    printf("----------------------------------\n");


}
void output(int index, char tape[], char state){
    int time = 1400;
    Sleep(time);
    system("cls");

    cetakTape(index, tape, state);
}