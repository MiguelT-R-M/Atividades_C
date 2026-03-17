    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    int main(void){

        long long int Q, NUM, Espaco_esq = 0, Ponto_atual = 1, Ponto_previo = 1; char W, ante_W = 'a';

        scanf("%lld", &Q);
        for(long long int i = 1; i<=Q; i++){
            scanf("%lld %c", &NUM, &W);

            if(W == 'E'){
                if(Ponto_atual-NUM<2){
                    if(ante_W == 'E' || ante_W == 'D'){printf("\n");}
                    printf("Informacao invalida");
                    break;
                }else if(Ponto_atual-NUM>=2){
                    Ponto_previo = Ponto_atual;
                    Ponto_atual-=NUM;
                    if(ante_W == 'E' || ante_W == 'D'){Ponto_atual+=1;}
                    if(ante_W == 'D' || ante_W == 'E'){printf("\n");}
                    for(long long int x = 1; x<Ponto_atual; x++){
                        printf(" ");
                    }
                    for(long long int x = Ponto_atual; x<Ponto_previo+1; x++){
                        printf(".");
                    }
                }
            }else if(W == 'D'){
                if(ante_W == 'D' || ante_W == 'E'){printf("\n");}
                Ponto_previo = Ponto_atual;
                Ponto_atual+= NUM;
                if(ante_W == 'D'){Ponto_atual+=1;}
                if(ante_W == 'E'){Ponto_atual-=1;}
                if(ante_W == 'B' || ante_W == 'E'){Ponto_atual+=1;}
                for(long long int x = 1; x<Ponto_previo; x++){
                    printf(" ");
                }
                for(long long int x = Ponto_previo; x<Ponto_atual; x++){
                    printf(".");
                }
                Ponto_atual-=1;
            }else if(W == 'B'){
                if(ante_W == 'B'){NUM-=1; printf(".");}
                for(long long int x = 1; x<NUM; x++){
                    printf("\n");
                    for(long long int x = 1; x<Ponto_atual; x++){
                        printf(" ");
                    }
                    printf(".");
                    ante_W = W;
                }
                printf("\n");
            }
            ante_W = W;
        }

        if(ante_W == 'B'){
        for(int x = 1; x<Ponto_atual; x++){
            printf(" ");
        }
        printf(".");
        }
        
        return 0;
    }