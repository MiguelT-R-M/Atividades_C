#include <stdio.h>
#define FORI(n) for(int i = 0; i<n; i++)

int maxCycleFunc(int M, int N){

    int Max_cycle_size = 0;

    for(int A = M; A<=N; A++){

        int TEMPCYCLE = 1, TEMPVAR1 = A, TEMPVAR2 = 0;

        while(TEMPVAR1!=1){

            if(TEMPVAR1%2==0){

                TEMPVAR2 = TEMPVAR1/2;
                TEMPVAR1 = TEMPVAR2;
                TEMPCYCLE+=1;

            }else if(TEMPVAR1%2!=0){

                TEMPVAR2 = (TEMPVAR1*3)+1;
                TEMPVAR1 = TEMPVAR2;
                TEMPCYCLE+=1;

            }

        }

        if(TEMPCYCLE>Max_cycle_size){

            Max_cycle_size = TEMPCYCLE;

        }

    }
    return Max_cycle_size;
}

int main(){

    int I, J;

    while (scanf("%d %d", &I, &J) != EOF){

        printf("\n");

        int Max_cycle_size;
        Max_cycle_size = maxCycleFunc(I, J);
        printf("%u %u %u", I, J, Max_cycle_size);

    }

    return 0;
}