#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void wordMerge(int Merged_wsize, int Word_amount, int *Indexes, int *WORDS_size, char *Merged_word, char *WORDS[]){

    int CTRL = 0, CTRL2 = 1; // CTRL = variável para controlar quando o índice de todos são iguais; CTRL2 = variável que subtrai 1 pra cada indice final

    for(int i = 0; i<Merged_wsize-1; i++){ // for loop que itera em cada indice da merged word
    
        int cont = 0;
        
        while(1){ // loop que escolhe a palavra a ser retirada o char

            if((cont<Word_amount-1)&&(Indexes[cont] >= Indexes[cont+1])&&(Indexes[cont] != CTRL)){
                cont++;
            }else if(Indexes[cont]>=WORDS_size[cont]){
                cont++;
            }else{
                break;
            }

        }

        Merged_word[i] = WORDS[cont][Indexes[cont]]; // Define o char atual

        Indexes[cont]++;
        if(cont >= Word_amount-CTRL2){ // Detecta se esta na palavra final e aumenta a CTRL, se a final acabou, aumenta tambem a CTRL2
            CTRL++;
            if(Indexes[cont]>=WORDS_size[cont]){
                CTRL2+=1;
            }
        }
    }

}

void wordFusion(char *Fusion_form, int Merged_wsize, char *Merged_word){

    int Fusion_pos = 0, END = 1, Fusion_amount = 0, CONTINUE = 1;

    while(END){ // Loop que itera na Merged_word até ficar na forma certa

        END = 0; Fusion_pos = 0; Fusion_amount = 0, CONTINUE = 1;

        for(int i = 0; i<Merged_wsize-1; i++){ // for loop em si que itera

            if((CONTINUE == 1)&&(i<Merged_wsize-1)&&(Merged_word[i] == Merged_word[i+1])){

                if(Merged_word[i]>=97 && Merged_word[i]<122){Fusion_form[Fusion_pos] = Merged_word[i] + 1;}else{Fusion_form[Fusion_pos] = 'a';}
                if((i>0)&&(Fusion_form[Fusion_pos]==Fusion_form[Fusion_pos-1])){
                    END = 1;
                    Fusion_amount++;
                }
                i++;
                Fusion_pos++;
                CONTINUE = 0;

            }else{

                Fusion_form[Fusion_pos] = Merged_word[i];
                if((i>0)&&(Fusion_form[Fusion_pos]==Fusion_form[Fusion_pos-1])){
                    END = 1;
                    Fusion_amount++;
                }
                Fusion_pos++;

            }

        }

        strcpy(Merged_word, Fusion_form);
        if(END == 1){
            for(int i = 0; i<Fusion_pos; i++){
                Fusion_form[i] = '\0';
            }
        }
        Merged_wsize = Fusion_pos+1;

    }
}

int main(void){

    int Word_amount, Merged_wsize = 1; scanf("%d", &Word_amount);

    char *WORDS[Word_amount], *Merged_word = calloc(Merged_wsize, sizeof(*Merged_word)), *Fusion_form = calloc(Merged_wsize, sizeof(*Fusion_form)); 
    
    int *WORDS_size = calloc(Word_amount, sizeof(*WORDS_size)), *Indexes = calloc(Word_amount, sizeof(*Indexes));

    if((Merged_word != NULL)&&(WORDS_size != NULL)&&(Indexes != NULL)&&(Fusion_form != NULL)){

        for(int i = 0; i<Word_amount; i++){

            WORDS[i] = calloc(200, sizeof(*WORDS[i]));
            if(WORDS[i] != NULL){
                scanf("%s", WORDS[i]);
                WORDS_size[i] = strlen(WORDS[i]);
                WORDS[i] = realloc(WORDS[i], (WORDS_size[i]+1) * sizeof(*WORDS));
                Merged_wsize += WORDS_size[i];
            }else{
                printf("Problema de memória");
                exit(1);
            }

        }

        Merged_word = realloc(Merged_word, Merged_wsize * sizeof(*Merged_word)); Fusion_form = realloc(Fusion_form, Merged_wsize * sizeof(*Fusion_form)); // realoca pro tamanho certo

        wordMerge(Merged_wsize, Word_amount, Indexes, WORDS_size, Merged_word, WORDS); // Função que da merge nas palavras

        char True_merged_word[Merged_wsize]; strcpy(True_merged_word, Merged_word); // Merged word verdadeira

        wordFusion(Fusion_form, Merged_wsize, Merged_word); // Função que funde os chars
        
        printf("%s\n", True_merged_word);
        printf("%s\n", Fusion_form);

        free(Merged_word); free(WORDS_size); free(Indexes); free(Fusion_form);
        for(int i = 0; i<Word_amount; i++){
            free(WORDS[i]);
        }

    }else{
        printf("Erro de alocação.");
        exit(1);
    }

    return 0;
}