#include "initializeBoard.h"

void initializeBoard(int board[]) {
    // 初始化棋盘，将玩家的棋子放在起始位置
    // 假设蓝方在左上角，红方在右下角
    board[11] = 1; board[12] = 1; board[13] = 1; board[21] = 1; board[22] = 1; board[31] = 1;
    board[68] = 2; board[77] = 2; board[78] = 2; board[86] = 2; board[87] = 2; board[88] = 2;
    // 其他位置初始化为0，表示空
    for (int i = 11; i <= 88; i++) {
        if (i != 11 && i != 12 && i != 13 && i != 21 && i != 22 && i != 31 &&
            i != 68 && i != 77 && i != 78 && i != 86 && i != 87 && i != 88) {
            board[i] = 0;
        }
    }
}
