#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int Q, NUM, Espaco_esq = 0, Ponto_atual = 1, Ponto_previo = 1; char W, ante_W = 'a';

    scanf("%d", &Q);
    for(int i = 1; i<=Q; i++){
        scanf("%d %c", &NUM, &W);

        if(W == 'E'){
            if(Espaco_esq-NUM<1){
                printf("\nInformacao invalida\n");
                break;
            }else if(Espaco_esq-NUM>=1){
                if(ante_W == 'D'){printf("\n");}
                Espaco_esq-=NUM;
                for(int x = 1; x<Espaco_esq; x++){
                    printf(" ");
                }
                for(int x = Espaco_esq-1; x<Ponto_atual; x++){
                    printf(".");
                }
                Ponto_atual-=NUM;
            }
        }else if(W == 'D'){
            if(ante_W == 'E'){printf("\n");}
            Ponto_previo = Ponto_atual;
            Ponto_atual+= NUM;
            if(ante_W == 'B'){Ponto_atual+=1;}
            for(int x = 1; x<Espaco_esq; x++){
                printf(" ");
            }
            for(int x = Ponto_previo; x<Ponto_atual; x++){
                printf(".");
            }
            Ponto_atual-=1;
            if(ante_W == 'E'){Espaco_esq-=1;}
            Espaco_esq+=NUM;
        }else if(W == 'B'){
            for(int x = 1; x<NUM; x++){
                printf("\n");
                for(int x = 1; x<Espaco_esq; x++){
                    printf(" ");
                }
                printf(".");
            }
            printf("\n");
        }
        ante_W = W;
    }

    return 0;
}