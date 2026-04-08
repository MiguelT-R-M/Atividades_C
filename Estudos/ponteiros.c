#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main(void){



    char command[8];
    // int NUMS[3] = {0};
    // int *Num_pointer = &NUMS[0], Tamanho_pilha = 0;

    int *NUMS = calloc(0, sizeof(*NUMS)), Tamanho_pilha = 0, NUM = 0;

    if(NUMS != NULL){

        int *point = NUMS, Point_place = 0;

        while(strcmp(command, "exit")){

            scanf("%s", command);

            if (!strcmp(command, "push")){
                
                Tamanho_pilha++;
                NUMS = realloc(NUMS, Tamanho_pilha);
                scanf("%d", &NUM);
                NUMS[Tamanho_pilha-1] = NUM;

            }else if (!strcmp(command, "pop")){
                if(Tamanho_pilha > 0){
                    Tamanho_pilha--;
                    NUMS = realloc(NUMS, Tamanho_pilha);
                }
            }else if (!strcmp(command, "sum")){
                int SUM = 0, cont = 0;
                while(cont < Tamanho_pilha){
                    SUM+=NUMS[cont];
                    cont++;
                }
                printf("%d\n", SUM);
            }else if (!strcmp(command, "pow")){
                int cont = 0;
                while(cont < Tamanho_pilha){
                    printf("%d ", NUMS[cont]*NUMS[cont]);
                    cont++;
                }
                printf("\n");
            }else if (!strcmp(command, "average")){
                if(Tamanho_pilha > 0){
                    int SUM = 0, cont = 0;
                    while(cont < Tamanho_pilha){
                        SUM+=NUMS[cont];
                        cont++;
                    }
                    float AVERAGE = SUM;
                    AVERAGE = AVERAGE/Tamanho_pilha;
                    printf("%.2f\n", AVERAGE);
                }else{
                    printf("0.00\n");
                }
            }else if (!strcmp(command, "print")){
                int cont = 0;
                while(cont < Tamanho_pilha){
                    printf("%d ", NUMS[cont]);
                    cont++;
                }
                printf("\n");
            }

            if(!strcmp(command, "SHOW")){
                printf("%d\n", *point);
            }else if(!strcmp(command, "LEFT")){
                if(Point_place > 0){
                    point--; Point_place--;
                }else{
                    printf("limite esquerdo do vetor atingido");
                }
            }else if(!strcmp(command, "RIGHT")){
                if(Point_place < Tamanho_pilha-1){
                    point++; Point_place++;
                }else{
                    printf("limite direito do vetor atingido");
                }

            }else if(!strcmp(command, "MEMSHOW")){
                printf("%p\n", point);
            }else if(!strcmp(command, "MODIFY")){
                scanf("%d", point);
            }
            
            
        }
    }else{
        printf("Deu errado\n");
        free(NUMS);
        exit(1);
    }
    free(NUMS);

    return 0;
}