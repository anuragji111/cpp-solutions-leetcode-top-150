**Maximum Sum Circular Subarray**

Problem Statement 112) Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

--------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0], currentMax = nums[0];
        int minSum = nums[0], currentMin = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < n; i++) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);

            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);

            totalSum += nums[i];
        }

        // If all elements are negative, the max subarray sum is the minimum element
        if (maxSum < 0) return maxSum;

        // Otherwise, consider the possible wrap-around subarray
        return max(maxSum, totalSum - minSum);
    }
};

-----------------------------Explanation:- 
Problem:

Given a circular array of integers (imagine the first and last elements connected), find the contiguous subarray (a sequence of elements) with the largest sum, considering both regular and wrap-around subarrays.
Key Features:

Handles Wrap-Around Cases: Uses Kadane's algorithm for maximum subarray, but also considers subarrays that wrap around the array.
Tracks Minimum Subarray Sum: Calculates the minimum subarray sum to aid in finding the maximum wrap-around subarray sum.
Code Breakdown:

1. maxSubarraySumCircular Function:

Initializes variables for maximum and minimum subarray sums, current subarray sums, and total array sum.
Iterates through the array:
Updates maximum and minimum subarray sums using Kadane's algorithm.
Updates the total array sum.
If all elements are negative, returns the maximum element (which is the maximum subarray sum).
Otherwise, considers the potential wrap-around subarray:
Calculates the sum of the remaining elements (total array sum minus the minimum subarray sum).
Returns the larger of the regular maximum subarray sum and the wrap-around subarray sum.
Time and Space Complexity:

Time: O(N), where N is the number of elements in the array, as it iterates through the array once.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
