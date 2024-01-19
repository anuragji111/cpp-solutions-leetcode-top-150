**House Robber**

Problem Statement 137) You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

---------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;  // Base case: no houses to rob
        }

        // dp vector to store maximum loot at each house
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];  // Initialize for the first house

        for (int i = 2; i <= n; i++) {
            // Choose the maximum of robbing the current house or skipping it
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }

        return dp[n];
    }
};

-----------------------------------------------Explanation:-
Problem:

Given a vector of non-negative integers nums representing the amount of money in each house, determine the maximum amount of money that can be robbed, given that you cannot rob adjacent houses.
Key Idea:

Utilize dynamic programming to efficiently calculate the maximum loot for each house, building upon the solutions for smaller subproblems.
Code Breakdown:

Base Case:

If there are no houses (n == 0), return 0 (no loot to be had).
Initialization:

Create a dp vector of size n + 1 filled with 0s to store the maximum loot at each house.
Set dp[1] to nums[0], as the maximum loot for one house is simply the money in that house.
Dynamic Programming:

Iterate from house 2 to house n:
Calculate dp[i] as the maximum of:
Robbing the current house (dp[i - 2] + nums[i - 1]): Add the money from the current house to the maximum loot from two houses before.
Skipping the current house (dp[i - 1]): Take the maximum loot from the previous house.
Return Result:

Return dp[n], which stores the maximum loot that can be robbed from all the houses.
Time and Space Complexity:

Time: O(n), where n is the number of houses, due to the linear traversal.
Space: O(n) for the dp vector used to store intermediate results.
