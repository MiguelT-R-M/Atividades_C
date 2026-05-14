#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

typedef struct{

    float Sepal_length;
    float Sepal_width;
    float Petal_length;
    float Petal_width;
    char Species[50];

} flor;

void checkNull(void *Pointer);
int compareFlowers(const void *a, const void *b);

int main(void){
    
    int Total_arq = 0, Arq_num = 0; scanf("%d", &Total_arq);

    for(int i = 0; i<Total_arq; i++){

        int Max_flores = 1, Current_flores = 0;
        flor *Flores = calloc(Max_flores, sizeof(*Flores));
        checkNull(Flores); 

        Arq_num++;
        char Nome_atual[50];
        sprintf(Nome_atual, "iris%d.csv", Arq_num);

        FILE *Arq_csv = fopen(Nome_atual, "a+");
        checkNull(Arq_csv);

        char BUFFER[100];
        fscanf(Arq_csv, "%[^\n]%*c", BUFFER);
        while(fscanf(Arq_csv, " %f,%f,%f,%f,%49[^\n]%*c", &Flores[Current_flores].Sepal_length, &Flores[Current_flores].Sepal_width, &Flores[Current_flores].Petal_length, &Flores[Current_flores].Petal_width, Flores[Current_flores].Species) != EOF){
            Current_flores++;


            if(Current_flores>=Max_flores){
                Max_flores*=2;
                flor *TEMPOINTER = realloc(Flores, Max_flores*(sizeof(*TEMPOINTER)));
                checkNull(TEMPOINTER);
                Flores = TEMPOINTER;
            }
        }

        if(Current_flores>0 && Current_flores<Max_flores){ // Economia de espaço
            flor *TEMPOINTER = realloc(Flores, Current_flores*(sizeof(*TEMPOINTER)));
            checkNull(TEMPOINTER);
            Flores = TEMPOINTER;
        }

        fseek(Arq_csv, 0, SEEK_SET); // Volta pro começo
        printf("Dados do arquivo %s:\n", Nome_atual);
        while(fscanf(Arq_csv, " %[^\n]", BUFFER) != EOF){
            printf("%s\n", BUFFER);
        }
        printf("\n");


        if(Current_flores>0){
            float AVG_SL = 0, AVG_SW = 0, AVG_PL = 0, AVG_PW = 0; int MODA_SPECIES = 0;
            for(int j = 0; j<Current_flores; j++){
                AVG_SL += Flores[j].Sepal_length;
                AVG_SW += Flores[j].Sepal_width;
                AVG_PL += Flores[j].Petal_length;
                AVG_PW += Flores[j].Petal_width;
            }
            AVG_SL = (AVG_SL/Current_flores);
            AVG_SW = (AVG_SW/Current_flores);
            AVG_PL = (AVG_PL/Current_flores);
            AVG_PW = (AVG_PW/Current_flores);

            // Código gerado por IA:
            qsort(Flores, Current_flores, sizeof(flor), compareFlowers);

            int max_streak = 0;
            int current_streak = 0;
            int best_index = 0;

            for (int j = 0; j < Current_flores; j++) {
                current_streak++;
                
                // If it's the last element OR the next element is different
                if (j == Current_flores - 1 || strcmp(Flores[j].Species, Flores[j+1].Species) != 0) {
                    if (current_streak > max_streak) {
                        max_streak = current_streak;
                        best_index = j - (current_streak - 1); // Point to the START of the streak
                    }
                    current_streak = 0; // Reset for next species
                }
            }
            MODA_SPECIES = best_index;
            //

            fprintf(Arq_csv, "\n----------------------------------\n");
            fprintf(Arq_csv, "Resultados:\n");
            fprintf(Arq_csv, "Média atributo 1 = %f\n", AVG_SL);
            fprintf(Arq_csv, "Média atributo 2 = %f\n", AVG_SW);
            fprintf(Arq_csv, "Média atributo 3 = %f\n", AVG_PL);
            fprintf(Arq_csv, "Média atributo 4 = %f\n", AVG_PW);
            fprintf(Arq_csv, "Espécie de maior frequência = %s\n", Flores[MODA_SPECIES].Species);
        }

        fclose(Arq_csv);
        free(Flores);
    }

    return 0;
}

void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}

int compareFlowers(const void *a, const void *b) {
    flor *f1 = (flor *)a;
    flor *f2 = (flor *)b;
    return strcmp(f1->Species, f2->Species);
}