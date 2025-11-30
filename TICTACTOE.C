#include <stdio.h>

// Function to initialize the board
void initBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard(char board[3][3]) {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a winner
int checkWin(char board[3][3]) {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    
    return 0;
}

// Function to check if board is full (draw)
int checkDraw(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    char board[3][3];
    int row, col;
    char player = 'X';
    
    printf("===== TIC TAC TOE GAME =====\n");
    printf("Enter positions as: row(0-2) column(0-2)\n");
    
    initBoard(board);
    
    while(1) {
        displayBoard(board);
        
        // Get player input
        printf("Player %c's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        
        // Validate input
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // Place marker
        board[row][col] = player;
        
        // Check for winner
        if(checkWin(board)) {
            displayBoard(board);
            printf("Player %c WINS!\n", player);
            break;
        }
        
        // Check for draw
        if(checkDraw(board)) {
            displayBoard(board);
            printf("It's a DRAW!\n");
            break;
        }
        
        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
