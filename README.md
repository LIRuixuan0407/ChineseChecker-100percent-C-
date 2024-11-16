1. Introduction
Chinese checker is a turn-based board game played by two, three, four or even six people. The rules are simple. Each player takes turns to move one of their chess pieces, aiming to be the first to move all their chess pieces across the game board from one’s initial camp to the opposite side of the star corner—using single-step moves or multi-jump moves over some other pieces.

This project is a simplified version of the game. We consider only two players seated at the opposing corners of an 8x8 square board; see Figure 2 below. Each player has six chess pieces of his/her own. In general, the game is won by being the first to transfer all of one's pieces from his/her camp into the opponent’s camp. In each turn, a player can move one of his/her chess pieces by either (i) moving one single step to an adjacent empty cell or (ii) jumping through empty cells on the game board over some other pieces successively.

****************************************************************************************************************************************************************
2. Game Rule
2.1
• There are two players in this game.
• Each player has six pieces, e.g., blue or red.
• Each player's camp consists of six cells on top-left and bottom-right corners of the game board; see Figure 2.
• The game starts with each player's camp filled by pieces of his/her own color.

We store the game board using a one-dimensional integer array of length 89. The location of each cell in the board is represented using an integer in [11, 88].

For example, location “47” means the fourth row and the seventh column.
• The upper-left corner of the board is 11.
• The cell on its right is 12.
• The cell just under 11 is 21. See the cell coordinates below.

2.2
The game always starts with the blue player, whose camp is located at the upper-left corner.

• Pieces may move only in eight possible directions (orthogonally and diagonally).
• In each turn, a player can have the following possible moves:
1. a single-step move to an adjacent empty cell. For example horizontal and diagonal moves, respectively;
2. a single-jump move to an empty cell with one jump over some other pieces (can be the player’s own piece or opponent’s piece). For example vertical and diagonal jumps, respectively;
3. also, we can have a long distance jump to an empty cell with exactly one single piece in the middle between the lifting and landing locations in that jump; and
4. a multi-jump move with more than one jumps successively through some empty cells, while having only one single piece in the middle between the landing and lifting cells for each jump.

2.3
There are only two possible “end game” conditions, i.e., one of the two players wins; or
the game is a draw. The detailed conditions are specified as follows:
(1) WIN: After making a move, a player wins the game, if he/she fills up all the cells in opponent’s camp with at least one of his/her piece(s) in these cells;
(2) DRAW: after each player has moved 100 steps, if there is no winner; and
(3) LOSE.

2.4
• ‘#’ to represent blue,
• ‘O’ to represent red, and
• ‘.’ to represent an empty cell.

2.5
Enter 1 --> "human v.s. human" mode
Enter 2 --> "human v.s. computer" mode
