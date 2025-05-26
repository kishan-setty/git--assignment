#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char currentPlayer;

void initializeBoard();
void printBoard();
int makeMove(int row, int col);
int checkWinner();
int isBoardFull();
void switchPlayer();
void playGame();
void printInstructions();

int main() {
    char playAgain;
    do {
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');
    printf("Thanks for playing!\n");
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void printBoard() {
    printf("\n");
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  ---|---|---\n");
    }
    printf("\n");
}

void printInstructions() {
    printf("=== TIC TAC TOE ===\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("Enter row and column numbers (0-2) to place your mark.\n");
}

int makeMove(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid position! Try again.\n");
        return 0;
    }
    if (board[row][col] != ' ') {
        printf("Cell already taken! Try again.\n");
        return 0;
    }
    board[row][col] = currentPlayer;
    return 1;
}

int checkWinner() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return 1;
        }
    }
    // Diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return 1;
    }
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    int moveValid;
    initializeBoard();
    printInstructions();
    printBoard();

    while (1) {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        moveValid = makeMove(row, col);
        if (!moveValid) continue;

        printBoard();

        if (checkWinner()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }
}

