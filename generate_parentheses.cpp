**Generate Parentheses**

Problem Statement 106) Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};

------------------Key Features:

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
