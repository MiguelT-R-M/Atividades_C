#include <stdio.h>
#include <math.h>

int main(){

    double Dinheiro_total, PORCA, PORCB, PORCC, VALA, VALB, VALC, SOBRA, Dinheiro_Rebeka = 3.0, INVEST = 0.0;

    scanf("%lf\n%lf\n%lf\n%lf\n", &Dinheiro_total, &PORCA, &PORCB, &PORCC);

    if(fmod((Dinheiro_total/100)*PORCA, 1.0)==0&&fmod((Dinheiro_total/100)*PORCB, 1.0)==0&&fmod((Dinheiro_total/100)*PORCC, 1.0)==0){ // 0
        
        SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);
        printf("Cada homem ficou com %.0lf, %.0lf e %.0lf reais, respectivamente\n", (Dinheiro_total/100)*PORCA, (Dinheiro_total/100)*PORCB, (Dinheiro_total/100)*PORCC);
        Dinheiro_Rebeka+=SOBRA;
        if(Dinheiro_Rebeka>=7.0){
            printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
        }else if(Dinheiro_Rebeka<7.0){
            printf("E parece que Rebeka vai ter que voltar andando...\n");
        }
        
    }else if(fmod((Dinheiro_total/100)*PORCA, 1.0)!=0||fmod((Dinheiro_total/100)*PORCB, 1.0)!=0||fmod((Dinheiro_total/100)*PORCC, 1.0)!=0){
        
        Dinheiro_total+=1.0;
        INVEST+=1.0;
        SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);

        if(SOBRA-1.0>=INVEST){ 

            Dinheiro_Rebeka-=1.0;

            if(fmod((Dinheiro_total/100)*PORCA, 1.0)==0&&fmod((Dinheiro_total/100)*PORCB, 1.0)==0&&fmod((Dinheiro_total/100)*PORCC, 1.0)==0){ // 1

                SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);
                printf("Cada homem ficou com %.0lf, %.0lf e %.0lf reais, respectivamente\n", (Dinheiro_total/100)*PORCA, (Dinheiro_total/100)*PORCB, (Dinheiro_total/100)*PORCC);
                Dinheiro_Rebeka+=SOBRA;
                if(Dinheiro_Rebeka>=7.0){
                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                }else if(Dinheiro_Rebeka<7.0){
                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                }

            }else if(fmod((Dinheiro_total/100)*PORCA, 1.0)!=0||fmod((Dinheiro_total/100)*PORCB, 1.0)!=0||fmod((Dinheiro_total/100)*PORCC, 1.0)!=0){
                
                Dinheiro_total+=1.0;
                INVEST+=1.0;
                SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);

                if(SOBRA-1.0>=INVEST){
                    
                    Dinheiro_Rebeka-=1.0;

                    char LA, LB, LC;
                    int VA, VB, VC;
                    scanf("%c\n%c\n%c", &LA, &LB, &LC);           

                    switch (LA)
                    {
                    case 'a':
                        VA = 1;
                        break;
                    case 'b':
                        VA = 2;
                        break;
                    case 'c':
                        VA = 3;
                        break;
                    case 'd':
                        VA = 4;
                        break;
                    case 'e':
                        VA = 5;
                        break;
                    case 'f':
                        VA = 6;
                        break;
                    case 'g':
                        VA = 7;
                        break;
                    case 'h':
                        VA = 8;
                        break;
                    case 'i':
                        VA = 9;
                        break;
                    case 'j':
                        VA = 10;
                        break;
                    case 'k':
                        VA = 11;
                        break;
                    case 'l':
                        VA = 12;
                        break;
                    case 'm':
                        VA = 13;
                        break;
                    case 'n':
                        VA = 14;
                        break;
                    case 'o':
                        VA = 15;
                        break;
                    case 'p':
                        VA = 16;
                        break;
                    case 'q':
                        VA = 17;
                        break;
                    case 'r':
                        VA = 18;
                        break;
                    case 's':
                        VA = 19;
                        break;
                    case 't':
                        VA = 20;
                        break;
                    case 'u':
                        VA = 21;
                        break;
                    case 'v':
                        VA = 22;
                        break;
                    case 'w':
                        VA = 23;
                        break;
                    case 'x':
                        VA = 24;
                        break;
                    case 'y':
                        VA = 25;
                        break;
                    case 'z':
                        VA = 26;
                        break;
                    default:
                        VA = 0;
                    }

                    switch (LB)
                    {
                    case 'a':
                        VB = 1;
                        break;
                    case 'b':
                        VB = 2;
                        break;
                    case 'c':
                        VB = 3;
                        break;
                    case 'd':
                        VB = 4;
                        break;
                    case 'e':
                        VB = 5;
                        break;
                    case 'f':
                        VB = 6;
                        break;
                    case 'g':
                        VB = 7;
                        break;
                    case 'h':
                        VB = 8;
                        break;
                    case 'i':
                        VB = 9;
                        break;
                    case 'j':
                        VB = 10;
                        break;
                    case 'k':
                        VB = 11;
                        break;
                    case 'l':
                        VB = 12;
                        break;
                    case 'm':
                        VB = 13;
                        break;
                    case 'n':
                        VB = 14;
                        break;
                    case 'o':
                        VB = 15;
                        break;
                    case 'p':
                        VB = 16;
                        break;
                    case 'q':
                        VB = 17;
                        break;
                    case 'r':
                        VB = 18;
                        break;
                    case 's':
                        VB = 19;
                        break;
                    case 't':
                        VB = 20;
                        break;
                    case 'u':
                        VB = 21;
                        break;
                    case 'v':
                        VB = 22;
                        break;
                    case 'w':
                        VB = 23;
                        break;
                    case 'x':
                        VB = 24;
                        break;
                    case 'y':
                        VB = 25;
                        break;
                    case 'z':
                        VB = 26;
                        break;
                    default:
                        VB = 0;
                    }

                    switch (LC)
                    {
                    case 'a':
                        VC = 1;
                        break;
                    case 'b':
                        VC = 2;
                        break;
                    case 'c':
                        VC = 3;
                        break;
                    case 'd':
                        VC = 4;
                        break;
                    case 'e':
                        VC = 5;
                        break;
                    case 'f':
                        VC = 6;
                        break;
                    case 'g':
                        VC = 7;
                        break;
                    case 'h':
                        VC = 8;
                        break;
                    case 'i':
                        VC = 9;
                        break;
                    case 'j':
                        VC = 10;
                        break;
                    case 'k':
                        VC = 11;
                        break;
                    case 'l':
                        VC = 12;
                        break;
                    case 'm':
                        VC = 13;
                        break;
                    case 'n':
                        VC = 14;
                        break;
                    case 'o':
                        VC = 15;
                        break;
                    case 'p':
                        VC = 16;
                        break;
                    case 'q':
                        VC = 17;
                        break;
                    case 'r':
                        VC = 18;
                        break;
                    case 's':
                        VC = 19;
                        break;
                    case 't':
                        VC = 20;
                        break;
                    case 'u':
                        VC = 21;
                        break;
                    case 'v':
                        VC = 22;
                        break;
                    case 'w':
                        VC = 23;
                        break;
                    case 'x':
                        VC = 24;
                        break;
                    case 'y':
                        VC = 25;
                        break;
                    case 'z':
                        VC = 26;
                        break;
                    default:
                        VC = 0;
                    }

                    int Soma_letra = VA+VB+VC;

                    if(fmod((Dinheiro_total/100)*PORCA, 1.0)==0&&fmod((Dinheiro_total/100)*PORCB, 1.0)==0&&fmod((Dinheiro_total/100)*PORCC, 1.0)==0){ // 2

                        SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);
                        printf("Cada homem ficou com %.0lf, %.0lf e %.0lf reais, respectivamente\n", (Dinheiro_total/100)*PORCA, (Dinheiro_total/100)*PORCB, (Dinheiro_total/100)*PORCC);
                        printf("%d\n", Soma_letra);
                        Dinheiro_Rebeka+=SOBRA;
                        if(Dinheiro_Rebeka>=7.0){
                            printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                        }else if(Dinheiro_Rebeka<7.0){
                            printf("E parece que Rebeka vai ter que voltar andando...\n");
                        }

                    }else if(fmod((Dinheiro_total/100)*PORCA, 1.0)!=0||fmod((Dinheiro_total/100)*PORCB, 1.0)!=0||fmod((Dinheiro_total/100)*PORCC, 1.0)!=0){
                        
                        Dinheiro_total+=1.0;
                        INVEST+=1.0;
                        SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);

                        if(SOBRA-1.0>=INVEST){
                            
                            Dinheiro_Rebeka-=1.0;

                            if(fmod((Dinheiro_total/100)*PORCA, 1.0)==0&&fmod((Dinheiro_total/100)*PORCB, 1.0)==0&&fmod((Dinheiro_total/100)*PORCC, 1.0)==0){ // 3
                                
                                SOBRA = (Dinheiro_total)-((Dinheiro_total/100)*PORCA+(Dinheiro_total/100)*PORCB+(Dinheiro_total/100)*PORCC);
                                printf("Cada homem ficou com %.0lf, %.0lf e %.0lf reais, respectivamente\n", (Dinheiro_total/100)*PORCA, (Dinheiro_total/100)*PORCB, (Dinheiro_total/100)*PORCC);
                                Dinheiro_Rebeka+=SOBRA;
                                if(Dinheiro_Rebeka>=7.0){
                                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                                }else if(Dinheiro_Rebeka<7.0){
                                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                                }

                            }else{
                                printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                                if(Dinheiro_Rebeka>=7.0){
                                    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                                }else if(Dinheiro_Rebeka<7.0){
                                    printf("E parece que Rebeka vai ter que voltar andando...\n");
                                }
                            }
                        }else{
                            printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                            printf("%d\n", Soma_letra);
                            if(Dinheiro_Rebeka>=7.0){
                                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                            }else if(Dinheiro_Rebeka<7.0){
                                printf("E parece que Rebeka vai ter que voltar andando...\n");
                            }
                        }
                    }
                }else{
                    printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
                    if(Dinheiro_Rebeka>=7.0){
                        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
                    }else if(Dinheiro_Rebeka<7.0){
                        printf("E parece que Rebeka vai ter que voltar andando...\n");
                    }
                }
            }
        }else{
            printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
            if(Dinheiro_Rebeka>=7.0){
                printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
            }else if(Dinheiro_Rebeka<7.0){
                printf("E parece que Rebeka vai ter que voltar andando...\n");
            }
        }
    }

    return 0;
}