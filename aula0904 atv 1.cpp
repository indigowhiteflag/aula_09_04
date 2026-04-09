#include<stdio.h>


int main()
{
    int cpfs_inativos[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    int tamanho = 10;
    int alvo = 99;
    
    printf("--FASE 1 BUSCANDO O PELO CPF %d--\n", alvo);

    //1. BUSCA LINEAR (Brute Force / O(n))

    int passos_linear = 0;
    int encontrou_linear = 0;

    for (int i = 0; i < tamanho; i++) {
        passos_linear++;
        if (cpfs_inativos[i] == alvo) {
            encontrou_linear = 1;
            break;
        }
    }
    printf("\nABORDAGEM BUSCA LINEAR\n");
    if (encontrou_linear){
        printf("SUCESSO: O CPF %d FOI ENCONTRADO EM %d PASSOS\n", alvo, passos_linear);

        //2. BUSCA BINÁRIA (Binary Search / O(log n))
        int passos_binaria = 0;
        int encontrou_binaria = 0;

        int inicio = 0;
        int fim = tamanho - 1;
        while (inicio <= fim) {
            passos_binaria++;
            int meio = inicio + (fim - inicio) / 2;

            if (cpfs_inativos[meio] == alvo) {
                encontrou_binaria = 1;
                break;
            } else if (cpfs_inativos[meio] < alvo) {
                //SE O ALVO É MAIOR, DESCARTA A METADE ESQUERDA
                inicio = meio + 1;
            } else {
                //SE O ALVO É MENOR, DESCARTA A METADE DIREITA
                fim = meio - 1;
            }
        }
    
    printf("\nABORDAGEM BUSCA BINÁRIA\n");
    if (encontrou_binaria){
        printf("SUCESSO: O CPF %d FOI ENCONTRADO EM %d PASSOS\n", alvo, passos_binaria);
    }
}
    return 0;
}