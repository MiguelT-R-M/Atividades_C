#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Mecha Mecha;

typedef struct {
    char nome[30];
    int atrib1;     // Atk: Dano Base   | Def: Blindagem Fixa | Utl: Recup. Base
    int atrib2;     // Atk: Custo Ener. | Def: Bônus de Slot   | Utl: Multiplicador
    
    // Função Modular: deve ser atribuída conforme o tipo do sistema.
    // m: ponteiro para o mecha dono do sistema.
    // slot: o índice da posição de entrada deste sistema no array sistemas[]
    // input: o dano base enviado pelo Wintermute para o combate.
    // output: onde deve ser gravado o resultado final da operação.
    void (*subrotina)(Mecha *m, int slot, int input, int *output);
} SubSistema;

struct Mecha {
    int id;                // Identificador único (0 até N-1)
    char modelo[50];
    int energia_atual;
    int num_sistemas;
    int valor_wintermute;       // Contexto de dano enviado pelo Comando
    SubSistema sistemas[]; // O Flexible Array Member (FAM)
};

void checkNull(void *Pointer);
void mechaOrder(Mecha **Evas, int Mecha_quant);
void defesaFunc(Mecha *m, int slot, int input, int *output);
void utilidadeFunc(Mecha *m, int slot, int input, int *output);
void ataqueFunc(Mecha *m, int slot, int input, int *output);

int main(void){

    int Mecha_quant = 0; scanf("%d", &Mecha_quant);

    Mecha *Evas[Mecha_quant];

    for(int k = 0; k < Mecha_quant; k++) {
        Evas[k] = NULL;
    }

    for(int i = 0; i<Mecha_quant; i++){
        int TEMPID; scanf("%d", &TEMPID);
        char TEMPMODEL[50]; scanf("%49s", TEMPMODEL);
        int TEMPENERGY; scanf("%d", &TEMPENERGY);
        int Q; scanf("%d", &Q);


        Mecha *TEMPOINTER = realloc(Evas[i], sizeof(Mecha) + Q * (sizeof(SubSistema)));
        checkNull(TEMPOINTER);
        Evas[i] = TEMPOINTER;

        Evas[i]->id = TEMPID;
        strcpy(Evas[i]->modelo, TEMPMODEL);
        Evas[i]->energia_atual = TEMPENERGY;
        Evas[i]->num_sistemas = Q;

        for(int j = 0; j<Q; j++){
            char TEMPTIPO; scanf(" %c", &TEMPTIPO);
            char TEMPNOME[30]; scanf("%29s", TEMPNOME);
            int TEMPAT1, TEMPAT2; scanf("%d %d", &TEMPAT1, &TEMPAT2);

            if(TEMPTIPO == 'D'){
                (*Evas)[i].sistemas[j].subrotina = defesaFunc;
            }else if(TEMPTIPO == 'U'){
                (*Evas)[i].sistemas[j].subrotina = utilidadeFunc;
            }else if(TEMPTIPO == 'A'){
                (*Evas)[i].sistemas[j].subrotina = ataqueFunc;
            }

            strcpy((*Evas)[i].sistemas[j].nome, TEMPNOME);
            (*Evas)[i].sistemas[j].atrib1 = TEMPAT1; (*Evas)[i].sistemas[j].atrib2 = TEMPAT2;
        }

        int TEMPWINTER; scanf("%d", &TEMPWINTER);
        Evas[i]->valor_wintermute = TEMPWINTER; 
    }

    mechaOrder(Evas, Mecha_quant);

    printf("[RELATORIO DE MISSÃO: OPERAÇÃO LANÇA DE NETUNO]\n");
    
    for(int i = 0; i<Mecha_quant; i++){
        printf("ID: %d | MECHA: %s | ENERGIA: %d\n", Evas[i]->id, Evas[i]->modelo, Evas[i]->energia_atual);

        

        printf("ENERGIA FINAL: %d\n-----------------------------------------\n", Evas[i]->energia_atual);
    }

    printf("Esquadrao pronto para o combate.");

    return 0;
}

void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}
void mechaOrder(Mecha **Evas, int Mecha_quant){
    for(int i = 0; i<Mecha_quant;i++){
        for(int j = i+1; j<Mecha_quant; j++){
            if(Evas[i]->id>Evas[j]->id){
                Mecha *TEMPMECHA = Evas[i];
                Evas[i] = Evas[j];
                Evas[j] = TEMPMECHA;
            }
        }
    }
}
void defesaFunc(Mecha *m, int slot, int input, int *output){

}
void utilidadeFunc(Mecha *m, int slot, int input, int *output){

}
void ataqueFunc(Mecha *m, int slot, int input, int *output){

}