#include <stdio.h>

int main(void){

    int N, tempint, cont = 0, Ncont = 0;

    while(scanf("%d", &tempint) != -1){

        if(cont == 0){
            N = tempint;
            cont++;
        }else if(cont <= 10){

            if(tempint == N){Ncont++;}
            cont++;

        }else if(cont > 10){

            printf("%d appeared %d times\n", N, Ncont);
            N = tempint;
            Ncont = 0;
            cont = 1;

        }

    }

    return 0;
}