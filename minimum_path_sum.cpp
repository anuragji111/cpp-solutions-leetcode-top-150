**Minimum Path Sum**

Problem Statement 142) Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

----------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // dp vector to store the minimum path sums for each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the first row and column
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Build the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];  // Minimum path sum is at the bottom-right corner
    }
};

----------------------------Explanation :-
Problem:

Given a grid of integers representing the costs of paths between adjacent cells, determine the minimum total cost to travel from the top-left cell to the bottom-right cell, only moving down or right.
Key Idea:

Utilize dynamic programming to efficiently calculate the minimum path sums for each cell, building upon the solutions for cells above and to the left.
Code Breakdown:

Initialization:

Get the dimensions of the grid (m rows, n columns).
Create a dp vector of vectors (same size as grid) to store the minimum path sums for each cell.
Initialize First Row and Column:

Set dp[0][0] to grid[0][0] (base case).
Iterate through the first row and column, setting each element to the sum of its corresponding grid value and the minimum path sum from its direct predecessor.
Build DP Table:

Iterate through the remaining cells of the grid:
Set each dp[i][j] to the minimum of its top and left neighbors (dp[i - 1][j] and dp[i][j - 1]) plus the value in grid[i][j].
Return Result:

The minimum path sum to the bottom-right corner is stored in dp[m - 1][n - 1], so return it.
Time and Space Complexity:

Time: O(m * n), where m and n are the grid dimensions, due to iterating through all cells.
Space: O(m * n) for the dp table.
