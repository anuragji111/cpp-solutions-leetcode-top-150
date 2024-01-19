**Unique Paths II**

Problem Statement 143) You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

--------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // dp vector to store the number of unique paths to each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Handle the first row and column, considering obstacles
        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;  // Initial cell has one path if it's not an obstacle
        }
        for (int i = 1; i < m; i++) {
            // If the current cell is not an obstacle and the cell above is reachable,
            // propagate the path count downwards
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
        }
        for (int j = 1; j < n; j++) {
            // Similarly, propagate the path count to the right if possible
            dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
        }

        // Build the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    // If the current cell is not an obstacle, combine paths from above and left
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];  // Number of unique paths to the bottom-right corner
    }
};

---------------------------------Explanation :- 
Problem:

Given a grid of integers obstacleGrid where 0 represents a navigable cell and 1 represents an obstacle, determine the number of unique paths from the top-left cell to the bottom-right cell, only moving down or right, while avoiding obstacles.
Key Idea:

Utilize dynamic programming to efficiently calculate the number of unique paths to each cell, building upon the solutions for previous cells and considering obstacles.
Code Breakdown:

Initialization:

Get the dimensions of the grid (m rows, n columns).
Create a dp vector of vectors (same size as obstacleGrid) to store the number of unique paths to each cell.
Handle First Row and Column:

If the initial cell is not an obstacle, set dp[0][0] to 1 (one path).
For the rest of the first row and column, set dp[i][0] or dp[0][j] to 1 only if the current cell is not an obstacle and the cell directly above or to the left is reachable (has a path count of 1).
Build DP Table:

Iterate through the remaining cells of the grid:
If the current cell is not an obstacle, set dp[i][j] to the sum of the path counts from its top and left neighbors (dp[i - 1][j] and dp[i][j - 1]). This combines possible paths reaching the current cell.
Return Result:

The number of unique paths to the bottom-right corner is stored in dp[m - 1][n - 1], so return it.
Time and Space Complexity:

Time: O(m * n), where m and n are the grid dimensions, due to iterating through all cells.
Space: O(m * n) for the dp table.
