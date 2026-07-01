#include <stdio.h>
#include <stdlib.h>

void exibirTabuleiro(char letras[], int tabuleiro[10][10]) {
    // Mostra o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");

    // Letras da coordenada
    for(int i = 0; i < 10; i++) {
        printf(" %c", letras[i]);
    }
    printf("\n");

    // Números da coordenada
    for (int i = 0; i < 10; i++) {

        // Ajuste para o 10 não ficar fora da linha do tabuleiro
        if (i == 9) {
            printf("%d", i + 1);
        } else {
            printf(" %d", i + 1);
        }

        // Mostra o tabuleiro 10x10
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int escolhaJogador, linha, coluna;
    char colunaLetra;

    // 1 - Tabuleiro
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2 - Návio na horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][3 + i] = 3;
    }

    // 3 - Návio na vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[5 + i][7] = 3;
    }

    // 4 Návio na diagonal (Esquerda para Direita)
    for (int i = 0; i < 3; i++) {
        tabuleiro[4 + i][1 + i] = 3;
    }

    // 5 - Návio na diagonal (Direita para Esquerda)
    for (int i = 0; i < 3; i++) {
        tabuleiro[9 - i][3 + i] = 3;
    }

    while (1) {
        system("cls");
        exibirTabuleiro(letras, tabuleiro);

        printf("\n--- Habilidades ---\n");
        printf("1 - Cone\n");
        printf("2 - Cruz\n");
        printf("3 - Octaedro\n");
        printf("Escolha uma habilidade: ");
        scanf("%d", &escolhaJogador);

        // Escolhendo as coordenadas
        printf("Escolha a linha: ");
        scanf(" %d", &linha);
        linha = linha - 1;
        printf("Escolha a coluna: ");
        scanf(" %c", &colunaLetra);

        for (int i = 0; i < 10; i++) {
            if (letras[i] == colunaLetra) {
                coluna = i;
            }
        }

        switch (escolhaJogador) {
            case 1:
                // Cone
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (i == 0) {
                            tabuleiro[linha][coluna] = 5;
                        } else if (i == 1 && j < 3) {
                            tabuleiro[linha + i][coluna - i + j] = 5;
                        } else if (i == 2) {
                            tabuleiro[linha + i][coluna - i + j] = 5;
                        }
                    }
                }
            break;
            case 2:
                // Cruz
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (i != 2) {
                            tabuleiro[linha + i][coluna] = 5;
                        } else {
                            tabuleiro[linha + i][coluna - i + j] = 5;
                        }
                    }
                }
            break;
            case 3:
                // Octaedro
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (i == 0 || i == 4) {
                            tabuleiro[linha + i][coluna] = 5;
                        } else if ((i == 1 || i == 3) && j < 3) {
                            tabuleiro[linha + i][coluna - 1 + j] = 5;
                        } else if (i == 2) {
                            tabuleiro[linha + i][coluna - 2 + j] = 5;
                        }
                    }
                }
            break;
            default:
                printf("Opção Invalida!");
            break;
        }
    }

    return 0;
}