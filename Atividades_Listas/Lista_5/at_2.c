#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int notasManipulation(int *Alunos_quant, float *NOTAS, float *MEDIA, float *Maior_nota, float *Menor_nota, int *Acima_media, float *MEDIANA, int *Moda_pos, int Novos_alunos_bool, int *Maior_nota_pos, int *Menor_nota_pos, int Novos_alunos, float *Notas_org, float *Soma_media){

    if(Novos_alunos_bool == 0){
        for(int i = (*Alunos_quant-Novos_alunos)*(Novos_alunos_bool); i<*Alunos_quant; i++){

            float TEMPFLOAT; scanf("%f", &TEMPFLOAT);
            NOTAS[i] =  TEMPFLOAT;
            *Soma_media+=NOTAS[i];

        }

        *MEDIA = *Soma_media/(*Alunos_quant);
        for(int i = 0; i<*Alunos_quant; i++){
            if(NOTAS[i]>*MEDIA){
                *Acima_media+=1;
            }
            if((NOTAS[i]>NOTAS[(int)*Maior_nota])){
                *Maior_nota = i;
            }
            if((NOTAS[i]<NOTAS[(int)*Menor_nota])){
                *Menor_nota = i;
            }
        }   
    }else{

        *Maior_nota = 0; *Menor_nota = 0; *MEDIA = 0; *Acima_media = 0;

        for(int i = (*Alunos_quant-Novos_alunos)*(Novos_alunos_bool); i<*Alunos_quant; i++){

            float TEMPFLOAT; scanf("%f", &TEMPFLOAT);
            NOTAS[i] =  TEMPFLOAT;
            *Soma_media+=NOTAS[i];

        }
        
        *MEDIA = *Soma_media/(*Alunos_quant);
        for(int i = 0; i<*Alunos_quant; i++){
            if(NOTAS[i]>*MEDIA){
                *Acima_media+=1;
            }
            if((NOTAS[i]>NOTAS[(int)*Maior_nota])){
                *Maior_nota = i;
            }
            if((NOTAS[i]<NOTAS[(int)*Menor_nota])){
                *Menor_nota = i;
            }
            
        }
    }
    *Maior_nota_pos = (int)*Maior_nota;
    *Menor_nota_pos = (int)*Menor_nota;
    *Maior_nota = NOTAS[(int)*Maior_nota];
    *Menor_nota = NOTAS[(int)*Menor_nota];

    for(int i = 0; i<*Alunos_quant; i++){
        Notas_org[i] = NOTAS[i];
    }

    for(int i = 0; i<*Alunos_quant; i++){
        for(int j = 1+i; j<*Alunos_quant; j++){
            if(Notas_org[j]<Notas_org[i]){
                float TEMPFLOAT = Notas_org[i];
                Notas_org[i] = Notas_org[j];
                Notas_org[j] = TEMPFLOAT;
            }
        }
    }

    if(*Alunos_quant%2==0){
        *MEDIANA = ((Notas_org[(*Alunos_quant-1)/2])+(Notas_org[((*Alunos_quant-1)/2)+1]))/2;
    }else{
        *MEDIANA = Notas_org[(*Alunos_quant/2)];
    }

    int Repeat_quant = 0, Repeat_max = 0;
    for(int i = 0; i<*Alunos_quant; i++){
        if((i<*Alunos_quant-1)&&(Notas_org[i]==Notas_org[i+1])){
            Repeat_quant++;
        }else{
            if(Repeat_quant>Repeat_max){ Repeat_max = Repeat_quant; *Moda_pos = i;}else if(Repeat_quant == Repeat_max){ *Moda_pos = -1;}
            Repeat_quant = 0;
        }
    }

}

int main(void){

    int Alunos_quant = 0, Novos_alunos_bool = 0, Novos_alunos = 0, Acima_media = 0, Moda_pos = 0, Maior_nota_pos = 0, Menor_nota_pos = 0; scanf("%d", &Alunos_quant);

    float *NOTAS = calloc(Alunos_quant, sizeof(*NOTAS)), *Notas_org = calloc(Alunos_quant, sizeof(*Notas_org)),MEDIA = 0.0, Maior_nota = 0, Menor_nota = 0, MEDIANA, Soma_media = 0;

    int *Alunos_quant_pont = &Alunos_quant, *Acima_media_pont = &Acima_media, *Moda_pos_pont = &Moda_pos, *Maior_nota_pos_pont = &Maior_nota_pos, *Menor_nota_pos_pont = &Menor_nota_pos;
    float *MEDIA_pont = &MEDIA, *Maior_nota_pont = &Maior_nota, *Menor_nota_pont = &Menor_nota, *MEDIANA_pont = &MEDIANA, *Soma_media_pont = &Soma_media;

    if((NOTAS != NULL)&&(Notas_org != NULL)){


        notasManipulation(Alunos_quant_pont, NOTAS, MEDIA_pont, Maior_nota_pont, Menor_nota_pont, Acima_media_pont, MEDIANA_pont, Moda_pos_pont, Novos_alunos_bool, Maior_nota_pos_pont, Menor_nota_pos_pont, Novos_alunos, Notas_org, Soma_media_pont);

        printf("Relatorio inicial\n");

        if(Moda_pos > 0){
            printf("Media: %.2f\nMaior nota: %.2f (aluno %d)\nMenor nota: %.2f (aluno %d)\nAcima da media: %d\nMediana: %.2f\nModa: %.2f\n\n", MEDIA, Maior_nota, Maior_nota_pos+1, Menor_nota, Menor_nota_pos+1, Acima_media, MEDIANA, Notas_org[Moda_pos]);
        }else{
            printf("Media: %.2f\nMaior nota: %.2f (aluno %d)\nMenor nota: %.2f (aluno %d)\nAcima da media: %d\nMediana: %.2f\nModa: Nao ha moda unica\n\n", MEDIA, Maior_nota, Maior_nota_pos+1, Menor_nota, Menor_nota_pos+1, Acima_media, MEDIANA);
        }

        scanf("%d", &Novos_alunos);
        Alunos_quant+=Novos_alunos;
        Novos_alunos_bool = 1;
        NOTAS = realloc(NOTAS, Alunos_quant * sizeof(*NOTAS));
        Notas_org = realloc(Notas_org, Alunos_quant * sizeof(*Notas_org));

        notasManipulation(Alunos_quant_pont, NOTAS, MEDIA_pont, Maior_nota_pont, Menor_nota_pont, Acima_media_pont, MEDIANA_pont, Moda_pos_pont, Novos_alunos_bool, Maior_nota_pos_pont, Menor_nota_pos_pont, Novos_alunos, Notas_org, Soma_media_pont);

        printf("Relatorio atualizado\n");
        if(Moda_pos > 0){
            printf("Media: %.2f\nMaior nota: %.2f (aluno %d)\nMenor nota: %.2f (aluno %d)\nAcima da media: %d\nMediana: %.2f\nModa: %.2f\n\n", MEDIA, Maior_nota, Maior_nota_pos+1, Menor_nota, Menor_nota_pos+1, Acima_media, MEDIANA, Notas_org[Moda_pos]);
        }else{
            printf("Media: %.2f\nMaior nota: %.2f (aluno %d)\nMenor nota: %.2f (aluno %d)\nAcima da media: %d\nMediana: %.2f\nModa: Nao ha moda unica\n\n", MEDIA, Maior_nota, Maior_nota_pos+1, Menor_nota, Menor_nota_pos+1, Acima_media, MEDIANA);
        }

        free(NOTAS); free(Notas_org);

    }else{

        printf("Alocação inválida de memória.");
        exit(1);

    }

    return 0;
}