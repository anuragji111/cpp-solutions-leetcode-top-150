**Find Peak Element**

Problem Statement 115) You are given an m x n integer matrix matrix with the following two properties:

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


----------------------------------------------------------------------------------------------------------------
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

----------------------------------Explanations:-
  Problem:

Given an array that is guaranteed to have a peak element (a value greater than its neighbors), find the index of any such peak element.
Key Features:

Binary Search Approach: Efficiently finds a peak element by repeatedly dividing the search space in half.
Property of Peak Elements: Leverages the fact that a peak element is always greater than its neighbors to narrow down the search.
Code Breakdown:

1. findPeakElement Function:

Initializes left and right pointers to the beginning and end of the array, respectively.
Iterates using a loop until left is less than right:
Calculates the middle index (mid) using the average of left and right.
If nums[mid] is greater than nums[mid + 1], potentially a peak exists in the left half, so updates right to mid.
Otherwise, potentially a peak exists in the right half, so updates left to mid + 1.
The loop converges when left and right point to a peak element (or a potential peak in case of duplicates).
Returns left, which holds the index of the peak element.
Time and Space Complexity:

Time: O(log N), where N is the number of elements in the array, due to the binary search approach.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.

