#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define arraySize(x) (sizeof(x)/sizeof(x[0]))


int main (void){

    // Vetor dinamico:

    int *vet, Vet_size = 10;

    if((vet = (int *) calloc(Vet_size, sizeof(int))) != NULL){

        for(int i = 0; i<Vet_size; i++){
            // vet[i] = i+1;
            printf("%d\n", vet[i]);
        }

        free(vet);
    }else{
        printf("Erro na alocação");
        exit(1);
    }

    // calloc(10, sizeof(int))   // realloc(vet, 10, sizeof(int))

    return 0;
}