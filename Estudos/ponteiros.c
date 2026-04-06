#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main(void){



    char command[8];
    int NUMS[3] = {0};
    int *Num_pointer = &NUMS[0], Tamanho_pilha = 0;


    while(strcmp(command, "exit")){

        scanf("%s", command);

        if (!strcmp(command, "push")){
            scanf("%d", Num_pointer);
            Num_pointer++;
            Tamanho_pilha++;
        }else if (!strcmp(command, "pop")){
            if(Tamanho_pilha > 0){
                Num_pointer--;
                *Num_pointer = 0;
                Tamanho_pilha--;
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
        
    }

    return 0;
}