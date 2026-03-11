#include <stdio.h>
#include <math.h>
#define arrayLength(X) (sizeof(X)/sizeof(X[0])) // define um macro para o tamanho de um array
#define stringLength(X) (sizeof(X)/sizeof(X[0])-1) // define um macro para o tamanho de um array de chars, ou string


int stringCompare(char X[], char Y[], int LENGTH){

    for(int Z = 1; Z<=LENGTH; Z++){
        if(X[Z]!=Y[Z]){
            return 0;
        }
    }
    return 1;

}


int main(){
    int XYLENGTH;
    char X[] = "arara";
    char Y[] = "arara";

    int XYCOMPARE = stringCompare(X, Y, stringLength(X));

    if(XYCOMPARE==1){
        printf("As strings são iguais!\n");
    }else if(XYCOMPARE==0){
        printf("As strings são diferentes\n");
    }

    return 0;
}