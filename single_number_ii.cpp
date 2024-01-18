**Single Number II**

Problem Statement 128) Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

-------------------------------------------Explanation:-
  Problem:

Given a vector nums where every element appears three times except for one, find the unique element.
Key Idea:

Use two variables, ones and twos, to track numbers seen once and twice, respectively, using bitwise operations.
Code Breakdown:

singleNumber Function:
Initializes ones and twos to 0.
Iterates through each element num in the vector:
Updates ones:
XORs num with ones to potentially add a new number or cancel a previous one.
ANDs the result with the negation of twos to clear any number that's been seen twice.
Updates twos:
XORs num with twos to potentially add a number seen twice or cancel one previously seen twice.
ANDs the result with the negation of ones to ensure only numbers seen twice remain.
Returns ones, which holds the number that's been seen once.
Time and Space Complexity:

Time: O(n), where n is the size of the vector, due to iterating through all elements.
Space: O(1), as it uses a constant amount of extra space for variables.
