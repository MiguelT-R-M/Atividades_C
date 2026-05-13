#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef union{
    unsigned char Raw_byte;
    struct{

        unsigned int Erro : 1;
        unsigned int Modo : 3;
        unsigned int Leitura : 4;

    } bitfield;
} simulador;


int main(void){

    int Received_byte; scanf(" %d", &Received_byte);
    simulador Full_sim = {Received_byte};
    
    printf("Byte bruto: %hhu | Erro: %hhu | Modo: %hhu | Leitura: %hhu\n", Full_sim.Raw_byte, Full_sim.bitfield.Erro, Full_sim.bitfield.Modo, Full_sim.bitfield.Leitura);

    return 0;
}