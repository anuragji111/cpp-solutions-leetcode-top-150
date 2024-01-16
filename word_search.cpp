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
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }

        visited[i][j] = true;
        bool found = backtrack(board, word, i + 1, j, index + 1, visited) ||
                      backtrack(board, word, i - 1, j, index + 1, visited) ||
                      backtrack(board, word, i, j + 1, index + 1, visited) ||
                      backtrack(board, word, i, j - 1, index + 1, visited);

        visited[i][j] = false; // Backtrack
        return found;
    }
};

--------------------------------------Explanations:-
 Key Features:

Backtracking: Explores possible word paths recursively, backtracking when necessary.
Visited Array: Prevents revisiting cells and forming circular paths.
Code Breakdown:

1. exist Function (Main Function):

Initializes a visited array to track visited cells.
Iterates through each cell in the board:
If backtrack returns true for a cell, the word exists; return true.
If no valid path is found, return false.
2. backtrack Function (Recursive Helper):

Base Cases:
If the index reaches the end of the word, a valid path has been found; return true.
If the current cell is out of bounds, already visited, or doesn't match the current word character, return false.
Recursive Steps:
Mark the current cell as visited.
Recursively call backtrack for each adjacent cell:
Up (i - 1, j)
Down (i + 1, j)
Left (i, j - 1)
Right (i, j + 1)
Backtrack (unmark the current cell as visited).
Return true if any of the recursive calls found a valid path, false otherwise.
Time and Space Complexity:

Time: Worst-case O(M * N * 4^L), where M is board rows, N is board columns, and L is word length.
Space: O(M * N) for visited array and O(L) for recursion stack depth.
