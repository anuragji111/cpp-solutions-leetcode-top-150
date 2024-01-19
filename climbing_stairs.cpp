**Climbing Stairs**

Problem Statement 136) You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

---------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int solve(int n,vector<int> &dp){
        //base case
        if(n<=2)
          return n;
        
        if(dp[n]!=-1) 
          return dp[n]; 
        
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

---------------------------------------------Explanation:-
Problem:

Given an integer n representing the number of stairs, determine the number of distinct ways to climb the stairs, taking one or two steps at a time.
Key Idea:

Employ dynamic programming to efficiently compute the number of ways for each stair count, breaking down the problem into smaller overlapping subproblems.
Code Breakdown:

solve Function (Recursive Helper):

Base Cases:
If n is less than or equal to 2, return n (there's only 1 way for 1 step and 2 ways for 2 steps).
Memoization:
If the result for n has already been calculated (dp[n] != -1), return the stored value.
Recursive Calls:
Calculate dp[n] as the sum of the ways to climb n-1 stairs and n-2 stairs, as each step can either be a single step or two steps.
Store the result in dp[n] for future use.
Return the calculated dp[n].
climbStairs Function (Main):

Base Case:
If n is less than or equal to 2, return n directly (using the base cases from solve).
Initialize Memoization:
Create a vector dp of size n+1 filled with -1 to store the calculated results.
Call Recursive Helper:
Call solve to calculate and return the number of ways for n stairs.
Time and Space Complexity:

Time: O(n), where n is the number of stairs, due to the memoization preventing redundant calculations.
Space: O(n) for the dp vector used for memoization.
