
// O C?DIGO FOI CORRIGIDO POR IA

#include <stdio.h>

int main() { // O C?DIGO FOI CORRIGIDO POR IA
    long long num_xupenio, n_canais;
    
    // Lendo a entrada inicial
    if (scanf("%lld %lld", &num_xupenio, &n_canais) != 2) return 0;

    long long melhor_canal = -1;
    long long melhor_minuto = -1;
    long long melhor_distancia = -1;
    long long melhor_valor_sequencia = -1;

    for (int i = 1; i <= n_canais; i++) {
        long long v1, v2;
        scanf("%lld %lld", &v1, &v2);

        long long f_penultimo = v1;
        long long f_ultimo = v2;
        
        // Vari?veis para guardar o melhor termo DESTE canal espec?fico
        long long canal_melhor_dist = -1;
        long long canal_melhor_minuto = -1;
        long long canal_melhor_valor = -1;

        // Vamos testar os termos da sequ?ncia um por um
        for (int minuto = 1; ; minuto++) {
            long long termo_atual;

            if (minuto == 1) {
                termo_atual = v1;
            } else if (minuto == 2) {
                termo_atual = v2;
            } else {
                termo_atual = f_penultimo + f_ultimo;
                f_penultimo = f_ultimo;
                f_ultimo = termo_atual;
            }

            // C?lculo da dist?ncia (valor absoluto manual)
            long long dist_atual = termo_atual - num_xupenio;
            if (dist_atual < 0) dist_atual = -dist_atual;

            // REGRA 1: Melhor termo dentro do canal
            // Se for o primeiro minuto OU dist?ncia menor OU dist?ncia igual com valor menor
            if (canal_melhor_minuto == -1 || dist_atual < canal_melhor_dist || 
               (dist_atual == canal_melhor_dist && termo_atual < canal_melhor_valor)) {
                
                canal_melhor_dist = dist_atual;
                canal_melhor_minuto = minuto;
                canal_melhor_valor = termo_atual;
            }

            // Condi??o de parada: se o termo j? passou muito do alvo, a dist?ncia s? vai aumentar
            if (termo_atual > num_xupenio && termo_atual > v1 && termo_atual > v2) {
                // Se a dist?ncia atual j? ? maior que a melhor que achamos, pode parar
                if (dist_atual > canal_melhor_dist) break;
            }
            
            // Seguran?a para evitar loops infinitos em casos de 0 0
            if (minuto > 100) break;
        }

        // REGRA 2: Compara??o entre canais diferentes
        // "Se dist?ncias iguais, pegue o canal de ?ndice maior"
        // Como o loop 'i' caminha do 1 ao N, o '>=' ou '<=' garante o maior ?ndice
        if (melhor_canal == -1 || canal_melhor_dist < melhor_distancia || 
           (canal_melhor_dist == melhor_distancia)) {
            
            melhor_distancia = canal_melhor_dist;
            melhor_canal = i;
            melhor_minuto = canal_melhor_minuto;
            melhor_valor_sequencia = canal_melhor_valor;
        }
    }

    // C?lculo da soma dos algarismos do campe?o para o VIP
    long long temp_valor = melhor_valor_sequencia;
    int soma_digitos = 0;
    while (temp_valor > 0) {
        soma_digitos += (temp_valor % 10);
        temp_valor /= 10;
    }

    // Sa?da final formatada
    if (soma_digitos > 10) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %lld e sera chamado mais ou menos no minuto %lld e com o VIP garantido!!!\n", melhor_canal, melhor_minuto);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %lld e sera chamado mais ou menos no minuto %lld, mas o ingresso VIP n�o vai rolar :(\n", melhor_canal, melhor_minuto);
    }

    return 0;
}

// O C?DIGO FOI CORRIGIDO POR IA
