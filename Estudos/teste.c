#include <stdio.h>
#include <math.h>
#define arrayLength(X) (sizeof(X)/sizeof(X[0]))
#define stringLength(X) (sizeof(X)/sizeof(X[0])-1)

int main(){

    int A, B, C;
    scanf("%d\n%d\n%d", &A, &B, &C);

    int arr[3];

    if(A<=B && A<=C){arr[0]=A;if(B<=C){arr[1]=B;arr[2]=C;}else{arr[1]=C;arr[2]=B;}}
    if(B<=A && B<=C){arr[0]=B;if(A<=C){arr[1]=A;arr[2]=C;}else{arr[1]=C;arr[2]=A;}}
    if(C<=B && C<=A){arr[0]=C;if(B<=A){arr[1]=B;arr[2]=A;}else{arr[1]=A;arr[2]=B;}}

    for(int i = 0; i<arrayLength(arr); i++){

        printf("%d\n", arr[i]);

    }

}