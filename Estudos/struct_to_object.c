    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #define QTD 2

    typedef struct cachorro{
        char Nome[50];
        int Idade;
        float Peso;
        char Raca[50];
        void (*Latir)(struct cachorro*);
    } dog;

    void dogLate(dog *Cachorro_atual);

    int main(void){

        dog Cachorros[QTD];
        for(int i = 0; i<QTD; i++){
            char TEMPNAME[50], BUFFER[50]; int TEMPINT; float TEMPFLOAT;
            printf("Informe o Nome do cachorro %d: ", i+1); scanf("%49s", TEMPNAME); strcpy(Cachorros[i].Nome, TEMPNAME);
            printf("\n");
            printf("Informe a idade do cachorro %s: ", TEMPNAME); scanf("%d", &TEMPINT); Cachorros[i].Idade = TEMPINT;
            printf("\n");
            printf("Informe o peso do cachorro %s: ", TEMPNAME); scanf("%f", &TEMPFLOAT); Cachorros[i].Peso = TEMPFLOAT;
            printf("\n");
            printf("Informe a raça do cachorro %s: ", TEMPNAME); scanf("%49s", BUFFER); strcpy(Cachorros[i].Raca, BUFFER);
            printf("\n");
            Cachorros[i].Latir = dogLate;
            printf("\n");
        }

        char Current_dog[50];
        printf("Informe o cachorro que está prestes a latir: ");
        while((scanf("%49s", Current_dog))&&(strcmp("Nenhum", Current_dog)!=0)){
            for(int i = 0; i<QTD; i++){
                if(strcmp(Cachorros[i].Nome, Current_dog)==0){
                    Cachorros[i].Latir(&Cachorros[i]);
                }
            }
            printf("Informe o cachorro que está prestes a latir: ");
        }
    }

    void dogLate(dog *Cachorro_atual){

        printf("Au Au AU! Meu nome é %s\n", (*Cachorro_atual).Nome);

    }