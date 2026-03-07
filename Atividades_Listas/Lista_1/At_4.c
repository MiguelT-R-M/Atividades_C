#include <stdio.h>
#include <math.h>

int main(){

    int X, Y, Quadrante_evitado, XFOCO, YFOCO;
    
    scanf("%d %d %d", &X, &Y, &Quadrante_evitado);

    if( X>0 && Y>0 ){  // 1° quadrante
        XFOCO = -1; YFOCO = -1;

        if( Quadrante_evitado == 4){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em x e %u passos em y", MOVX, MOVY);
        }else if( Quadrante_evitado == 2){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em y e %u passos em x", MOVY, MOVX);
        }else{
            printf("caminhada invalida\n");
        }
    }else if( X<0 && Y>0 ){ // 2° quadrante
        XFOCO = 1; YFOCO = -1;

        if( Quadrante_evitado == 3){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em x e %u passos em y", MOVX, MOVY);
        }else if( Quadrante_evitado == 1){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em y e %u passos em x", MOVY, MOVX);
        }else{
            printf("caminhada invalida\n");
        }
    }else if( X<0 && Y<0 ){ // 3° quadrante
        XFOCO = 1; YFOCO = 1;

        if( Quadrante_evitado == 2){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em x e %u passos em y", MOVX, MOVY);
        }else if( Quadrante_evitado == 4){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em y e %u passos em x", MOVY, MOVX);
        }else{
            printf("caminhada invalida\n");
        }
    }else if( X>0 && Y<0 ){ // 4° quadrante
        XFOCO = -1; YFOCO = 1;

        if( Quadrante_evitado == 1){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em x e %u passos em y", MOVX, MOVY);
        }else if( Quadrante_evitado == 3){
            int MOVX = X - XFOCO; int MOVY = Y - YFOCO;
            if(MOVX<0){MOVX= MOVX*(-1);} if(MOVY<0){MOVY = MOVY*(-1);}

            printf("%u passos em y e %u passos em x", MOVY, MOVX);
        }else{
            printf("caminhada invalida\n");
        }
    }

    return 0;
}