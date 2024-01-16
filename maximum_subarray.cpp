**Maximum Subarray**

Problem Statement 111) Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currentSum = 0;

        for (int num : nums) {
            currentSum = max(num, currentSum + num); // Include current element or start a new subarray
            maxSum = max(maxSum, currentSum);      // Update overall maximum
        }

        return maxSum;
    }
};

---------------------------------Explanations:-
  Problem:

Given an array of integers, find the contiguous subarray (a sequence of elements) that has the largest sum.
Key Features:

Dynamic Programming Approach: Uses the optimal substructure property of the problem to build the solution incrementally.
Code Breakdown:

1. maxSubArray Function:

Initializes maxSum to the smallest possible integer (INT_MIN) to ensure it's updated by any positive sum.
Initializes currentSum to 0 to track the sum of the current subarray.
Iterates through each element in the array:
Updates currentSum based on whether including the current element would increase the sum or if starting a new subarray would be better:
currentSum = max(num, currentSum + num)
Updates maxSum if the current subarray sum is greater than the maximum found so far.
Returns the maximum subarray sum (maxSum).
Time and Space Complexity:

Time: O(N), where N is the number of elements in the array, as it iterates through the array once.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
