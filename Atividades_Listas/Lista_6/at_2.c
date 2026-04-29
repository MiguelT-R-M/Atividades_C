#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void explosaoArcana(int **Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]);
void nuvemVenenosa(int **Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]);
void printMat(int **Mat, int M, int N);
void checkNull(void *Pointer);
void checkNullMat(int ***Mat, int Current_index);
void matMake(int ***Mat, int M, int N);
void getValues(int **Mat, int M, int N);
void freeMat(int ***Mat, int M);
void matCpy(int **Source, int ***Dest, int M, int N);

int main(void){
    int **Mat = NULL, M, N, Centro_X, Centro_Y; scanf("%d %d", &M, &N);
    void (*Ataques[2])(int **, int, int, int (*)[2], int (*)[2]) = {explosaoArcana, nuvemVenenosa};

    matMake(&Mat, M, N);
    scanf("%d %d", &Centro_X, &Centro_Y);

    int Camada_1[5][2] = {{Centro_X, Centro_Y}, {Centro_X-1, Centro_Y}, {Centro_X+1, Centro_Y}, {Centro_X, Centro_Y-1}, {Centro_X, Centro_Y+1}};
    int Camada_2[16][2] = {{Centro_X-1, Centro_Y-1}, {Centro_X-1, Centro_Y+1}, {Centro_X-2, Centro_Y-1}, {Centro_X-2, Centro_Y+1}, {Centro_X-2, Centro_Y}, {Centro_X+1, Centro_Y-1}, {Centro_X+1, Centro_Y+1}, {Centro_X+2, Centro_Y-1}, {Centro_X+2, Centro_Y+1}, {Centro_X+2, Centro_Y}, {Centro_X-1, Centro_Y-2}, {Centro_X+1, Centro_Y-2}, {Centro_X, Centro_Y-2}, {Centro_X-1, Centro_Y+2}, {Centro_X+1, Centro_Y+2}, {Centro_X, Centro_Y+2}};

    printf("Estado inicial do mapa:\n");
    printMat(Mat, M, N);
    printf("\n");

    char ATACK_INPUT[50] = {'\n'};scanf("%49s", ATACK_INPUT);

    int z = -1;
    if(strcmp(ATACK_INPUT, "EXPLOSAO_ARCANA") == 0){
        z = 0;
        printf("Estado do mapa após usar a Explosão Arcana:\n");
    }else if(strcmp(ATACK_INPUT, "NUVEM_VENENOSA") == 0){
        z = 1;
        printf("Estado do mapa, por turno, após usar a Nuvem Venenosa:\n");
    }
    Ataques[z](Mat, M, N, Camada_1, Camada_2);

    freeMat(&Mat, M);
    return 0;
}

void explosaoArcana(int **Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]){
    int **Mat_2 = NULL;
    matCpy(Mat, &Mat_2, M, N);

    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){

            int cont = 0;
            if(cont == 0){
                for(int k = 0; k<5; k++){
                    if(i==Camada_1[k][0]&&j==Camada_1[k][1]){
                        cont = 1;
                        Mat_2[i][j] = (int)fmax(0, Mat_2[i][j] - 50);
                        break;
                    }
                }
            }
            if(cont == 0){
                for(int k = 0; k<16; k++){
                    if(i==Camada_2[k][0]&&j==Camada_2[k][1]){
                        cont = 1;
                        Mat_2[i][j] = (int)fmax(0, Mat_2[i][j] - 25);
                        break;
                    }
                }
            }
        }
    }

    printMat(Mat_2, M, N);
    freeMat(&Mat_2, M);
}
void nuvemVenenosa(int **Mat, int M, int N, int Camada_1[5][2], int Camada_2[16][2]){
    int **Mat_2 = NULL;
    int **Mat_3 = NULL;
    matCpy(Mat, &Mat_2, M, N);
    matCpy(Mat_2, &Mat_3, M, N);

    int END = 0, ENDBREAK = 0;

    while(END<3){
        ENDBREAK = 0;
        for(int i = 0; i<M; i++){
            for(int j = 0; j<N; j++){
                int cont = 0, vizinhos = 0;

                if((i-1>=0)){
                    if(Mat_2[i-1][j]>0){
                        vizinhos++;
                    }
                    if((j-1>=0)&&(Mat_2[i-1][j-1]>0)){
                        vizinhos++;
                    }
                    if((j+1<N)&&(Mat_2[i-1][j+1]>0)){
                        vizinhos++;
                    }
                }
                if((i+1<M)){
                    if(Mat_2[i+1][j]>0){
                        vizinhos++;
                    }
                    if((j-1>=0)&&(Mat_2[i+1][j-1]>0)){
                        vizinhos++;
                    }
                    if((j+1<N)&&(Mat_2[i+1][j+1]>0)){
                        vizinhos++;
                    }
                }
                if((j-1>=0)&&(Mat_2[i][j-1]>0)){
                    vizinhos++;
                }
                if((j+1<N)&&(Mat_2[i][j+1]>0)){
                    vizinhos++;
                }


                if(cont == 0){
                    for(int k = 0; k<5; k++){
                        if(i==Camada_1[k][0]&&j==Camada_1[k][1]){
                            cont = 1;
                            Mat_3[i][j] = (int)fmax(0, Mat_3[i][j]-(5+(8*vizinhos)));
                            break;
                        }
                    }
                }
                if(cont == 0){
                    for(int k = 0; k<16; k++){
                        if(i==Camada_2[k][0]&&j==Camada_2[k][1]){
                            cont = 1;
                            Mat_3[i][j] = (int)fmax(0, Mat_3[i][j]-(5+(8*vizinhos)));
                            break;
                        }
                    }
                }

                if(Mat_3[i][j]>0){
                    ENDBREAK = 1;
                }
            }
        }

        END++;
        if(ENDBREAK == 0){
            END = 10;
        }
        printMat(Mat_3, M, N);
        printf("\n");
        freeMat(&Mat_2, M);
        Mat_2 = NULL;
        matCpy(Mat_3, &Mat_2, M, N);
    }

    freeMat(&Mat_2, M);
    freeMat(&Mat_3, M);
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
    exit(1);
}
void matMake(int ***Mat, int M, int N){
    int **TEMPOINTER = realloc((*Mat), M*sizeof(*(*Mat)));
    checkNull(TEMPOINTER);
    (*Mat) = TEMPOINTER;

    for(int i = 0; i<M; i++){
        (*Mat)[i] = calloc(N, sizeof((*Mat)[i]));
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
void matCpy(int **Source, int ***Dest, int M, int N){

    int **TEMPOINTER = realloc((*Dest), M*sizeof(*(*Dest)));
    checkNull(TEMPOINTER);
    (*Dest) = TEMPOINTER;

    for(int i = 0; i<M; i++){
        (*Dest)[i] = calloc(N, sizeof((*Dest)[i]));
        if((*Dest)[i] == NULL){
            checkNullMat(&(*Dest), i);
        } 
    }

    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            (*Dest)[i][j] = Source[i][j];
        }
    }
}