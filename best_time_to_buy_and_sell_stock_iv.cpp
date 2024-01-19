**Best Time to Buy and Sell Stock IV**

Problem Statement 148) You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxProfit(int k, vector<int>& Arr) {
        int n = Arr.size();

   vector<vector<int>> ahead(2,vector<int> (k+1,0));
   vector<vector<int>> cur(2,vector<int> (k+1,0));

      
       for(int ind = n-1;ind>=0;ind--){
           for(int buy=0;buy<=1;buy++){
               for(int cap=1;cap<=k;cap++){
                     if(buy==0){//Condition for buy
                  cur[buy][cap] = max(ahead[0][cap],-Arr[ind]+ahead[1][cap]);
                }
                if(buy==1){//Condition for Sell
                  cur[buy][cap] = max(ahead[1][cap], Arr[ind]+ahead[0][cap-1]);
                }
               }  
           }
           ahead = cur;
       }
       return ahead[0][k];
    }
};

----------------------------Explanation :-
Problem:

Given an array of stock prices Arr and a maximum number of transactions allowed k, determine the maximum profit that can be made by buying and selling stocks multiple times.
Key Idea:

Utilize dynamic programming to efficiently explore possible buying and selling decisions, building upon solutions for smaller subproblems.
Code Breakdown:

Initialization:

Get the size of the Arr array (n).
Create two 2D vectors ahead and cur (size 2 by k+1) to store maximum profits at different states.
Iterate Backwards:

Iterate through the Arr array in reverse order (ind from n-1 to 0):
Iterate through possible states:
buy = 0: Not holding a stock
buy = 1: Holding a stock
cap = 1 to k: Number of transactions remaining
Calculate Profits:

If not holding a stock (buy = 0):
Consider either buying the current stock or doing nothing.
If holding a stock (buy = 1):
Consider either selling the current stock or doing nothing.
Update ahead:

After each iteration, update ahead with the values from cur for the next iteration.
Return Result:

The final value ahead[0][k] represents the maximum profit achievable with at most k transactions.
Time and Space Complexity:

Time: O(n * k), due to iterating through the array and filling the DP tables.
Space: O(k) for the two DP tables.
