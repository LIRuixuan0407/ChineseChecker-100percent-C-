#include "checkGameOver.h"

// 检查游戏是否结束
// board: 当前棋盘状态
// player: 当前轮到的玩家，1表示蓝方，2表示红方
// 返回值：0 表示游戏继续，1 表示蓝方获胜，2 表示红方获胜，3 表示平局
int checkGameOver(const int board[], int moveCount) {
    bool blueWon = false;
    bool redWon = false;

    // 检查红方是否获胜
    if (board[11] == 2 && board[12] == 2 && board[13] == 2 && board[21] == 2 && board[22] == 2 && board[31] == 2) {
            redWon = true;
        }

    // 检查蓝方是否获胜
    if (board[68] == 1 && board[77] == 1 && board[78] == 1 && board[86] == 1 && board[87] == 1 && board[88] == 1) {
        blueWon = true;
    }

    // 检查是否有玩家获胜
    if (blueWon) {
        return 1; // 蓝方获胜
    }
    else if (redWon) {
        return 2; // 红方获胜
    }

    // 检查是否平局，每方最多走100步
    if (moveCount >= 200) {
        return 3; // 平局
    }

    // 如果没有玩家获胜且步数未达到上限，游戏继续
    return 0;
}

