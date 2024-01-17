**Search in Rotated Sorted Array**

Problem Statement 116) There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            }

            // Determine which half is sorted and whether target lies in that half
            if (nums[mid] >= nums[left]) { // Left half is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Search in the left half
                } else {
                    left = mid + 1; // Search in the right half
                }
            } else { // Right half is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Search in the right half
                } else {
                    right = mid - 1; // Search in the left half
                }
            }
        }

        return -1; // Target not found
    }
};

---------------------------------------Explanations:-
Problem:

Given a sorted array that has been rotated at some unknown pivot point, find the index of a target value if it exists in the array.
Key Features:

Adapted Binary Search: Addresses the rotation by determining which half of the array is sorted and adjusting the search accordingly.
Pivot Point Handling: Determines the pivot point implicitly within the search process.
Code Breakdown:

1. search Function:

Initializes left and right pointers to the beginning and end of the array, respectively.
Iterates using a loop until left is no longer less than or equal to right:
Calculates the middle index (mid) using the average of left and right.
If nums[mid] matches the target value, returns mid (target found).
Determines which half (left or right) is sorted by comparing nums[mid] with nums[left].
If the left half is sorted:
If the target value lies within the sorted range of the left half, updates right to mid - 1 to search in the left half.
Otherwise, updates left to mid + 1 to search in the right half.
If the right half is sorted (similar logic, but with comparisons for the right half's range):
If the target value lies within the sorted range of the right half, updates left to mid + 1 to search in the right half.
Otherwise, updates right to mid - 1 to search in the left half.
If the loop completes without finding the target, returns -1.
Time and Space Complexity:

Time: O(log N), where N is the number of elements in the array, due to the adapted binary search approach.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
