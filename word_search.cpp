**Word Search**

Problem Statement) Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

-----------------------------------------------------------------------------------------------
SOLUTION = 
bool starts_with(int r, int c, char **board, int boardSize,
                 int* boardColSize, char * word)
{
    if (strlen(word) == 0)
        return true;
    
    if (r < 0 || r >= boardSize)
        return false;
    
    if (c < 0 || c >= boardColSize[0])
        return false;
    
    if (board[r][c] != word[0])
        return false;
    
    bool res;
    char old = word[0];

    board[r][c] = '_';
    if (starts_with(r - 1, c, board, boardSize, boardColSize, &word[1]))
        return true;
    if (starts_with(r + 1, c, board, boardSize, boardColSize, &word[1]))
        return true;
    if (starts_with(r, c - 1, board, boardSize, boardColSize, &word[1]))
        return true;
    if (starts_with(r, c + 1, board, boardSize, boardColSize, &word[1]))
        return true;
    board[r][c] = old;
    
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    int r, c;
    
    for (r = 0; r < boardSize; r++) {
        for (c = 0; c < boardColSize[0]; c++) {
            if (starts_with(r, c, board, boardSize, boardColSize, word))
                return true;
        }
    }
    
    return false;
}

--------------------------Explanations :- 
Key Features:

Backtracking: Explores possible word paths recursively, backtracking when necessary.
Temporary Marking: Overwrites characters on the board to prevent revisiting cells and forming circular paths.
Code Breakdown:

1. starts_with Function (Recursive Helper):

Base Cases:
If word is empty, a valid path has been found; return true.
If (r, c) is out of bounds or doesn't match word[0], return false.
Recursive Steps:
Temporarily overwrite the current character on the board.
Recursively call starts_with for each adjacent cell:
Up (r - 1, c)
Down (r + 1, c)
Left (r, c - 1)
Right (r, c + 1)
Backtrack (restore the original character on the board).
If all recursive calls fail, return false.
2. exist Function (Main Function):

Iterates through each cell in the board:
If starts_with returns true for a cell, the word exists; return true.
If no valid path is found, return false.
Time and Space Complexity:

Time: Worst-case O(M * N * 4^L), where M is board rows, N is board columns, and L is word length.
Space: O(L) for recursion stack depth (due to the depth of the backtracking search).word
