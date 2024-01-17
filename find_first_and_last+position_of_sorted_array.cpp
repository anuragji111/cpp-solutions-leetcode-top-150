**Find First and Last Position of Sorted Array**

Problem Statement 117) Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        // Find the leftmost occurrence of target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                right = mid - 1; // Continue searching to the left
            }
        }

        int first = left;

        // Find the rightmost occurrence of target
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1; // Continue searching to the right
            }
        }

        int last = right;

        // Return the result
        if (first <= last) {
            return {first, last};
        } else {
            return {-1, -1};
        }
    }
};

--------------------------------------------Explanation:- 
Problem:

Given a sorted array of integers and a target value, find the first and last indices of occurrences of the target value in the array.
Key Features:

Dual Binary Search: Employs two binary searches, one to find the leftmost occurrence and another to find the rightmost occurrence.
Boundary Handling: Uses specific conditions within the binary searches to locate the exact boundaries of the target value's occurrences.
Code Breakdown:

1. searchRange Function:

Finding Leftmost Occurrence:

Initializes left and right pointers to the beginning and end of the array.
Iterates using a loop until left is no longer less than or equal to right:
Calculates the middle index (mid) using the average of left and right.
If nums[mid] is less than the target value, updates left to mid + 1 to search in the right half.
If nums[mid] is greater than the target value, updates right to mid - 1 to search in the left half.
If nums[mid] equals the target value, updates right to mid - 1 to continue searching to the left for a potential earlier occurrence.
Stores the potential leftmost index in first.
Finding Rightmost Occurrence:

Resets left and right pointers to the beginning and end of the array.
Iterates using a loop until left is no longer less than or equal to right:
Calculates the middle index (mid) using the average of left and right.
If nums[mid] is less than the target value, updates left to mid + 1 to search in the right half.
If nums[mid] is greater than the target value, updates right to mid - 1 to search in the left half.
If nums[mid] equals the target value, updates left to mid + 1 to continue searching to the right for a potential later occurrence.
Stores the potential rightmost index in last.
Returning the Result:

If first is less than or equal to last (meaning occurrences were found), returns a vector containing first and last.
Otherwise, returns a vector containing -1 and -1 to indicate the target value was not found.
Time and Space Complexity:

Time: O(log N) on average, where N is the number of elements in the array, due to the two binary searches.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
