#include <stdio.h>
#include <math.h>   

int main(){

    int Ani_dia, Ani_mes, Ani_ano, Data_dia, Data_mes, Data_ano;
    int AMOR, SORTE, TRABALHO, COR;

    scanf("%d/%d/%d %d/%d/%d", &Ani_dia, &Ani_mes, &Ani_ano, &Data_dia, &Data_mes, &Data_ano); // scanf que pega todos os inputs do usuário
    int Soma_data = Ani_dia + Ani_mes + Ani_ano + Data_dia + Data_mes + Data_ano; // Soma de todas as datas
    int Soma_dias_meses = Ani_dia + Ani_mes + Data_dia + Data_mes; // Soma de todos os dias e meses

    AMOR = (Soma_data*7)%101;
    printf("Amor: %d%% ", AMOR);
    if(AMOR<20){
        printf("Pessimo dia para se apaixonar.\n");
    }else if(AMOR>=20 && AMOR<=40){
        printf("Melhor manter o coracao <3 longe de perigo.\n");
    }else if(AMOR>=41 && AMOR<=69){
        printf("Se o papo e as ideias baterem, esta liberado pensar em algo.\n");
    }else if(AMOR>=70 && AMOR<=80){
        printf("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.\n");
    }else if(AMOR>80){
        printf("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n");
    }

    SORTE = ((Soma_dias_meses*9)+(Data_ano-Ani_ano))%101;
    printf("Sorte: %d%% ", SORTE);
    if(SORTE<30){
        printf("Nem jogue moedas pra cima hoje.");
    }else if(SORTE>=30 && SORTE<=50){
        printf("Melhor nao arriscar.");
    }else if(SORTE>=51 && SORTE<=79){
        printf("Por sua conta em risco.");
    }else if(SORTE>=80 && SORTE<=90){
        printf("Hoje vale a pena arriscar.");
    }else if(SORTE>90){
        printf("Nao tenha medo de virar cartas hoje.");
    }
    printf(" Sem tigrinho nem jogos de azar, por favor!\n");

    TRABALHO = ((Data_ano+Ani_ano)-(Soma_dias_meses*8))%101;
    printf("Trabalho: %d%% ", TRABALHO);
    if(TRABALHO<40){
        printf("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.\n");
    }else if(TRABALHO>=40 && TRABALHO<=50){
        printf("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.\n");
    }else if(TRABALHO>=51 && TRABALHO<=69){
        printf("Um dia proveitoso com certeza, leve sua simpatia consigo.\n");
    }else if(TRABALHO>=70 && TRABALHO<=84){
        printf("Boas vibracoes hoje, chances podem estar ao seu redor.\n");
    }else if(TRABALHO>85){
        printf("Use do maximo de networking possível hoje, dia bom para negocios.\n");
    }

    COR = ((Ani_dia*Ani_dia)+(Ani_mes*Ani_mes)+(Ani_ano*Ani_ano)+(Data_dia*Data_dia)+(Data_mes*Data_mes)+(Data_ano*Data_ano))%11;
    printf("Cor: ");
    if(COR == 0){
        printf("Cinza.");
    }else if(COR ==1){
        printf("Vermelho.");
    }else if(COR ==2){
        printf("Laranja.");
    }else if(COR ==3){
        printf("Amarelo.");
    }else if(COR ==4){
        printf("Verde.");
    }else if(COR ==5){
        printf("Azul.");
    }else if(COR ==6){
        printf("Roxo.");
    }else if(COR ==7){
        printf("Marrom.");
    }else if(COR ==8){
        printf("Rosa.");
    }else if(COR ==9){
        printf("Preto.");
    }else if(COR ==10){
        printf("Branco.");
    }   

    return 0;
}