#include <stdio.h>

int main(void){

    int V1, V2, V3, D, D1, D2, Caminho_direto, Caminho_P2;

    scanf("%d %d %d %d", &V1, &V2, &V3, &D);

    Caminho_direto = V1+V3;
    Caminho_P2 = V1+V2+V3;

    D1 = D/10;
    D2 = D-(D/10*10);

    if(D1>D2){
        Caminho_direto+=(D1-D2);
    }else if(D2>D1){
        Caminho_P2+=(D2-D1);
    }else if(D1==D2){
        Caminho_direto+=(D1+D2); Caminho_P2+=(D1+D2);
    }

    if(Caminho_P2>=Caminho_direto){
        printf("Caminho: P2. ");
        if(Caminho_P2>30){
            printf("Xupenio aprova! Nível: ELITE.\n");
        }else if(Caminho_P2<=30 && Caminho_P2>=10){
            printf("Boa caminhada! Nível: SÓLIDO.\n");
        }else if(Caminho_P2<=9 && Caminho_P2>=0){
            printf("Passou por pouco. Nível: BÁSICO.\n");
        }else if(Caminho_P2<0){
            printf("Xupenio reprova. Nível: CRÍTICO.\n");
        }
    }else if(Caminho_direto>Caminho_P2){
        printf("Caminho: direto. ");
        if(Caminho_direto>30){
            printf("Xupenio aprova! Nível: ELITE.\n");
        }else if(Caminho_direto<=30 && Caminho_direto>=10){
            printf("Boa caminhada! Nível: SÓLIDO.\n");
        }else if(Caminho_direto<=9 && Caminho_direto>=0){
            printf("Passou por pouco. Nível: BÁSICO.\n");
        }else if(Caminho_direto<0){
            printf("Xupenio reprova. Nível: CRÍTICO.\n");
        }
    }

    return 0;
}