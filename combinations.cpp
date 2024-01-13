**Combinations**

Problem Statement 102) Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n

---------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;
        backtrack(combinations, combination, 1, n, k);
        return combinations;
    }

private:
    void backtrack(vector<vector<int>>& combinations, vector<int>& combination, int start, int n, int k) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            backtrack(combinations, combination, i + 1, n, k);
            combination.pop_back();
        }
    }
};

-------------------------Explanations:-
Key Features:

Backtracking: Explores possible combinations by recursively building and pruning candidate combinations.
Start Index: Guides exploration to avoid duplicates and improve efficiency.
Code Breakdown:

combine Function:

Initializes combinations to store the results.
Calls backtrack to initiate the backtracking process.
backtrack Function:

Base Case: If combination has size k, add it to combinations and return.
Iterate through numbers from start to n:
Append the current number to combination.
Recursively call backtrack with an updated start (i + 1) to avoid duplicates.
Backtrack (remove the number from combination).
Time and Space Complexity:

Time: O(N choose K), the number of combinations generated.
Space: O(K) for combination vector and recursion stack depth.
