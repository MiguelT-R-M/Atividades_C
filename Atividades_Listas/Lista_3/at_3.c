#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define arrayLength(x) (sizeof(x)/sizeof(x[0]))
#define stringLength(x) (sizeof(x)/sizeof(x[0])-1)
#define properLetter(x) ((x>=97 && x<=122)||(x>=65 && x<=90))

int main(void){

    char w = 'a', x = 'z', y = 'A', z = 'Z', WORD;
    char Array_words[200], Array_start[200], Array_wordsize[200]; 
    int cont = 0, wordcont = 0, previous_wordcont = -1, New_word = 1, Ana_gram = 0, Word_end, Anagram_quant = 0;

    while(scanf("%c", &WORD) != EOF && WORD != '\n'){

        if(previous_wordcont != wordcont){
            Array_wordsize[wordcont] = 0;
            previous_wordcont = wordcont;
        }
        if(properLetter(WORD)){

            if(New_word == 1){Array_start[wordcont] = cont; New_word = 0;}
            Array_words[cont] = WORD;

            if(WORD>=65 && WORD<=90){
                WORD = WORD + 32;
            }

            Array_wordsize[wordcont] = Array_wordsize[wordcont]+WORD;


        }else{
            Array_words[cont] = WORD;
            New_word = 1;
            if((cont>0) && (properLetter(Array_words[cont-1]))){
                wordcont++;
                Word_end = cont;
            }
        }

        cont++;
    }

    Array_words[cont] = WORD;
    New_word = 1;
    if((cont>0) && (properLetter(Array_words[cont-1]))){
        wordcont++;
        Word_end = cont;
    }

    for(int i = 0; i<wordcont; i++){
        for(int j = i+1; j<wordcont; j++){
            if(Array_wordsize[i]==Array_wordsize[j]){

                if(Ana_gram == 0){
                    Ana_gram = 1;
                    printf("Pares de anagramas encontrados:\n");
                }

                cont = Array_start[i];
                while(properLetter(Array_words[cont])){
                    printf("%c", Array_words[cont]);
                    cont++;
                }
                printf(" e ");
                cont = Array_start[j];
                while(properLetter(Array_words[cont]) && cont<Word_end){
                    printf("%c", Array_words[cont]);
                    cont++;
                }
                printf("\n");
                Anagram_quant++;

            }
        }
    }

    if(Ana_gram == 0){
        printf("Nao existem anagramas na frase.");
    }else if (Ana_gram == 1)
    {
        printf("\nTotal de pares: %d\n", Anagram_quant);
    }
    

    return 0;
}