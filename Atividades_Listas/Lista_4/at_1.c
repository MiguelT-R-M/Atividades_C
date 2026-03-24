#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int m, n;

    scanf("%d %d\n", &m, &n);

    char Main_array[m][n+1], tempchar; int P_array[m*n][2], P_amount = 0;

    for(int i = 0; i<m; i++){

        for(int j = 0; j<n; j++){

            scanf("%c", &tempchar);
            if(tempchar == 'P'){
                P_array[P_amount][0] = i; P_array[P_amount][1] = j;
                P_amount+=1;
            }
            Main_array[i][j] = tempchar;

        }
        scanf("%c", &tempchar);

    }

    for(int i = 0; i<P_amount; i++){

        if(P_array[i][0]-1>=0 && P_array[i][1]-1>=0){ // if que checa a diagonal superior esquerda e a parte de cima do P atual
            if(Main_array[P_array[i][0]-1][P_array[i][1]-1] != 'P'){if(Main_array[P_array[i][0]-1][P_array[i][1]-1] == '-'){Main_array[P_array[i][0]-1][P_array[i][1]-1] = 'x';}}
            if(Main_array[P_array[i][0]][P_array[i][1]-1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]-1] = '+';}
            if(Main_array[P_array[i][0]-1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]-1][P_array[i][1]] = '+';}
        }
        if(P_array[i][0]-1>=0 && P_array[i][1]+1>=0){ // if que checa a diagonal superior direita e a parte de cima do P atual
            if(Main_array[P_array[i][0]-1][P_array[i][1]+1] != 'P'){if(Main_array[P_array[i][0]-1][P_array[i][1]+1] == '-'){Main_array[P_array[i][0]-1][P_array[i][1]+1] = 'x';}}
            if(Main_array[P_array[i][0]][P_array[i][1]+1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]+1] = '+';}
            if(Main_array[P_array[i][0]-1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]-1][P_array[i][1]] = '+';}
        }
        if(P_array[i][0]+1>=0 && P_array[i][1]-1>=0){ // if que checa a diagonal inferior esquerda e a parte de cima do P atual
            if(Main_array[P_array[i][0]+1][P_array[i][1]-1] != 'P'){if(Main_array[P_array[i][0]+1][P_array[i][1]-1] == '-'){Main_array[P_array[i][0]+1][P_array[i][1]-1] = 'x';}}
            if(Main_array[P_array[i][0]][P_array[i][1]-1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]-1] = '+';}
            if(Main_array[P_array[i][0]+1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]+1][P_array[i][1]] = '+';}
        }
        if(P_array[i][0]+1>=0 && P_array[i][1]+1>=0){ // if que checa a diagonal inferior direita e a parte de cima do P atual
            if(Main_array[P_array[i][0]+1][P_array[i][1]+1] != 'P'){if(Main_array[P_array[i][0]+1][P_array[i][1]+1] == '-'){Main_array[P_array[i][0]+1][P_array[i][1]+1] = 'x';}}
            if(Main_array[P_array[i][0]][P_array[i][1]+1] != 'P'){Main_array[P_array[i][0]][P_array[i][1]+1] = '+';}
            if(Main_array[P_array[i][0]+1][P_array[i][1]] != 'P'){Main_array[P_array[i][0]+1][P_array[i][1]] = '+';}
        }
        
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%c", Main_array[i][j]);
        }
        printf("\n");
    }

    return 0;
}