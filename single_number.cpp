**Single Number**

Problem Statement 127) Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

----------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num; // XOR each element with the accumulator
        }
        return single;
    }
};

-------------------------------Explanation:-
Problem:

Given a vector nums where every element appears twice except for one, find the unique element.
Key Idea:

Use the XOR operator's properties:
XORing a number with itself results in 0.
XORing 0 with any number results in the number itself.
Code Breakdown:

singleNumber Function:
Initializes single to 0 to store the unique number.
Iterates through each element num in the vector:
XORs num with single. This cancels out pairs of duplicate elements, leaving only the unique number in single.
Returns the final value of single, which is the unique number.
Time and Space Complexity:

Time: O(n), where n is the size of the vector, due to iterating through all elements.
Space: O(1), as it uses a constant amount of extra space for variables.
