#include <stdio.h>
#define MAXIMO 1000

int main(void){

    int arr[MAXIMO], N, cont = 0;

    while( scanf("%d", &arr[cont]) != EOF){
        cont++;

        if(cont>=MAXIMO){
            
            int Ncont = 0;
            cont = 0;
    
            scanf("%d", &N);
            
            for(int i = 0; i<1000; i++){
                
                if(arr[i]==N){Ncont++;}
                
            }
            
            printf("%d appeared %d times\n", N, Ncont);
        }
    }
    return 0;
}