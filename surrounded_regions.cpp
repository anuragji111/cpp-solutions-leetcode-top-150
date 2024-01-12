**Surrounded Regions**

Problem Statement 90) Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

-----------------------------------------------------------------------
SOLUTION = class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;  // Empty board
        int cols = board[0].size();

        // Handle edges: mark 'O's connected to edges as safe
        for (int i = 0; i < rows; i++) {
            dfs(board, i, 0);  // Left edge
            dfs(board, i, cols - 1);  // Right edge
        }
        for (int j = 0; j < cols; j++) {
            dfs(board, 0, j);  // Top edge
            dfs(board, rows - 1, j);  // Bottom edge
        }

        // Flip remaining 'O's (not connected to edges) to 'X'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {  // Restore safe 'O's
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
            return;  // Out of bounds or not 'O'
        }

        board[i][j] = '#';  // Mark as safe

        dfs(board, i + 1, j);  // Explore neighbors
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};

-----------------------Key Points:

Edge Exploration: Marks 'O's connected to edges as safe using DFS.
Flipping Remaining 'O's: Flips remaining 'O's (not connected to edges) to 'X', indicating captured regions.
Temporary Marker: Uses '#' to temporarily mark safe 'O's during DFS.
Explanation:

solve Function:

Handles empty board case.
Edge Exploration:
Starts DFS from each edge cell to mark connected 'O's as safe using '#'.
Flipping Remaining 'O's:
Iterates through the board:
Flips remaining 'O's (not marked as '#') to 'X'.
Restores safe 'O's (marked as '#') back to 'O'.
dfs Function (Recursive):

Base Cases:
If out of bounds or the current cell is not 'O', return.
Mark the current 'O' cell as safe using '#'.
Recursively call dfs for the four neighboring cells (up, down, left, right) to explore the connected region.
Time Complexity:

O(rows * cols), where rows and cols are the grid dimensions, as it potentially visits every cell.
Space Complexity:

O(rows * cols) in the worst case due to recursive calls on the stack if the entire grid is filled with 'O'. However, in practice, it's usually much less as surrounded regions are typically smaller than the grid size.
