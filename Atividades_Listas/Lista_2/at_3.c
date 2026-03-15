#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

    long long int VIP = 0, Num_inicial, Canal_num, Stop_condition = 1, VAL1, VAL2, Proximidade_val  = 0, Proximidade_canal = -1, Min_importante = -1, Antes_proximidade_val, Antes_proximidade_canal, Antes_min_importante, Canal_importante = -1;

    scanf("%lld %lld", &Num_inicial, &Canal_num);

    for(int i = 1; i<=Canal_num; i++){

        long long int Soma_val = 0, Soma_superpreanterior = Num_inicial, Soma_preanterior = 0, Soma_anterior = 0, MIN = 0, Proximidade_V1 = 0, Proximidade_V2 = 0, Antes_PV1 = 0 , Antes_PV2 = 0;
        scanf("%lld %lld", &VAL1,&VAL2);
        Soma_preanterior = VAL1; Soma_anterior = VAL2;

        while (Stop_condition){

            MIN++;
            Soma_val = Soma_preanterior+Soma_anterior;
            Proximidade_V1 = llabs(Soma_preanterior-Num_inicial); Proximidade_V2 = llabs(Soma_anterior-Num_inicial);
            if((Proximidade_V1 == 0 || Proximidade_V2 == 0) || ((MIN>1) && (Proximidade_V1>Antes_PV1 || Proximidade_V2>Antes_PV2))){
                Antes_min_importante = MIN;
                Stop_condition = 0;
                if(Antes_PV1<Antes_PV2){
                    Antes_proximidade_canal = Antes_PV1; Antes_proximidade_val = Soma_superpreanterior;
                }else if(Antes_PV2<Antes_PV1){
                    Antes_proximidade_canal = Antes_PV2; Antes_proximidade_val = Soma_preanterior;
                }else if(Antes_PV2==Antes_PV1){
                    Antes_proximidade_canal = Antes_PV2; if(Soma_superpreanterior<Soma_preanterior){Antes_proximidade_val = Soma_superpreanterior;}else{Antes_proximidade_val = Soma_preanterior;};
                }
            }else{
                Soma_superpreanterior = Soma_preanterior;
                Soma_preanterior = Soma_anterior;
                Soma_anterior = Soma_val;
            }
            Antes_PV1 = Proximidade_V1; Antes_PV2 = Proximidade_V2;

        }

        if(i>1 && (Antes_proximidade_canal <= Proximidade_canal)){
            Proximidade_canal = Antes_proximidade_canal;
            Proximidade_val = Antes_proximidade_val;
            Min_importante = Antes_min_importante;
            Canal_importante = i;
        }else if(i==1){
            Proximidade_canal = Antes_proximidade_canal;
            Proximidade_val = Antes_proximidade_val;
            Min_importante = Antes_min_importante;
            Canal_importante = i;
        }
        Stop_condition = 1;
    }

    long long int Valor_atual = 0;

    while(Proximidade_val != 0){
        Valor_atual+= (Proximidade_val%10);
        Proximidade_val = Proximidade_val/10;
    }
    if(Valor_atual>10){
        VIP = 1;
    }

    if(VIP == 1){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %lld e sera chamado mais ou menos no minuto %lld e com o VIP garantido!!!\n", Canal_importante, Min_importante);
    }else if (VIP == 0){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %lld e sera chamado mais ou menos no minuto %lld, mas o ingresso VIP não vai rolar :(\n", Canal_importante, Min_importante);
    }

    return 0;
}