#include "isValidMove.h"

// 检查坐标是否在棋盘内
bool isWithinBoard(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

// 检查是否为单步移动
int isSingleStep(const int board[], int startX, int startY, int endX, int endY) {
    if (startX == endX && (startY == endY + 1 || startY == endY - 1)) {
        return 1;
    }
    if (startY == endY && (startX == endX + 1 || startX == endX - 1)) {
        return 1;
    }
    if ((startX == endX + 1 || startX == endX - 1) && (startY == endY + 1 || startY == endY - 1)) {
        return 1;
    }
    return 0;
}


// 检查是否为合法的跳棋动作，包括隔空跳子和连续跳跃
int isJump(const int board[], int startX, int startY, int endX, int endY, int visited[9][9]) {
    
    int directions[8][2] = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    
    for (int i = 0; i < 8; i++) {
        int x = startX + directions[i][0];
        int y = startY + directions[i][1];
        int steps = 1;
        while (isWithinBoard(x, y) && board[10 * y + x] == 0) {
            x += directions[i][0];
            y += directions[i][1];
            steps++;
        }
        if (isWithinBoard(x, y) && board[10 * y + x] != 0) {
            int newX = x + directions[i][0] * steps;
            int newY = y + directions[i][1] * steps;
            if (isWithinBoard(newX, newY) && board[10 * newY + newX] == 0 && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                int flag = 0;
                
                for (int j = 1; j < steps; ++j) {
                    if (board[10 * (y + directions[i][1] * j) + (x + directions[i][0] * j)] != 0) {
                        flag = 1;
                    }
                }
                
                if (newX == endX && newY == endY && flag == 0) {
                    return 1;
                }
                else if ((newX != endX || newY != endY) && flag == 0 && isJump(board, newX, newY, endX, endY, visited)) {
                    return 1;
                }
                
            }
        }
    }
    return 0;
}

// 尝试执行移动并恢复棋盘状态
void makeMove(int board[], int startX, int startY, int endX, int endY) {
    board[10 * endY + endX] = board[10 * startY + startX];
    board[10 * startY + startX] = 0;
}

// 检查移动是否有效
int isValidMove(const int board[], int move, int player, int visited[9][9]) {
    int start = move / 100;
    int end = move % 100;
    int startY = start / 10;
    int startX = start % 10;
    int endY = end / 10;
    int endX = end % 10;
    
    if (move > 9999 || move < 1000) {
        return 0;
    }
    
    if (!isWithinBoard(startY, startX) || !isWithinBoard(endY, endX)) {
        return 0;
    }
    
    if (board[start] != player) {
        return 0;
    }
    
    if (board[end] != 0) {
        return 0;
    }

    if (isSingleStep(board, startX, startY, endX, endY) || isJump(board, startX, startY, endX, endY, visited)) {
        return 1;
    }
    else {
        return 0;
    }
}
