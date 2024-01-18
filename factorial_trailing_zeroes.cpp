**Factorial Trailing Zeroes**

Problem Statement 132) Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

0 <= n <= 104
 
--------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

--------------------------------------------Explanation:-
Problem:

Given a non-negative integer n, calculate the number of trailing zeros in its factorial (n!).
Key Idea:

Trailing zeros in a factorial are solely determined by the number of 5s in its prime factorization.
Count multiples of 5, 25, 125, etc., up to n to determine the total number of 5s.
Code Breakdown:

trailingZeroes Function:
Initializes count to 0 to store the number of trailing zeros.
Iterates while n is greater than or equal to 5:
Adds the quotient of n / 5 to count, representing the number of multiples of 5 in the current range (5, 10, 15, ..., n).
Divides n by 5 to move to the next group of multiples (25, 50, 75, ...).
Returns the final count of trailing zeros.
Time and Space Complexity:

Time: O(log n), where n is the input integer, due to the number of divisions by 5.
Space: O(1), as it uses a constant amount of extra space for variables.
