#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int m, n;

    scanf("%d %d\n", &m, &n);

    char Main_array[m][n], tempchar; int Water_pos[m*n][2], Water_amount = 0, Water_bool = 0;

    for(int i = 0; i<m; i++){

        for(int j = 0; j<n; j++){

            scanf("%c", &tempchar);
            if(tempchar == 'o'){
                Water_pos[Water_amount][0] = i; Water_pos[Water_amount][1] = j;
                Water_amount+=1;
            }
            Main_array[i][j] = tempchar;

        }
        scanf("%c", &tempchar);

    }

    Water_bool = Water_amount;

    while (Water_bool > 0){

        Water_bool = Water_amount;

        for(int i = 0; i<Water_amount; i++){

            if(Water_pos[i][0]+1 < m && Main_array[Water_pos[i][0]+1][Water_pos[i][1]] == '.'){
                Main_array[Water_pos[i][0]+1][Water_pos[i][1]] = 'o';
                Water_pos[i][0] = Water_pos[i][0]+1; 
            }else if(Water_pos[i][0]+1 < m && Main_array[Water_pos[i][0]+1][Water_pos[i][1]] == '#'){
                
                if((Water_pos[i][1]-1 >= 0 && Water_pos[i][1]+1 < n) && (Main_array[Water_pos[i][0]][Water_pos[i][1]-1] != 'o' && Main_array[Water_pos[i][0]][Water_pos[i][1]+1] != 'o')){

                    Water_pos[Water_amount][0] = Water_pos[i][0]; Water_pos[Water_amount][1] = Water_pos[i][1]+1;
                    Water_amount+=1;
                    Main_array[Water_pos[i][0]][Water_pos[i][1]-1] = 'o'; Main_array[Water_pos[i][0]][Water_pos[i][1]+1] = 'o';
                    Water_pos[i][1] = Water_pos[i][1]-1;

                }else if(Water_pos[i][1]-1 >= 0 && Main_array[Water_pos[i][0]][Water_pos[i][1]-1] != 'o'){
                    
                    Main_array[Water_pos[i][0]][Water_pos[i][1]-1] = 'o';
                    Water_pos[i][1] = Water_pos[i][1]-1;

                }else if(Water_pos[i][1]+1 < n && Main_array[Water_pos[i][0]][Water_pos[i][1]+1] != 'o'){
                    
                    Main_array[Water_pos[i][0]][Water_pos[i][1]+1] = 'o';
                    Water_pos[i][1] = Water_pos[i][1]+1;

                }else{
                    Water_bool-=1;
                }
                
            }else{
                Water_bool-=1;
            }
            
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