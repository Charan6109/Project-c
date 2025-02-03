#include <stdio.h>

// Function to initialize the board with spaces
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if there's a winner
int checkWinner(char board[3][3]) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Winner found
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Winner found
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Winner found
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Winner found

    return 0; // No winner yet
}

// Function to check if the board is full (for a draw)
int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') // If there's an empty spot
                return 0;
    return 1; // The board is full
}

int main() {
    char board[3][3];
    int row, col, currentPlayer = 1; // Player 1 starts
    char playerSymbol;
    
    initializeBoard(board);

    // Main game loop
    while (1) {
        printBoard(board);
        playerSymbol = (currentPlayer == 1) ? 'X' : 'O'; // Player 1 is X, Player 2 is O
        printf("Player %d's turn (Symbol: %c)\n", currentPlayer, playerSymbol);
        printf("Enter row (0-2) and column (0-2) for your move: ");
        scanf("%d %d", &row, &col);

        // Check if the position is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = playerSymbol; // Make the move
        } else {
            printf("Invalid move. Try again.\n");
            continue; // Skip the rest of the loop and ask for another move
        }

        // Check for a winner
        if (checkWinner(board)) {
            printBoard(board);
            printf("Player %d (Symbol: %c) wins!\n", currentPlayer, playerSymbol);
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            printBoard(board);
            printf("The game is a draw!\n");
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
