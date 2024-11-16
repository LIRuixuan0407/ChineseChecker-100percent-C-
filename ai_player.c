#include "ai_player.h"
#include <math.h>

int ai_player(int player , const int * board) {
    int maxMove[6] = {0};
    int chess = 0;
    int move[6] = {0};
    int distance = 0;
        
    for (int startY = 1; startY < 9; startY++) {
        for (int startX = 1; startX < 9; startX++) {
            if (board[10 * startY + startX] == player) {
                for (int endY = 1; endY < 9; endY++) {
                    for (int endX = 1; endX < 9; endX++) {
                        int visited[9][9] = {0};
                        if (isValidMove(board, 1000 * startY + 100 * startX + 10 * endY + endX, player, visited)) {
                            
                            if (endX >= startX && endY >= startY) {
                                distance = pow((endY - startY), 2) + pow((endX - startX), 2);
                                if (distance > maxMove[chess]) {
                                    maxMove[chess] = distance;
                                    move[chess] = 1000 * startY + 100 * startX + 10 * endY + endX;
                                }
                            }
                            
                            if (distance == 0 && (endX + endY >= 14) && (endX + endY == startX + startY)) {
                                distance = pow((endY - startY), 2) + pow((endX - startX), 2);
                                if (distance > maxMove[chess]) {
                                    maxMove[chess] = distance;
                                    move[chess] = 1000 * startY + 100 * startX + 10 * endY + endX;
                                }
                            }
                            
                        }
                    }
                }
                chess++;
            }
        }
    }
    
    int bestMove = 0;
        for (int i = 1; i < 6; i++) {
            if (maxMove[i] > maxMove[bestMove]) {
                bestMove = i;
            }
        }
        
        return move[bestMove];
    }
