**Maximal Square**

Problem Statement 150) Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

---------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;

        // Base cases: Handle the first row and column separately
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]);
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxSide = max(maxSide, dp[0][j]);
        }

        // Fill the DP table, building upon previous squares
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide * maxSide; // Area of the largest square
    }
};

-------------------------------------Explanation :-
  Problem:

Given a binary matrix matrix containing '0's and '1's, determine the area of the largest square submatrix that consists entirely of '1's.
Key Idea:

Utilize dynamic programming to efficiently calculate the maximum side lengths of possible squares at each position in the matrix, building upon solutions for smaller subproblems.
Code Breakdown:

Initialization:

Get the dimensions of the matrix (m and n).
Create a dp vector of vectors (size m by n) to store the maximum side lengths of squares ending at each position.
Initialize maxSide to 0 to track the largest square found.
Base Cases:

Handle the first row and column separately:
dp[i][0] = 1 if matrix[i][0] is '1', otherwise 0.
dp[0][j] = 1 if matrix[0][j] is '1', otherwise 0.
Fill DP Table:

Iterate through the rest of the matrix (i from 1 to m-1, j from 1 to n-1):
If the current element is '1':
Calculate dp[i][j] based on the minimum of the three adjacent squares:
dp[i - 1][j] (top square)
dp[i][j - 1] (left square)
dp[i - 1][j - 1] (diagonal square)
This ensures the square can be extended from all sides.
Update maxSide if a larger square is found.
Return Result:

Return maxSide * maxSide, which represents the area of the largest square submatrix.
Time and Space Complexity:

Time: O(m * n), due to filling the DP table.
Space: O(m * n) for the dp table.
