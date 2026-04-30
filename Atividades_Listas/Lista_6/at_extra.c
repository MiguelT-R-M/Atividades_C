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
    void (*RegFunc[5])(ash**, int*);
}reg;

void checkNull(void *Pointer);
void cadastroTreinador(ash **Treinadores, int *Ash_quant);
void cadastroPokemon(ash **Treinadores, int *Ash_quant);
void trainerUpdater(ash **Treinadores, int Current_trainer, int Ash_quant);
void listarClass(ash **Treinadores, int *Ash_quant);
char* typePrint(int Type_enum);
void trainerRemove(ash **Treinadores, int *Ash_quant);
void pokeUpdate(ash **Treinadores, int *Ash_quant);
void freeAll(ash **Treinadores, int Ash_quant);

int main(void){

    int Ash_quant = 0, Current_reg;
    ash *Treinadores = NULL;
    reg Registrador;
    
    Registrador.RegFunc[0] = cadastroTreinador;
    Registrador.RegFunc[1] = cadastroPokemon;   
    Registrador.RegFunc[2] = listarClass;
    Registrador.RegFunc[3] = trainerRemove;
    Registrador.RegFunc[4] = pokeUpdate;

    while((scanf("%d", &Current_reg)!=EOF)&&(Current_reg!=0)){
        Registrador.RegFunc[Current_reg-1](&Treinadores, &Ash_quant);
    }

    freeAll(&Treinadores, Ash_quant);
    return 0;
}

void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}

void cadastroTreinador(ash **Treinadores, int *Ash_quant){

    char TEMPNOME[50]; int TEMPCPF, TEMPIDADE; scanf("%49s", TEMPNOME); scanf("%d", &TEMPCPF); scanf("%d", &TEMPIDADE);
    int END = 0;

    for(int i = 0; i<(*Ash_quant); i++){
        if((*Treinadores)[i].CPF==TEMPCPF){
            END = 1;
        }
    }
    if(END == 0){
        *Ash_quant += 1;
        ash *TEMPOINTER = realloc((*Treinadores), *Ash_quant*sizeof(*(*Treinadores)));
        checkNull(TEMPOINTER);
        *Treinadores = TEMPOINTER;

        strcpy((*Treinadores)[*Ash_quant-1].Nome, TEMPNOME); (*Treinadores)[*Ash_quant-1].CPF = TEMPCPF; (*Treinadores)[*Ash_quant-1].Idade = TEMPIDADE;

        (*Treinadores)[*Ash_quant-1].LVL = 0; (*Treinadores)[*Ash_quant-1].Poke_quant = 0;
    }

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
    poke *TEMPOINTER = realloc((*Treinadores)[Current_trainer].Pokemons, (*Treinadores)[Current_trainer].Poke_quant*(sizeof(poke)));
    checkNull(TEMPOINTER);
    (*Treinadores)[Current_trainer].Pokemons = TEMPOINTER;

    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ID = TEMPID;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].XP = TEMPXP;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ATK = TEMPATK;
    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].Type = TEMPTIPO;
    strcpy((*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].Nome, TEMPNOME);

    (*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].STR = (2*(*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].XP)+(*Treinadores)[Current_trainer].Pokemons[(*Treinadores)[Current_trainer].Poke_quant-1].ATK;

    trainerUpdater(&(*Treinadores), Current_trainer, *Ash_quant);

}

void trainerUpdater(ash **Treinadores, int Current_trainer, int Ash_quant){

    (*Treinadores)[Current_trainer].LVL = 0;

    for(int i = 0; i<(*Treinadores)[Current_trainer].Poke_quant; i++){
        (*Treinadores)[Current_trainer].LVL += (*Treinadores)[Current_trainer].Pokemons[i].STR;
    }

    for(int i = 0; i<Ash_quant; i++){
        for(int j = i+1; j<Ash_quant; j++){
            if((*Treinadores)[j].LVL>(*Treinadores)[i].LVL){
                ash TEMPTRAINER = (*Treinadores)[i];
                (*Treinadores)[i] = (*Treinadores)[j];
                (*Treinadores)[j] = TEMPTRAINER;
            }
        }
    }

    for(int i = 0; i<Ash_quant; i++){
        for(int j = 0; j<(*Treinadores)[i].Poke_quant; j++){
            for(int k = j+1; k<(*Treinadores)[i].Poke_quant; k++){
                if((*Treinadores)[i].Pokemons[k].STR>(*Treinadores)[i].Pokemons[j].STR){
                    poke TEMPOKE = (*Treinadores)[i].Pokemons[j];
                    (*Treinadores)[i].Pokemons[j] = (*Treinadores)[i].Pokemons[k];
                    (*Treinadores)[i].Pokemons[k] = TEMPOKE;
                }
            }
        }
    }

}

