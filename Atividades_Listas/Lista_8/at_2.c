#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

typedef union{

    uint32_t Raw_data;
    struct{

        unsigned int ID : 10;
        unsigned int Status : 3;
        unsigned int Low_bat : 1;
        int Temp : 12;
        unsigned int Ctrl : 6;

    }bitfield;

} package;

void checkNull(void *Pointer);

int main(void){

    int Pack_amount = 0, Pack_max = 1;
    package *Pacotes = calloc(Pack_max, sizeof(*Pacotes)); 
    checkNull(Pacotes);
    uint32_t hexValue = 0;

    while(scanf("%X", &hexValue) && hexValue != 0){

        Pacotes[Pack_amount].Raw_data = hexValue;

        Pack_amount++;
        if(Pack_amount>=Pack_max){ // Aumento dinâmico quando chega-se no limite
            Pack_max*=2;
            package *TEMPOINTER = realloc(Pacotes, Pack_max*(sizeof(*TEMPOINTER)));
            checkNull(TEMPOINTER);
            Pacotes = TEMPOINTER;
        }
    }

    if(Pack_amount>0 && Pack_amount<Pack_max){ // Economia de espaço
        package *TEMPOINTER = realloc(Pacotes, Pack_amount*(sizeof(*TEMPOINTER)));
        checkNull(TEMPOINTER);
        Pacotes = TEMPOINTER;
    }

    for(int i = 0; i<Pack_amount; i++){
        printf("Pacote [%d] - Dado Bruto: 0x%08X\n", i+1, Pacotes[i].Raw_data);
        printf("ID do Sensor : %hhu\n", Pacotes[i].bitfield.ID);
        printf("Status : %hhu\n", Pacotes[i].bitfield.Status);
        if(Pacotes[i].bitfield.Low_bat == 0){
            printf("Bateria Baixa: Nao\n");
        }else{
            printf("Bateria Baixa: SIM (ALERTA)\n");
        }
        printf("Temperatura : %d graus\n", Pacotes[i].bitfield.Temp);
        printf("-------------------------------------------------\n");
    }

    free(Pacotes);
    return 0;
}

void checkNull(void *Pointer){
    if(Pointer==NULL){
        printf("Erro de memória, fechando código.");
        exit(1);
    }
}

