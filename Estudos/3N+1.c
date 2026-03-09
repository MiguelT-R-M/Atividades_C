#include <stdio.h>

int maxCycleFunc(unsigned long int M, unsigned long int N){

    unsigned long int Max_cycle_size = 0;

    if(M<=N){
        for(unsigned long int A = M; A<=N; A++){

            unsigned long int TEMPCYCLE = 1, TEMPVAR = A;

            while(TEMPVAR!=1){

                if(TEMPVAR%2==0){

                    TEMPVAR = TEMPVAR/2;
                    TEMPCYCLE+=1;

                }else if(TEMPVAR%2!=0){

                    TEMPVAR = (TEMPVAR*3)+1;
                    TEMPCYCLE+=1;

                }

            }

            if(TEMPCYCLE>Max_cycle_size){

                Max_cycle_size = TEMPCYCLE;

            }

        }
    }else if(N<M){
        for(unsigned long int A = N; A<=M; A++){

            unsigned long int TEMPCYCLE = 1, TEMPVAR = A;

            while(TEMPVAR!=1){

                if(TEMPVAR%2==0){

                    TEMPVAR = TEMPVAR/2;
                    TEMPCYCLE+=1;

                }else if(TEMPVAR%2!=0){

                    TEMPVAR = (TEMPVAR*3)+1;
                    TEMPCYCLE+=1;

                }

            }

            if(TEMPCYCLE>Max_cycle_size){

                Max_cycle_size = TEMPCYCLE;

            }

        }
    }
    return Max_cycle_size;
}

int main(){

    unsigned long int I, J;

    while (scanf("%lu %lu", &I, &J) != EOF){

        unsigned long int Max_cycle_size;
        Max_cycle_size = maxCycleFunc(I, J);
        printf("%lu %lu %lu\n", I, J, Max_cycle_size);

    }

    return 0;
}