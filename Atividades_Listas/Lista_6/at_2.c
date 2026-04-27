#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void explosaoArcana(int ***Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]);
void nuvemVenenosa(int ***Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]);
void matCopy(int **Mat, int ***Mat_copy, int M, int N);
void checkNull(void *Pointer);
void checkNullMat(int ***Mat, int Current_index);
void printMat(int **Mat, int M, int N);
void matAllocate(int ***Mat, int M, int N);
void getInput(int **Mat, int M, int N);
void freeMat(int ***Mat, int M);

int main(void){

    int M, N; scanf("%d %d", &M, &N);
    int **Mat = NULL;
    int **Mat_copy = NULL;

    matAllocate(&Mat, M, N);
    getInput(Mat, M, N);
    matCopy(Mat, &Mat_copy, M, N);
    printf("Estado inicial do mapa:\n");
    printMat(Mat, M, N);
    printf("\n");

    int Centro_X, Centro_Y; scanf("%d %d", &Centro_X, &Centro_Y);

    int Camada_1[5][2] = {{Centro_X, Centro_Y}, {Centro_X-1, Centro_Y}, {Centro_X+1, Centro_Y}, {Centro_X, Centro_Y-1}, {Centro_X, Centro_Y+1}};
    int Camada_2[16][2] = {{Centro_X-1, Centro_Y-1}, {Centro_X-1, Centro_Y+1}, {Centro_X-2, Centro_Y-1}, {Centro_X-2, Centro_Y+1}, {Centro_X+1, Centro_Y-1}, {Centro_X+1, Centro_Y+1}, {Centro_X+2, Centro_Y-1}, {Centro_X+2, Centro_Y+1}, {Centro_X-2, Centro_Y}, {Centro_X+2, Centro_Y}, {Centro_X-1, Centro_Y-2}, {Centro_X+1, Centro_Y-2}, {Centro_X-1, Centro_Y+2}, {Centro_X+1, Centro_Y+2}, {Centro_X, Centro_Y-2}, {Centro_X, Centro_Y+2}};

    char ATAQUE[16] = {'\n'}; scanf("%15s", ATAQUE);

    void (*Funct_pointer[2])(int***, int, int, int (*)[2], int (*)[2]) = {explosaoArcana, nuvemVenenosa}; int k = -1;
    if(strcmp(ATAQUE, "EXPLOSAO_ARCANA") == 0){
        k = 0;
    }else if(strcmp(ATAQUE, "NUVEM_VENENOSA") == 0){
        k = 1;
    }
    Funct_pointer[k](&Mat_copy, M, N, Camada_1, Camada_2);

    freeMat(&Mat, M);
    freeMat(&Mat_copy, M);
    return 0;
}

void explosaoArcana(int ***Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]){
    printf("Estado do mapa após usar a Explosão Arcana:\n");
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){

            int cont = 0;

            if(cont == 0){
                for(int k = 0; k<5; k++){
                    if((i==Camada_1[k][0])&&(j==Camada_1[k][1])){
                        (*Mat)[i][j] = (*Mat)[i][j]-50;
                        cont = 1;
                        break;
                    }
                }
            }
            if(cont == 0){
                for(int k = 0; k<16; k++){
                    if((i==Camada_2[k][0])&&(j==Camada_2[k][1])){
                        (*Mat)[i][j] = (*Mat)[i][j]-25;
                        break;
                    }
                }
            }

            if((*Mat)[i][j]<0){
                (*Mat)[i][j] = 0;
            }
        }
    }
    printMat((*Mat), M, N);
}

void nuvemVenenosa(int ***Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]){
    printf("Estado do mapa, por turno, após usar a Nuvem Venenosa:\n");
    for(int z = 0; z<3; z++){

        int END = 1;

        int **Mat_copy_2 = NULL;
        matCopy((*Mat), &Mat_copy_2, M, N);


        for(int i = 0; i<M; i++){
            for(int j = 0; j<N; j++){

                int cont = 0, vizinhos = 0;

                if(((i-1>=0)&&(i-1<M))&&((*Mat)[i-1][j]>0)){
                    vizinhos++;
                }
                if(((i+1>=0)&&(i+1<M))&&((*Mat)[i+1][j]>0)){
                    vizinhos++;
                }
                if(((j-1>=0)&&(j-1<N))&&((*Mat)[i][j-1]>0)){
                    vizinhos++;
                }
                if(((j+1>=0)&&(j+1<N))&&((*Mat)[i][j+1]>0)){
                    vizinhos++;
                }
                if(((i-1>=0)&&(i-1<M)&&(j-1>=0)&&(j-1<N))&&((*Mat)[i-1][j-1]>0)){
                    vizinhos++;
                }
                if(((i-1>=0)&&(i-1<M)&&(j+1>=0)&&(j+1<N))&&((*Mat)[i-1][j+1]>0)){
                    vizinhos++;
                }
                if(((i+1>=0)&&(i+1<M)&&(j-1>=0)&&(j-1<N))&&((*Mat)[i+1][j-1]>0)){
                    vizinhos++;
                }   
                if(((i+1>=0)&&(i+1<M)&&(j+1>=0)&&(j+1<N))&&((*Mat)[i+1][j+1]>0)){
                    vizinhos++;
                }


                if(cont == 0){
                    for(int k = 0; k<5; k++){
                        if((i==Camada_1[k][0])&&(j==Camada_1[k][1])){
                            Mat_copy_2[i][j] = Mat_copy_2[i][j]-(5+(8*vizinhos));
                            cont = 1;
                            break;
                        }
                    }
                }
                if(cont == 0){
                    for(int k = 0; k<16; k++){
                        if((i==Camada_2[k][0])&&(j==Camada_2[k][1])){
                            Mat_copy_2[i][j] = Mat_copy_2[i][j]-(5+(8*vizinhos));
                            break;
                        }
                    }
                }

                if(Mat_copy_2[i][j]<0){
                    Mat_copy_2[i][j] = 0;
                }else if(Mat_copy_2[i][j]>0){
                    END = 0;
                }
            }
        }

        freeMat(&(*Mat), M);
        (*Mat) = NULL;
        (*Mat) = Mat_copy_2;
        printMat((*Mat), M, N);
        printf("\n");
        
        if(END == 1){
            z = 100;
        }
    }
}

void matCopy(int **Mat, int ***Mat_copy, int M, int N){

    matAllocate(&(*Mat_copy), M, N);
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            (*Mat_copy)[i][j] = Mat[i][j];
        }
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
    free(*Mat);
    exit(1);
}

void printMat(int **Mat, int M, int N){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}

void matAllocate(int ***Mat, int M, int N){

    int **TEMPOINTER = realloc((*Mat), M * sizeof(*(*Mat)));
    checkNull(TEMPOINTER);
    (*Mat) = TEMPOINTER;

    for(int i = 0; i<M; i++){
        (*Mat)[i] = calloc(N, sizeof(*(*Mat)[i]));
        if((*Mat)[i] == NULL){
            checkNullMat(&(*Mat), i);
        }
    }
}

void getInput(int **Mat, int M, int N){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            int TEMPINT = 0; scanf("%d", &TEMPINT);
            Mat[i][j] = TEMPINT;
        }
    }
}

void freeMat(int ***Mat, int M){
    for(int i = 0; i<M; i++){
        free((*Mat)[i]);
    }
    free(*Mat);
}