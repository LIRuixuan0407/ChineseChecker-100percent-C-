#include <stdio.h>
#include "initializeBoard.h"
#include "isValidMove.h"
#include "readMove.h"
#include "checkGameOver.h"
#include "printBoard.h"
#include "ai_player.h"

int main(void) {
    int board[89];
    initializeBoard(board);
    int currentPlayer = 1; // 假设蓝方先手
    int moveCount = 0; // 记录步数
    int mode = 1;
    scanf("%d", &mode); // 1 为人人对战，2 为人机对战（机器人先手）
    
    if (mode == 1) {
        while (1) {
            printBoard(board);
            printf("\n%c\'s turn.\n\n", currentPlayer == 1 ? '#' : 'O');
            int move = readMove();
            int visited[9][9] = {0};
            int start = move / 100;
            int end = move % 100;
            int startY = start / 10;
            int startX = start % 10;
            int endY = end / 10;
            int endX = end % 10;
            
            if (move > 9999 || move < 1000) {
                printf("Invalid input format, please input again: \n");
                continue;
            }
            
            if (!isWithinBoard(startY, startX) || !isWithinBoard(endY, endX)) {
                printf("Input out of the game board, please input again: \n");
                continue;
            }
            
            if (board[start] != currentPlayer) {
                printf("Invalid starting location, please input again: \n");
                continue;
            }
            
            if (board[end] != 0) {
                printf("Invalid ending location, please input again: \n");
                continue;
            }
            
            if (isValidMove(board, move, currentPlayer, visited)) {
                makeMove(board, startX, startY, endX, endY);
                currentPlayer = 3 - currentPlayer; // 切换玩家
            }
            else {
                printf("The move violates the game rule, please input again.\n");
                continue;
            }
            
            moveCount++;
            if (checkGameOver(board, moveCount)) {
                if (checkGameOver(board, moveCount) == 1) {
                    printBoard(board);
                    printf("Blue(#) wins!\n");
                }
                else if (checkGameOver(board, moveCount) == 2) {
                    printBoard(board);
                    printf("Red(O) wins!\n");
                }
                else {
                    printBoard(board);
                    printf("Draw!\n");
                }
                break;
            }
        }
        return 0;
    }
    else if (mode == 2) {
        while (1) {
            printBoard(board);
            printf("\n%c\'s turn.\n\n", currentPlayer == 1 ? '#' : 'O');
            
            if (currentPlayer == 1) {
                int ai_move = ai_player(currentPlayer, board);
                int start = ai_move / 100;
                int end = ai_move % 100;
                int startY = start / 10;
                int startX = start % 10;
                int endY = end / 10;
                int endX = end % 10;
                printf("%d\n", ai_move);
                makeMove(board, startX, startY, endX, endY);
            }

            else if (currentPlayer == 2) {
                int human_move = readMove();
                int visited[9][9] = {0};
                int start = human_move / 100;
                int end = human_move % 100;
                int startY = start / 10;
                int startX = start % 10;
                int endY = end / 10;
                int endX = end % 10;
                
                if (human_move > 9999 || human_move < 1000) {
                    printf("Invalid input format, please input again: \n");
                    continue;
                }
                
                if (!isWithinBoard(startY, startX) || !isWithinBoard(endY, endX)) {
                    printf("Input out of the game board, please input again: \n");
                    continue;
                }
                
                if (board[start] != currentPlayer) {
                    printf("Invalid starting location, please input again: \n");
                    continue;
                }
                
                if (board[end] != 0) {
                    printf("Invalid ending location, please input again: \n");
                    continue;
                }
                
                if (isValidMove(board, human_move, currentPlayer, visited)) {
                    makeMove(board, startX, startY, endX, endY);
                }
                else {
                    printf("The move violates the game rule, please input again.\n");
                    continue;
                }
            }
            
            currentPlayer = 3 - currentPlayer; // 切换玩家
            moveCount++;
            if (checkGameOver(board, moveCount)) {
                if (checkGameOver(board, moveCount) == 1) {
                    printBoard(board);
                    printf("Blue(#) wins!\n");
                }
                else if (checkGameOver(board, moveCount) == 2) {
                    printBoard(board);
                    printf("Red(O) wins!\n");
                }
                else {
                    printBoard(board);
                    printf("Draw!\n");
                }
                break;
            }
        }
    return 0;
    }
}
