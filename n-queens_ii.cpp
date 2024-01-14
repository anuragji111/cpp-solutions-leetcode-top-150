**N-Queens II**

Problem Statement 105) The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9

-------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens(n, -1); // Track queen positions in each row
        return backtrack(queens, 0, n);
    }

private:
    int backtrack(vector<int>& queens, int row, int n) {
        if (row == n) return 1; // Base case: all queens placed

        int count = 0;
        for (int col = 0; col < n; col++) {
            if (isValid(queens, row, col)) {
                queens[row] = col;
                count += backtrack(queens, row + 1, n);
                queens[row] = -1; // Backtrack
            }
        }
        return count;
    }

    bool isValid(vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            // Check for conflicts in the same column or diagonals
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
};

--------------------------Key Features:

Backtracking: Explores possible placements by recursively placing queens and backtracking when conflicts arise.
isValid Function: Checks if a queen placement at a given row and column is valid (no conflicts with other queens).
Code Breakdown:

totalNQueens Function:

Initializes a vector queens to track queen positions (-1 indicates no queen).
Calls backtrack to initiate the backtracking process.
backtrack Function:

Base Case: If row reaches N, all queens are placed successfully; return 1 (count one valid placement).
Iterate through possible columns for the current row:
If isValid returns true, place a queen at (row, col).
Recursively call backtrack for the next row.
Backtrack (remove the queen from the current row).
Return the total count of valid placements found.
isValid Function:

Iterates through previously placed queens (rows 0 to row-1):
Checks for conflicts:
Same column (queens[i] == col)
Diagonal conflict: abs(queens[i] - col) == abs(i - row)
Returns false if a conflict is found.
Returns true if no conflicts are found.
Time and Space Complexity:

Time: O(N^N), due to the backtracking exploration of exponentially many board states.
Space: O(N) for queens vector and recursion stack depth.
