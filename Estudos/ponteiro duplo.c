#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void checkNull(void *POINTER){

    if(POINTER == NULL){
        printf("Erro de memória.\n");
        exit(1);
    }

}
void checkNullMat(void *VET, int **MAT, int SIZE){
    if(VET == NULL){
        for(int i = SIZE-1; i>=0; i--){
            free(MAT[i]);
        }
        free(MAT);
        exit(1);
    }
}

void printMat(int **NUMS, int SIZE, int *INDSIZE){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<INDSIZE[i]; j++){
            printf("%d ", NUMS[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){

    int SIZE = 10, *INDSIZE = calloc(SIZE, sizeof(*INDSIZE));
    int **NUMS = calloc(SIZE, sizeof(*NUMS));
    checkNull(NUMS); checkNull(INDSIZE);

    for(int i = 0; i<SIZE; i++){
        INDSIZE[i] = 20;
        NUMS[i] = calloc(INDSIZE[i], sizeof(*NUMS[i]));
        if(i == 1){
            NUMS[i] = NULL;
        }
        checkNullMat(NUMS[i], NUMS, i);
    }

    NUMS[3][6] = 3; NUMS[3][7] = 9; NUMS[9][19] = 81;

    printMat(NUMS, SIZE, INDSIZE);

    int *TEMPOINTER = realloc(NUMS[3], 30 * sizeof(*NUMS[3]));
    checkNull(TEMPOINTER);
    NUMS[3] = TEMPOINTER;
    NUMS[3][29] = 9999; INDSIZE[3] = 30;

    SIZE++;
    TEMPOINTER = realloc(INDSIZE, SIZE * sizeof(*INDSIZE));
    checkNull(TEMPOINTER);
    INDSIZE = TEMPOINTER;
    INDSIZE[SIZE-1] = 20;

    int **TEMPOINTER2 = realloc(NUMS, SIZE * sizeof(*NUMS));
    checkNull(TEMPOINTER2);
    NUMS = TEMPOINTER2;
    NUMS[SIZE-1] = calloc(INDSIZE[SIZE-1], sizeof(*NUMS[SIZE-1]));
    checkNull(NUMS[SIZE-1]);

    printMat(NUMS, SIZE, INDSIZE);

    for(int i = 0; i<SIZE; i++){
        free(NUMS[i]);
    }
    free(INDSIZE); 
    free(NUMS); 

    return 0;
}