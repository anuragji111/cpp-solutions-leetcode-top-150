**Number of Islands**

Problem Statement 89) Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);  // Sink the island
                }
            }
        }

        return numIslands;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;  // Out of bounds or water
        }

        grid[i][j] = '0';  // Mark as visited (sink)

        dfs(grid, i + 1, j);  // Explore neighbors
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

-------------------------Key Points:

Island Representation: 1s represent land, 0s represent water.
Sinking Islands: It modifies the grid to mark visited land as water (0s), preventing redundant exploration.
Explanation:

numIslands Function:

Initializes variables for grid dimensions and island count.
Iterates through the grid:
If a land cell ('1') is found:
Increment numIslands.
Call dfs to sink the island, exploring its connected land.
Returns the final count of islands.
dfs Function (Recursive):

Base Cases:
If out of bounds or the current cell is water ('0'), return.
Sink the current cell by setting it to '0' (mark as visited).
Recursively call dfs for the four neighboring cells (up, down, left, right) to explore the island.
Time Complexity:

O(rows * cols), where rows and cols are the grid dimensions. In the worst case, it might explore every cell.
Space Complexity:

O(rows * cols) in the worst case due to the recursive calls on the stack if the grid is entirely filled with land. In practice, it's usually much less as islands are typically smaller than the grid size.
