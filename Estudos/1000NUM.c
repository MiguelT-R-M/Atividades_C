#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define arrayLength(X) (sizeof(X)/sizeof(X[0])) // define um macro para o tamanho de um array
#define stringLength(X) (sizeof(X)/sizeof(X[0])-1) // define um macro para o tamanho de um array de chars, ou string