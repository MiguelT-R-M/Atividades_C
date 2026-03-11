#include <stdio.h>
#include <math.h>

int main(void){

    long int N, K, P, Num_inicial = 2, fatores_primos_impares = 0, Q = 0, NUM = -1;

    scanf("%ld %ld %ld", &N, &K, &P);

    for(N = N; N<K; N++){ // loop que itera do N até K
        unsigned long int tempint = N, tempnuminicial = 0;

        while(tempint>1 && tempnuminicial != Num_inicial){ // Loop que fatora o valor N
            if(tempint%Num_inicial==0){
                if(Num_inicial>2){
                    fatores_primos_impares++;
                }
                tempint = tempint/Num_inicial;
                if(tempint%Num_inicial==0 && Num_inicial>2){tempnuminicial = Num_inicial; fatores_primos_impares = -1;}
            }else if(tempint%Num_inicial!=0){tempnuminicial = Num_inicial; Num_inicial++;}
        }

        if(NUM==-1 && fatores_primos_impares == P){
            NUM = N;
        }else if(NUM!=-1 && fatores_primos_impares == P){
            Q++;
        }

        Num_inicial = 2; // reset de variável
        fatores_primos_impares = 0; // reset de variável
    }

    if(NUM != -1){
        printf("%ld %ld\n", NUM, Q);
    }else{
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }

    return 0;
}