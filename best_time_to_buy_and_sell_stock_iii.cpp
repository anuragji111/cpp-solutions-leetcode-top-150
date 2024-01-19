**Best Time to Buy and Sell Stock**

Problem Statement 147) You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int dfs(int i,int j,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(i == n) return 0;
        int ans = 0;
        if(k == 2) return 0;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(j == 0){
            ans = max(dfs(i+1,1,k,prices,dp)-prices[i],dfs(i+1,0,k,prices,dp));
        }
        else{
            ans = max(dfs(i+1,0,k+1,prices,dp)+prices[i],dfs(i+1,1,k,prices,dp));
        }
        return dp[i][j][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return dfs(0,0,0,prices,dp);
    }
};

----------------------------------Expalanation:-
Problem:

Given an array of stock prices prices, determine the maximum profit that can be made by buying and selling stocks at most twice, with the constraint that you can only hold one stock at a time.
Key Idea:

Utilize dynamic programming to efficiently explore possible buying and selling decisions, avoiding redundant calculations.
Code Breakdown:

maxProfit Function:

Get the size of the prices array (n).
Create a 3D dp vector of vectors of vectors (size n by 2 by 3) to store maximum profits at different states.
Initialize all elements of dp to -1 (unknown states).
Call the dfs helper function to start the calculation.
dfs Helper Function:

Takes four arguments:
i: Current day index
j: Current state (0 for no stock, 1 for holding a stock)
k: Number of transactions made so far (0, 1, or 2)
dp: The dynamic programming table
Base Cases:
If i reaches the end of the array or k reaches 2 (no more transactions allowed), return 0 profit.
If the maximum profit for the current state is already calculated, return it from dp.
Logic:
If not holding a stock (j == 0):
Consider either buying a stock or doing nothing.
If holding a stock (j == 1):
Consider either selling the stock or doing nothing.
Memoization:
Store the calculated maximum profit in dp for future use.
Time and Space Complexity:

Time: O(n * 2 * 3) = O(n), due to filling the dp table and effectively reducing redundant calculations.
Space: O(n * 2 * 3) = O(n) for the dp table.
