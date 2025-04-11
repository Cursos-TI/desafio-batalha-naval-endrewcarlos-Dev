#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LINHAS][COLUNAS];

    //Representação da água e o posicionamento dos navios nas diagonais
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = 0;
            if (LINHAS == COLUNAS)
            {
                tabuleiro[i][i - 0] = 3; //diagonal principal
                tabuleiro[i][10 - 1 - i] = 3; //diagonal segundária
            }
        }
    }

    //Posicionamento dos navios na vertical e horizontal
    tabuleiro[2][3] = 3; 
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3; 
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    //Número de Colunas
    printf(" TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
    }
    printf("\n");

    //Imprime tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1); // número da linha começando em 1
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}