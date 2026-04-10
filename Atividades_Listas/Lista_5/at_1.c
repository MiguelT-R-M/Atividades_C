#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void printWords(char **WORDS, int Word_amount){ // Pra debug

    for(int i = 0; i<Word_amount; i++){

        printf("%s\n", WORDS[i]);

    }
    printf("\n");

}


int main(void){

    int Word_amount, Merged_wsize = 1; scanf("%d", &Word_amount);

    char **WORDS = calloc(Word_amount, sizeof(*WORDS)), *Merged_word = calloc(Merged_wsize, sizeof(*Merged_word)); 
    
    int *WORDS_size = calloc(Word_amount, sizeof(*WORDS_size)), *Indexes = calloc(Word_amount, sizeof(*Indexes));

    if((WORDS != NULL)&&(Merged_word != NULL)&&(WORDS_size != NULL)&&(Indexes != NULL)){

        for(int i = 0; i<Word_amount; i++){

            WORDS[i] = realloc(WORDS[i], 100);
            scanf("%s", WORDS[i]);
            WORDS_size[i] = strlen(WORDS[i]);
            WORDS[i] = realloc(WORDS[i], WORDS_size[i]);
            Merged_wsize += WORDS_size[i];

        }

        Merged_word = realloc(Merged_word, Merged_wsize);

        int CTRL = 0;

        for(int i = 0; i<Merged_wsize-1; i++){
        
            int cont = 0;
            
            while(1){

                if((cont<Word_amount)&&(Indexes[cont] >= Indexes[cont+1])&&(Indexes[cont] != CTRL)){
                    cont++;
                }else if(Indexes[cont]>=WORDS_size[cont]){
                    cont++;
                }else{
                    break;
                }

            }

            if(cont >= Word_amount-1){
                CTRL++;
            }

            Merged_word[i] = WORDS[cont][Indexes[cont]];

            Indexes[cont]++;

        }

        printWords(WORDS, Word_amount);
        printf("%s\n", Merged_word);

        free(WORDS); free(Merged_word); free(WORDS_size);
    }else{
        printf("Erro de alocação.");
        exit(1);
    }

    return 0;
}