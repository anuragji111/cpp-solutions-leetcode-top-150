**Permutations**

Problem Statement 103) Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

--------------------------------------------------------------------------------------
SOLUTIOn = class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(permutations, nums, 0);
        return permutations;
    }

private:
    void backtrack(vector<vector<int>>& permutations, vector<int>& nums, int start) {
        if (start == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(permutations, nums, start + 1);
            swap(nums[start], nums[i]); // Backtrack
        }
    }
};

-------------------------EXPLANATIONSS:- 
  Key Features:

Backtracking: Explores possible permutations by recursively swapping elements and backtracking when necessary.
In-Place Swapping: Modifies the input array directly to avoid extra memory usage.
Code Breakdown:

permute Function:

Initializes permutations to store the results.
Calls backtrack to initiate the backtracking process.
backtrack Function:

Base Case: If start reaches the end of nums, add the current permutation to permutations and return.
Iterate through elements from start to the end of nums:
Swap the current element with the element at start.
Recursively call backtrack for the next position.
Backtrack (swap back to the original order).
Time and Space Complexity:

Time: O(N!), where N is the number of elements in the array (generating all possible permutations).
Space: O(N) for permutations vector and recursion stack depth (no additional space for permutations themselves).
