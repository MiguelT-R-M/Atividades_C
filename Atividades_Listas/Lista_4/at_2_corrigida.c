//CÓDIGO CORRIGIDO POR IA;;

#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    char parede[m][n];

    // 1. Leitura da matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &parede[i][j]);
        }
    }

    // 2. Simulação: Repetimos o processo enquanto a água ainda estiver se movendo
    int mudou = 1;
    while (mudou) {
        mudou = 0; // Resetamos a flag de mudança

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Se encontrarmos uma gota, verificamos para onde ela pode ir
                if (parede[i][j] == 'o') {
                    
                    // Regra 1: Tentar descer (se não for a última linha e houver espaço '.')
                    if (i + 1 < m && parede[i + 1][j] == '.') {
                        parede[i + 1][j] = 'o';
                        mudou = 1; // Algo mudou, precisamos de outra rodada
                    }
                    
                    // Regra 2: Se bater numa prateleira '#' embaixo, espalha pros lados
                    else if (i + 1 < m && parede[i + 1][j] == '#') {
                        
                        // Tenta ir para a esquerda
                        if (j - 1 >= 0 && parede[i][j - 1] == '.') {
                            parede[i][j - 1] = 'o';
                            mudou = 1;
                        }
                        
                        // Tenta ir para a direita
                        if (j + 1 < n && parede[i][j + 1] == '.') {
                            parede[i][j + 1] = 'o';
                            mudou = 1;
                        }
                    }
                }
            }
        }
    }

    // 3. Impressão do resultado final
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", parede[i][j]);
        }
        printf("\n");
    }

    return 0;
}