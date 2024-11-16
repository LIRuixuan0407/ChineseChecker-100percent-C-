#include "printBoard.h"

void printBoard(const int board[]) {
    
    for (int i = 0; i <= 8; i++) {
        if (i == 0) printf("   ");
        else printf("%d ", i);
    }

    printf("\n1  ");
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (board[i * 10 + j] == 1) {
                printf("# ");
            }
            else if (board[i * 10 + j] == 2) {
                printf("O ");
            }
            else {
                printf(". ");
            }
            if (j == 8 && i != 8) {
                printf("\n%d  ", i+1);
            }
        }
    }
    puts("");
}
