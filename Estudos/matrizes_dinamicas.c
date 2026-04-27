#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printMat(int **Mat, int M, int N);
void checkNull(void *Pointer);
void checkNullMat(int ***Mat, int Current_index);
void matMake(int ***Mat, int M, int N);
void getValues(int ***Mat, int M, int N);
void freeMat(int ***Mat, int M);

int main(void){


    return 0;
}

void printMat(int **Mat, int M, int N){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}
void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}
void checkNullMat(int ***Mat, int Current_index){
    for(int i = Current_index-1; i>=0; i--){
        free((*Mat)[i]);
    }
    free((*Mat));
}
void matMake(int ***Mat, int M, int N){
    int **TEMPOINTER = realloc((*Mat), M*sizeof(*(*Mat)));
    checkNull(TEMPOINTER);
    (*Mat) = TEMPOINTER;

    for(int i = 0; i<M; i++){
        (*Mat)[i] = calloc(N, sizeof(*(*Mat)[i]));
        if((*Mat)[i] == NULL){
            checkNullMat(&(*Mat), i);
        }
    }
}
void getValues(int ***Mat, int M, int N){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &(*Mat)[i][j]);
        }
    }
}
void freeMat(int ***Mat, int M){
    for(int i = 0; i<M; i++){
        free((*Mat)[i]);
    }
    free((*Mat));
}