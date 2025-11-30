# C-project-SEC-I-250301370144-
TIC TAC TOE
<img width="1408" height="967" alt="Screenshot From 2025-11-30 22-34-00" src="https://github.com/user-attachments/assets/7b69a5a7-abb2-4128-ac3b-76671ac39799" />
<img width="1408" height="967" alt="Screenshot From 2025-11-30 22-34-11" src="https://github.com/user-attachments/assets/b0f61990-8975-4236-8aba-704b24745180" />
<img width="1408" height="967" alt="Screenshot From 2025-11-30 22-34-20" src="https://github.com/user-attachments/assets/b81ac14c-2f68-4cb5-ab84-7187e768c03a" />

## Algorithm: Two-Player Tic-Tac-Toe Game

### Main Algorithm
1. **START**
2. Declare 3×3 character array `board` for game grid
3. Declare variables: `row`, `col` (integers), `player` = 'X'
4. Display game title and instructions
5. Call `initBoard()` to initialize all cells to empty spaces
6. **REPEAT** (Game Loop):
   - Call `displayBoard()` to show current board state
   - Display current player's turn
   - Input `row` and `col` from user
   - **IF** `row` or `col` is out of range (0-2) **OR** cell is already occupied **THEN**:
     - Display "Invalid move"
     - Continue to next iteration (don't change turn)
   - **ELSE**:
     - Set `board[row][col]` = `player`
     - Call `checkWin()`
     - **IF** winner found **THEN**:
       - Display board
       - Display "Player [X/O] WINS!"
       - **BREAK** loop
     - Call `checkDraw()`
     - **IF** draw detected **THEN**:
       - Display board
       - Display "It's a DRAW!"
       - **BREAK** loop
     - Switch player (X → O or O → X)
7. **END**

### Sub-Algorithm 1: initBoard()
1. **FOR** `i` = 0 to 2:
   - **FOR** `j` = 0 to 2:
     - Set `board[i][j]` = ' ' (empty space)
2. **RETURN**

### Sub-Algorithm 2: displayBoard()
1. **FOR** `i` = 0 to 2:
   - Print `board[i][0]`, `board[i][1]`, `board[i][2]` with separators
   - **IF** `i` < 2 **THEN** print horizontal divider line
2. **RETURN**

### Sub-Algorithm 3: checkWin()
1. **FOR** `i` = 0 to 2:
   - **IF** all three cells in row `i` are equal **AND** not empty **THEN** **RETURN** 1
   - **IF** all three cells in column `i` are equal **AND** not empty **THEN** **RETURN** 1
2. **IF** main diagonal cells (0,0), (1,1), (2,2) are equal **AND** not empty **THEN** **RETURN** 1
3. **IF** anti-diagonal cells (0,2), (1,1), (2,0) are equal **AND** not empty **THEN** **RETURN** 1
4. **RETURN** 0 (no winner)

### Sub-Algorithm 4: checkDraw()
1. **FOR** `i` = 0 to 2:
   - **FOR** `j` = 0 to 2:
     - **IF** `board[i][j]` = ' ' (empty) **THEN** **RETURN** 0 (game continues)
2. **RETURN** 1 (board is full, it's a draw)

This algorithm follows a simple turn-based structure where players alternate moves until someone wins or the board fills up.

