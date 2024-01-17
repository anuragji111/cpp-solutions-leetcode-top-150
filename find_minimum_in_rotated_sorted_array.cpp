**Find Minimum in Rotated Sorted Array**

Problem Statement 118) Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the middle element is greater than the rightmost element,
            // the minimum must lie in the left half (including the middle).
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Otherwise, the minimum must lie in the right half (excluding the middle).
                right = mid;
            }
        }

        // The loop terminates when left == right, pointing to the minimum element.
        return nums[left];
    }
};

------------------------------------------Explanation:-
Problem:

Given a sorted array that has been rotated at some unknown pivot point, find the minimum element in the array.
Key Features:

Adapted Binary Search: Leverages the sorted nature of the array, even with the rotation, to efficiently find the minimum element.
Rotation Handling: Identifies the rotated portion of the array and focuses the search on the relevant half.
Code Breakdown:

1. findMin Function:

Initializes left and right pointers to the beginning and end of the array, respectively.
Iterates using a loop until left is less than right:
Calculates the middle index (mid) using the average of left and right.
If nums[mid] is greater than nums[right], the minimum element must lie in the left half (including the middle), so updates left to mid + 1.
Otherwise, the minimum element must lie in the right half (excluding the middle, as it's already smaller than or equal to nums[right]), so updates right to mid.
The loop terminates when left and right converge, pointing to the minimum element.
Returns nums[left], which holds the minimum value.
Time and Space Complexity:

Time: O(log N), where N is the number of elements in the array, due to the adapted binary search approach.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
