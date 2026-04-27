#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void modificar(int **Mat, int M, int N, int Control_val, int Critic[3]);
void calibracao(int **Mat, int M, int N, int Critic[3]);
void saturacao(int **Mat, int M, int N, int Critic[3]);
void amplificador(int **Mat, int M, int N, int Critic[3]);
void printMat(int **Mat, int M, int N);
void checkNull(void *Pointer);
void checkNullMat(int ***Mat, int Current_index);
void matMake(int ***Mat, int M, int N);
void getValues(int **Mat, int M, int N);
void freeMat(int ***Mat, int M);

int main(void){
    int M, N; scanf("%d %d", &M, &N);
    int **Mat = NULL;

    matMake(&Mat, M, N);

    int Critic[3] = {0};

    int Control_val = -1;
    while((scanf("%d", &Control_val)) && (Control_val != 0)){
        modificar(Mat, M, N, Control_val, Critic);
    }

    printf("Matriz processada:\n");
    printMat(Mat, M, N);
    printf("\n");
    printf("Sensor critico: %d\nPosicao: (%d,%d)\n", Critic[0], Critic[1], Critic[2]);

    freeMat(&Mat, M);
    return 0;
}

void modificar(int **Mat, int M, int N, int Control_val, int Critic[3]){
    void (*Filtro[3])(int** , int, int, int*) = {calibracao, saturacao, amplificador};

    if((Control_val>=1)&&(Control_val<=3)){
        Filtro[Control_val-1](Mat, M, N, Critic);
    }else if(Control_val == 4){
        int Repeat_amount = 0; scanf("%d", &Repeat_amount);

        for(int i = 0; i<Repeat_amount; i++){
            scanf("%d", &Control_val);
            Filtro[Control_val-1](Mat, M, N, Critic);
        }
    }
}
void calibracao(int **Mat, int M, int N, int Critic[3]){
    int Biggest = -99999;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            Mat[i][j] = Mat[i][j]+5;
            if(Mat[i][j]>Biggest){
                Critic[0] = Mat[i][j];
                Critic[1] = i;
                Critic[2] = j;
                Biggest = Mat[i][j];
            }
        }
    }
}
void saturacao(int **Mat, int M, int N, int Critic[3]){
    int Biggest = -99999;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            if(Mat[i][j]>80){
                Mat[i][j] = 80;
            }
            if(Mat[i][j]>Biggest){
                Critic[0] = Mat[i][j];
                Critic[1] = i;
                Critic[2] = j;
                Biggest = Mat[i][j];
            }
        }
    }
}
void amplificador(int **Mat, int M, int N, int Critic[3]){
    int Biggest = -99999;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            Mat[i][j] = Mat[i][j]*2;
            if(Mat[i][j]>Biggest){
                Critic[0] = Mat[i][j];
                Critic[1] = i;
                Critic[2] = j;
                Biggest = Mat[i][j];
            }
        }
    }
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
    int **TEMPMAT = realloc((*Mat), M*sizeof(*(*Mat)));
    checkNull(TEMPMAT);
    (*Mat) = TEMPMAT;

    for(int i = 0; i<M; i++){
        (*Mat)[i] = calloc(N, sizeof(*(*Mat)[i]));
        if((*Mat)[i] == NULL){
            checkNullMat(&(*Mat), i);
        }
    }

    getValues((*Mat), M, N);
}
void getValues(int **Mat, int M, int N){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &Mat[i][j]);
        }
    }
}
void freeMat(int ***Mat, int M){
    for(int i = 0; i<M; i++){
        free((*Mat)[i]);
    }
    free((*Mat));
}