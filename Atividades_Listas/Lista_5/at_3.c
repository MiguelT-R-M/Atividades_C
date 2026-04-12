#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){

    int *NUMS = calloc(0, sizeof(*NUMS)), Current_num = 0, Num_quant = 0;

    if(NUMS != NULL){

        while(scanf("%d\n", &Current_num) != EOF){

            Num_quant+=1;
            NUMS = realloc(NUMS, Num_quant * sizeof(*NUMS));
            NUMS[Num_quant-1] = Current_num;

        }

        printf("Mais um bom dia de trabalho!\n");
        for(int i = 0; i<Num_quant;i++){
            if(NUMS[i]%2!=0){
                printf("%d\n", NUMS[i]);
            }
        }
        for(int i = 0; i<Num_quant;i++){
            if(NUMS[i]%2==0){
                printf("%d\n", NUMS[i]);
            }
        }
        printf("Vou visitar esses lugares de novo... algum dia.\n");

        free(NUMS);
        NUMS = NULL;
    }else{
        
        printf("Problema de memória.");
        exit(1);

    }

    return 0;
}