#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LINHAS][COLUNAS];
    
    //Matriz da cruz
    int cruz[5][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 5},
        {0, 0, 5, 0, 0}
    };
    
    // Parte horizontal da cruz
    for (int j = 0; j < 5; j++) {
        cruz[1][j] = 5;
    
    //Matriz do cone
    int cone[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5}
    };

    //Matriz do octaedro
    int octaedro[3][3] = {
        {0, 5, 0},
        {5, 5, 5},
        {0, 5, 0}
    };
    
    //Representação da água e o posicionamento dos navios nas diagonais
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++){
            tabuleiro[i][j] = 0;
            if (LINHAS == COLUNAS)
            {
                tabuleiro[i][i - 0] = 3; //diagonal principal
                //tabuleiro[i][10 - 1 - i] = 3; //diagonal segundária
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

    //Habilidade da cruz 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] != 0) {
                tabuleiro[i][j + 5] = cruz[i][j];
            }
        }
    }

    //Habilidade do cone 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] != 0) {
                tabuleiro[i + 7][j + 2] = cone[i][j];
            }
        }
    }

    //Habilidade do octaedro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (octaedro[i][j] != 0) {
                tabuleiro[i + 2][j + 0] = octaedro[i][j];
            }
        }
    }
    
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
}