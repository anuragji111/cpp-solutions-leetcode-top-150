**Search a 2D Matrix**

Problem Statement 114) You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104


--------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / cols, col = mid % cols;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

-------------------Explanation:-
  Problem:

Given a 2D matrix where each row and column is sorted in ascending order, and a target value, determine if the target value exists in the matrix.
Key Features:

Treats Matrix as a 1D Array: Conceptually converts the 2D matrix into a 1D array for efficient binary search.
Calculates Rows and Columns: Determines the row and column indices from the flattened 1D index during binary search.
Code Breakdown:

1. searchMatrix Function:

Gets the number of rows and columns in the matrix.
Initializes left and right pointers to 0 and the last index of the flattened array, respectively.
Iterates using a loop until left is no longer less than or equal to right:
Calculates the middle index (mid) using the average of left and right.
Maps mid to its corresponding row and column indices in the 2D matrix.
If matrix[row][col] matches the target value, returns true (target found).
If matrix[row][col] is less than the target value, updates left to mid + 1 to search the right half.
Otherwise, updates right to mid - 1 to search the left half.
If the loop completes without finding the target, returns false.
Time and Space Complexity:

Time: O(log N), where N is the total number of elements in the matrix, due to the binary search approach.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
