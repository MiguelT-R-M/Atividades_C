#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum tipo{
    Fogo,
    Agua,
    Eletricidade,
    Planta
} tip;

typedef struct pokemon{

    int ID;
    char Nome[50];
    tip Type;
    int XP;
    int ATK;
    int STR;

} poke;

typedef struct treinador{

    char Nome[50];
    int CPF;
    int Idade;
    poke *Pokemons;
    int Poke_quant;
    int LVL;

} ash;

typedef struct registro{
    void (*RegFunc[2])(ash**, int*);
}reg;

void checkNull(void *Pointer);
void cadastroTreinador(ash **Treinadores, int *Ash_quant);
void cadastroPokemon(ash **Treinadores, int *Ash_quant);
void trainerUpdater(ash **Treinadores, int Current_trainer);

int main(void){

    int Ash_quant = 0, Current_reg;
    ash *Treinadores = NULL;
    reg Registrador;
    
    Registrador.RegFunc[0] = cadastroTreinador;
    Registrador.RegFunc[1] = cadastroPokemon;   

    while((scanf("%d", &Current_reg)!=EOF)&&(Current_reg!=-1)){
        Registrador.RegFunc[Current_reg-1](&Treinadores, &Ash_quant);
    }

    for(int i = 0; i<Ash_quant; i++){
        if(Treinadores[i].Poke_quant>0){
            free(Treinadores[i].Pokemons);
        }
    }
    free(Treinadores);
    return 0;
}

void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}

void cadastroTreinador(ash **Treinadores, int *Ash_quant){

    *Ash_quant += 1;
    ash *TEMPOINTER = realloc((*Treinadores), *Ash_quant*sizeof(*(*Treinadores)));
    checkNull(TEMPOINTER);
    *Treinadores = TEMPOINTER;

    char TEMPNOME[50]; int TEMPCPF, TEMPIDADE; scanf("%49s", TEMPNOME); scanf("%d", &TEMPCPF); scanf("%d", &TEMPIDADE);

    strcpy((*Treinadores)[*Ash_quant-1].Nome, TEMPNOME); (*Treinadores)[*Ash_quant-1].CPF = TEMPCPF; (*Treinadores)[*Ash_quant-1].Idade = TEMPIDADE;

    (*Treinadores)[*Ash_quant-1].LVL = 0; (*Treinadores)[*Ash_quant-1].Poke_quant = 0;

}

void cadastroPokemon(ash **Treinadores, int *Ash_quant){

    int TEMPCPF, Current_trainer = 0; scanf("%d", &TEMPCPF);
    int TEMPID, TEMPXP, TEMPATK, TEMPTIPO; char TEMPNOME[50]; 
    scanf("%d", &TEMPID); scanf("%49s", TEMPNOME); scanf("%d", &TEMPXP); scanf("%d", &TEMPATK); scanf("%d", &TEMPTIPO); 

    for(int i = 0; i<*Ash_quant; i++){
        if((*Treinadores)[i].CPF==TEMPCPF){
            break;
        }else{
            Current_trainer++;
        }
    }
    if(Current_trainer>=*Ash_quant){
        return;
    }else if((*Treinadores)[Current_trainer].Poke_quant>=7){
        return;
    }

    for(int i = 0; i<(*Treinadores)[Current_trainer].Poke_quant; i++){
        if(TEMPID == (*Treinadores)[Current_trainer].Pokemons[i].ID){
            return;
        }
    }

    (*Treinadores)[Current_trainer].Poke_quant++;
    poke *TEMPOINTER = realloc((*Treinadores)[Current_trainer].Pokemons, (*Treinadores)[Current_trainer].Poke_quant*(sizeof(*((*Treinadores)[Current_trainer].Pokemons))));
    checkNull(TEMPOINTER);
    (*Treinadores)[Current_trainer].Pokemons = TEMPOINTER;

    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ID = TEMPID;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].XP = TEMPXP;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ATK = TEMPATK;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].Type = TEMPTIPO;
    strcpy((*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].Nome, TEMPNOME);

    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].STR = (2*(*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].XP)+(*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ATK;

    trainerUpdater(&(*Treinadores), Current_trainer);

}

void trainerUpdater(ash **Treinadores, int Current_trainer){

    (*Treinadores)[Current_trainer].LVL = 0;

    for(int i = 0; i<(*Treinadores)[Current_trainer].Poke_quant; i++){
        (*Treinadores)[Current_trainer].LVL += (*Treinadores)[Current_trainer].Pokemons[i].STR;
    }

}

