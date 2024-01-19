**Longest Increasing Subsequences**

Problem Statement 140) Longest Increasing Subsequence) Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

-----------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;  // Base case: empty array
        }

        // dp vector to store the length of LIS ending at each index
        vector<int> dp(n, 1);  // Initialize with 1 as each element is a subsequence of length 1

        // Iterate through the array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // Update dp[i] if a longer LIS ending at i is found
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // Find the maximum length LIS in the dp vector
        int maxLength = 1;
        for (int len : dp) {
            maxLength = max(maxLength, len);
        }

        return maxLength;
    }
};

------------------------------------Explanation :- 
Problem:

Given a vector of integers nums, determine the length of the longest subsequence within it where the elements are strictly increasing.
Key Idea:

Utilize dynamic programming to efficiently calculate the length of the LIS ending at each index, building upon the solutions for previous indices.
Code Breakdown:

Base Case:

If the array is empty (n == 0), return 0 (no subsequence exists).
Initialization:

Create a dp vector of size n, initialized with 1s, as each element can form an LIS of length 1 by itself.
Dynamic Programming:

Iterate through the array from index 1 to n - 1:
Iterate through the previous indices from 0 to i - 1:
If nums[i] is greater than nums[j] (potential extension of an LIS):
Update dp[i] with the maximum of its current value and dp[j] + 1 (length of LIS ending at j plus 1).
Find Maximum Length:

Iterate through the dp vector to find the maximum length, representing the length of the LIS.
Return Result:

Return the maximum length of the LIS found.
Time and Space Complexity:

Time: O(n^2), where n is the length of the array, due to the nested loops.
Space: O(n) for the dp vector.