void listarClass(ash **Treinadores, int *Ash_quant){

    printf("Classificação atual\n");
    for(int i = 0; i<*Ash_quant; i++){
        printf("T: %s, CPF: %d, Nivel: %d\n", (*Treinadores)[i].Nome, (*Treinadores)[i].CPF, (*Treinadores)[i].LVL);
        for(int j = 0; j<(*Treinadores)[i].Poke_quant; j++){
            printf("  P: %d, %s, %d, %d, %s\n", (*Treinadores)[i].Pokemons[j].ID, (*Treinadores)[i].Pokemons[j].Nome, (*Treinadores)[i].Pokemons[j].XP, (*Treinadores)[i].Pokemons[j].ATK, typePrint((*Treinadores)[i].Pokemons[j].Type));
        }
    }

}

char* typePrint(int Type_enum){

    switch (Type_enum){  
    case 0:
        return("Fogo");
        break;
    case 1:
        return("Agua");
        break;
    case 2:
        return("Eletricidade");
        break;
    case 3:
        return("Planta");
        break;
    default:
        break;
    }

}

void trainerRemove(ash **Treinadores, int *Ash_quant){

    int TEMPCPF; scanf("%d", &TEMPCPF);
    int Current_trainer = -1;

    for(int i = 0; i<(*Ash_quant); i++){
        if((*Treinadores)[i].CPF==TEMPCPF){
            Current_trainer =  i;
            break;
        }
    }

    if(Current_trainer>=0){
        if((*Treinadores)[Current_trainer].Poke_quant>0){
            free((*Treinadores)[Current_trainer].Pokemons);
        }

        for(int i = Current_trainer+1; i<(*Ash_quant); i++){
            (*Treinadores)[i-1] = (*Treinadores)[i];
        }

        (*Ash_quant)-=1;

        ash *TEMPOINTER = realloc((*Treinadores), (*Ash_quant)*(sizeof(*(*Treinadores))));
        if((*Ash_quant)>0){checkNull(TEMPOINTER);}
        (*Treinadores) = TEMPOINTER; 
    }

}

void pokeUpdate(ash **Treinadores, int *Ash_quant){

    int TEMPCPF, TEMPID; scanf("%d", &TEMPCPF); scanf("%d", &TEMPID);
    int Current_trainer = -1, Current_poke = -1;
    int TEMPXP, TEMPATK, TEMPTIPO; char TEMPNOME[50]; 
    scanf("%49s", TEMPNOME); scanf("%d", &TEMPXP); scanf("%d", &TEMPATK); scanf("%d", &TEMPTIPO);

    for(int i = 0; i<(*Ash_quant); i++){
        if((*Treinadores)[i].CPF==TEMPCPF){
            Current_trainer =  i;
            break;
        }
    }

    if(Current_trainer>=0){
        for(int i = 0; i<(*Treinadores)[Current_trainer].Poke_quant; i++){
            if((*Treinadores)[Current_trainer].Pokemons[i].ID==TEMPID){
                Current_poke =  i;
                break;
            }
        }
    }

    if((Current_trainer>=0)&&(Current_poke>=0)){

        (*Treinadores)[Current_trainer].Pokemons[Current_poke].ATK = TEMPATK;
        (*Treinadores)[Current_trainer].Pokemons[Current_poke].XP = TEMPXP;
        (*Treinadores)[Current_trainer].Pokemons[Current_poke].Type = TEMPTIPO;
        strcpy((*Treinadores)[Current_trainer].Pokemons[Current_poke].Nome, TEMPNOME);
        (*Treinadores)[Current_trainer].Pokemons[Current_poke].STR = (2*(*Treinadores)[Current_trainer].Pokemons[Current_poke].XP)+(*Treinadores)[Current_trainer].Pokemons[Current_poke].ATK;

        trainerUpdater(&(*Treinadores), Current_trainer, (*Ash_quant));
    }
}

void freeAll(ash **Treinadores, int Ash_quant){

    for(int i = 0; i<Ash_quant; i++){
        if((*Treinadores)[i].Poke_quant>0){
            free((*Treinadores)[i].Pokemons);
        }
    }
    free((*Treinadores));

}

