//Usei IA apenas para encontrar as fórmulas usadas

#include <stdio.h>
#include <math.h>

int main(){
    long long unsigned int N, A, B, Soma_total, SOMAA, SOMAB, AM, BM, Soma_final, MMCAB, MMCABM, SOMMC;

    scanf("%llu", &N);
    scanf("%llu %llu", &A, &B);

    Soma_total = (N*(N+1))/2; // Formula de soma total de 1 até N
    
    if(A!=B){ // Define o MMC entre A e B, desta forma por sempre serem numeros primos
        MMCAB = A*B; 
    }else{
        MMCAB = A;
    }

    AM = N/A; // Quantidade de multiplos de A até N
    BM = N/B; // Quantidade de multiplos de B até N
    MMCABM = N/MMCAB; // Quantidade de multiplos entre o MMC de A e B até N

    SOMAA = A*((AM*(AM+1))/2); // Soma dos multiplos de A até N
    SOMAB = B*((BM*(BM+1))/2); // Soma dos multiplos de B até N
    SOMMC = MMCAB*((MMCABM*(MMCABM+1))/2); // Soma dos multiplos do MMC entre A e B até N

    Soma_final = Soma_total - (SOMAA + SOMAB - SOMMC); // Formula da soma final

    printf("%llu\n", Soma_final);
    if(Soma_final%2==0){
        printf("Lá ele!!!");
    }else{
        printf("Opa xupenio AULAS...");
    }

    return 0;
}