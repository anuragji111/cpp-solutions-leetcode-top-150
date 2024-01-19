**Coin Change**

Problem Statement 139) You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp vector to store minimum coins needed for each amount
        vector<int> dp(amount + 1, amount + 1);  // Initialize with amount + 1 (impossible value)
        dp[0] = 0;  // Base case: 0 amount needs 0 coins

        // Iterate through amounts
        for (int i = 1; i <= amount; i++) {
            // Iterate through coin denominations
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    // Update dp[i] with the minimum of current value and using the coin
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        // Return the minimum coins, or -1 if impossible
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

---------------------------Explanation :-