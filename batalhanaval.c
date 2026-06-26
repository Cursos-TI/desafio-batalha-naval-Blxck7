#include <stdio.h>

int main(){

    // 1 - Variáveis
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',};

    // 2 - Tabuleiro
    int tabuleiro[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // 3 - Navio na Horizontal
    for(int i = 0; i < 3; i++){
        tabuleiro[2][3 + i] = 3;
    }

    // 4 - Navio na Vertical
    for(int i = 0; i < 3; i++){
        tabuleiro[5 + i][7] = 3;
    }

    // 5 -  Mostrando o Tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");

    // 6 - Mostra as letras da Coordenada
    for(int i = 0; i < 10; i++){
        printf(" %c", linha[i]);
    }
    printf("\n");

    // 7 - Mostra os números da Coordenada
    for(int i = 0; i < 10; i++){

    // 8 - Ajustando o 10 para ele não ficar fora de linha no tabuleiro
        if(i == 9){
            printf("%d", i + 1);
        } else {
            printf(" %d", i + 1);
        }

    // 9 - Exibe o tabuleiro
    for (int j = 0; j < 10; j++){
        printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }



    return 0;
}