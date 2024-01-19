**Triangle**

Problem Statement 141) Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Iterate from the second-to-last row to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Update each element with the minimum path sum from its children
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The minimum path sum is at the top of the triangle
        return triangle[0][0];
    }
};

-----------------------Explanation :-
Problem:

Given a triangular array triangle of integers representing the costs of paths between nodes, calculate the minimum total cost to reach the bottom row starting from the top.
Key Idea:

Employ dynamic programming to efficiently compute the minimum path sums for each node, working from the bottom up and building upon the solutions for the lower rows.
Code Breakdown:

Initialization:

Get the number of rows in the triangle (n).
Dynamic Programming:

Iterate from the second-to-last row (n - 2) to the top (0):
Iterate through the elements in each row (j from 0 to i):
Update each element triangle[i][j] with the sum of itself and the minimum path sum from its two children in the row below: min(triangle[i + 1][j], triangle[i + 1][j + 1]).
Return Result:

The minimum path sum to the bottom is stored in the top element triangle[0][0], so return it.
Time and Space Complexity:

Time: O(n^2), where n is the number of rows, due to the nested loops.
Space: O(1) in-place modification of the input triangle.
