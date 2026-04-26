#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void matOp(int ***Mat, int L, int C, int CHOICE); // função que faz as operações nos pointeiros
void getValues(int ***Mat, int L, int C); // função que recebe os valores da matriz
void checkNullMat(int ***Mat, int Current_ind); // função que checa se algum vetor dinamico da matriz deu null
void checkNull(void *Pointer); // função que checa a nulidade de um ponteiro individual
void printMat(int ***Mat, int L, int C); // printa a matriz
void changeMat(int ***Mat, int L, int C); // aloca dinamicamente a matriz
void freeMemMat(int ***Mat, int L); // libera a memória da matriz

int main(void){
	
    void (*matOpPont)(int***, int, int, int); // ponteiro pra função
    matOpPont = matOp; // ponteiro pra função 

	int L = 0, C = 0; 
	int **Mat = NULL;

	scanf("%d %d", &L, &C);
	changeMat(&Mat, L, C);

	getValues(&Mat, L, C);
	int CHOICE = 0; scanf("%d", &CHOICE);
	
    matOpPont(&Mat, L, C, CHOICE);

	printMat(&Mat, L, C);
	
	freeMemMat(&Mat, L);
	return 0;
}

void matOp(int ***Mat, int L, int C, int CHOICE){

	if(CHOICE == 1){ // Dobro
		for(int i = 0; i<L; i++){
			for(int j = 0; j<C; j++){
			
				(*Mat)[i][j] = (*Mat)[i][j]*2;

			}
		}	
	}else if(CHOICE == 2){ // Quadrado
		for(int i = 0; i<L; i++){
			for(int j = 0; j<C; j++){
			
				(*Mat)[i][j] = (*Mat)[i][j]*(*Mat)[i][j];

			}
		}	
	}else if(CHOICE == 3){ // Absoluto
		for(int i = 0; i<L; i++){
			for(int j = 0; j<C; j++){
			
				(*Mat)[i][j] = abs((*Mat)[i][j]);

			}
		}	
	}

}

void getValues(int ***Mat, int L, int C){

	for(int i = 0; i<L; i++){
		
		for(int j = 0; j<C; j++){
			
			scanf("%d", &(*Mat)[i][j]);
			
		}
			
	}	

}

void checkNullMat(int ***Mat, int Current_ind){
	
	for(int i = Current_ind-1; i>=0; i--){
		
		free((*Mat)[i]);
			
	}
	free(*Mat);
	exit(1);	
	
}

void checkNull(void *Pointer){
	
	if(Pointer == NULL){
		printf("Erro de memoria.");
		exit(1);
	}
	
}

void printMat(int ***Mat, int L, int C){

	for(int i = 0; i<L; i++){
		
		for(int j = 0; j<C; j++){
			
			printf("%d ", (*Mat)[i][j]);
			
		}
		printf("\n");
			
	}	

}

void changeMat(int ***Mat, int L, int C){
	
	int **TEMPOINTER = realloc(*Mat, (L)*(sizeof(**Mat)));
	checkNull(TEMPOINTER);
	*Mat = TEMPOINTER;
	for(int i = 0; i<L; i++){

		(*Mat)[i] = calloc(C, sizeof((**Mat)[i]));
		if((*Mat)[i] == NULL){
			
			checkNullMat(Mat, i);
			
		}
				
	}
	
}

void freeMemMat(int ***Mat, int L){

	for(int i = 0; i<L; i++){
		free((*Mat)[i]);
	}
	free(*Mat);

}