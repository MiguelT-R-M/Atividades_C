#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct entradas{

    char Titulo[50];
    char Genero[50];
    char Studio[50];
    char Console[50];
    int Nota;
    int Ano_lanc;

} games;

void printAno(games *Jogos, int Quant);
void printLetra(games *Jogos, int Quant);
void printStudio(games *Jogos, int Quant);
void printConsole(games *Jogos, int Quant);
void printColecao(games *Jogos, int Quant);

int main(void){

    int Quant; scanf("%d", &Quant);
    void (*Functions[5])(games*, int) = {printAno, printLetra, printStudio, printConsole, printColecao};

    games Jogos[Quant];
    
    for(int i = 0; i<Quant; i++){
        char TEMPTITULO[50], TEMPGENERO[50], TEMPSTUDIO[50], TEMPCONSOLE[50]; int TEMPNOTA, TEMPANO;
        scanf("%49s %49s %49s %49s %d %d", TEMPTITULO, TEMPGENERO, TEMPSTUDIO, TEMPCONSOLE, &TEMPNOTA, &TEMPANO);
        
        strcpy(Jogos[i].Titulo, TEMPTITULO); strcpy(Jogos[i].Genero, TEMPGENERO); strcpy(Jogos[i].Studio, TEMPSTUDIO); strcpy(Jogos[i].Console, TEMPCONSOLE);
        Jogos[i].Nota = TEMPNOTA; Jogos[i].Ano_lanc = TEMPANO;

        if(Jogos[i].Nota>7){
            printf("AWESOME! Mais um GOTY pra minha coleção!\n");
        }else if(Jogos[i].Nota<4){
            printf("Era melhor jogar mais um jogo de Mahjong.\n");
        }
    }

    char Current_func[50];
    while((scanf("%49s", Current_func)!= EOF)){
        if(strcmp(Current_func, "printAno")==0){Functions[0](Jogos, Quant);}
        if(strcmp(Current_func, "printLetra")==0){Functions[1](Jogos, Quant);}
        if(strcmp(Current_func, "printStudio")==0){Functions[2](Jogos, Quant);}
        if(strcmp(Current_func, "printConsole")==0){Functions[3](Jogos, Quant);}
        if(strcmp(Current_func, "printColecao")==0){Functions[4](Jogos, Quant);}
    }

    printf("Enjoei de jogar, agora vou ver TV.\n");

    return 0;
}

void printAno(games *Jogos, int Quant){

    int Current; scanf("%d", &Current);
    int Amount = 0;

    for(int i = 0; i<Quant; i++){
        if(Jogos[i].Ano_lanc==Current){
            printf("%s\n", Jogos[i].Titulo);
            Amount++;
        }
    }

    if(Amount>0){
        printf("Tenho %d jogos || %d.\n", Amount, Current);
    }else{
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    }
}
void printLetra(games *Jogos, int Quant){

    char Current; scanf(" %c", &Current);
    int Amount = 0;

    for(int i = 0; i<Quant; i++){
        if(Jogos[i].Titulo[0]==Current){
            printf("%s\n", Jogos[i].Titulo);
            Amount++;
        }
    }

    if(Amount>0){
        printf("Tenho %d jogos || %c.\n", Amount, Current);
    }else{
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    }

}
void printStudio(games *Jogos, int Quant){

    char Current[50]; scanf("%49s", Current);
    int Amount = 0;

    for(int i = 0; i<Quant; i++){
        if(strcmp(Jogos[i].Studio, Current)==0){
            printf("%s\n", Jogos[i].Titulo);
            Amount++;
        }
    }
    
    if(Amount>0){
        printf("Tenho %d jogos || %s.\n", Amount, Current);
    }else{
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    }
}
void printConsole(games *Jogos, int Quant){

    char Current[50]; scanf("%49s", Current);
    int Amount = 0;

    for(int i = 0; i<Quant; i++){
        if(strcmp(Jogos[i].Console, Current)==0){
            printf("%s\n", Jogos[i].Titulo);
            Amount++;
        }
    }

    if(Amount>0){
        printf("Tenho %d jogos || %s.\n", Amount, Current);
    }else{
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    }

}
void printColecao(games *Jogos, int Quant){

    for(int i = 0; i<Quant; i++){
        printf("%s %d\n", Jogos[i].Titulo, Jogos[i].Nota);
    }

}
