#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int Main_arr[4][4] = {0}, Current_pos[2] = {0}, Best_pos[2] = {0}; char MOVE;

    while(scanf("%c", &MOVE) != EOF && MOVE != '\n'){
        if(MOVE == 'c' && (Current_pos[0]-1) >= 0){
            
            Main_arr[Current_pos[0]-1][Current_pos[1]]+=1;
            Current_pos[0]-=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }else if(MOVE == 'e' && (Current_pos[1]-1) >= 0){

            Main_arr[Current_pos[0]][Current_pos[1]-1]+=1;
            Current_pos[1]-=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }
            
        }else if(MOVE == 'b' && (Current_pos[0]+1) <= 3){

            Main_arr[Current_pos[0]+1][Current_pos[1]]+=1;
            Current_pos[0]+=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }else if(MOVE == 'd' && (Current_pos[1]+1) <= 3){

            Main_arr[Current_pos[0]][Current_pos[1]+1]+=1;
            Current_pos[1]+=1;
            if(Main_arr[Current_pos[0]][Current_pos[1]]>Main_arr[Best_pos[0]][Best_pos[1]]){
                Best_pos[0] = Current_pos[0]; Best_pos[1] = Current_pos[1];
            }

        }
    }

    printf("Coordenada X:%d, Y:%d\n", Best_pos[1], Best_pos[0]);

    return 0;
}