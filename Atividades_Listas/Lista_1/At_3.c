#include <stdio.h>
#include <math.h>

int main(){

    double Dinheiro_total, PORCA, PORCB, PORCC, VALA, VALB, VALC, SOBRA, Dinheiro_Rebeka = 3.0, INVEST = 0.0;

    scanf("%lf\n%lf\n%lf\n%lf", &Dinheiro_total, &PORCA, &PORCB, &PORCC);

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

                    if(fmod((Dinheiro_total/100)*PORCA, 1.0)==0&&fmod((Dinheiro_total/100)*PORCB, 1.0)==0&&fmod((Dinheiro_total/100)*PORCC, 1.0)==0){ // 2
                        
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
                        }
                    }
                }
            }
        }
    }

    return 0;
}