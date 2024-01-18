**Bitwise AND of Numbers Range**

Problem Statement 129) Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1

----------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }
        return left << count;
    }
};

---------------------------------------------Explanation:- 
Problem:

Given two integers left and right, representing a range, calculate the bitwise AND of all numbers within that range (inclusive).
Key Idea:

Find the common prefix of 1s in the binary representations of left and right.
Shift those common 1s to their correct positions to form the final result.
Code Breakdown:

rangeBitwiseAnd Function:
Initializes count to 0 to count the number of common 1s.
Iterates while left and right are different:
Shifts both left and right one bit to the right using >>= 1. This removes the rightmost bits and aligns the remaining bits.
Increments count to track the number of shifts.
Returns left shifted left by count using << count. This moves the common 1s back to their original positions, forming the bitwise AND of the range.
Time and Space Complexity:

Time: O(log n), where n is the maximum of left and right, due to the number of shifts needed to find the common prefix.
Space: O(1), as it uses a constant amount of extra space for variables.
