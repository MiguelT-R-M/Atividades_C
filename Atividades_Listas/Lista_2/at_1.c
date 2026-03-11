#include <stdio.h>

int main(void){
    
    char C;

    scanf("%c", &C);

    int Altura_pir = C - 64, Comprimento_base = (Altura_pir*2)-1, Ponto_meio = (Comprimento_base/2)+1,Ponto_comeco = Ponto_meio, Ponto_fim = Ponto_meio, Letra_atual = 65;

    for(int X = 1; X<=Altura_pir; X++){ // Loop para as linhas
        for(int Y = 1; Y<=Comprimento_base; Y++){ // Loop para as colunas
            if((Y>Ponto_fim || Y<Ponto_comeco)){
                printf(".");
            }else if((Y<= Ponto_fim || Y>=Ponto_comeco)){
                printf("%c", Letra_atual);
                if(Y<Ponto_meio){Letra_atual++;}else if(Y>=Ponto_meio){Letra_atual--;}
            }
        }
        printf("\n");
        Letra_atual = 65;
        Ponto_comeco--;
        Ponto_fim++;
    }

    return 0;
}