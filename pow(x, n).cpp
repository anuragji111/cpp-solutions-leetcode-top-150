**Pow(x, n)**

Problem Statement 134) Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;  // Base case: x^0 = 1
        }

        double half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;  // Even exponent: x^n = (x^n/2)^2
        } else if (n > 0) {
            return half * half * x;  // Odd exponent: x^n = (x^n/2)^2 * x
        } else {
            return half * half / x;  // Negative exponent: x^n = 1 / (x^-n) = (x^-n/2)^2 / x
        }
    }
};

------------------------------------Explanation:-
Problem:

Given a double x and an integer n, calculate x^n.
Key Idea:

Employ recursion and the property x^n = (x^n/2)^2 to efficiently compute the power.
Handle positive, negative, odd, and even exponents separately.
Code Breakdown:

Base Case:

If n is 0, return 1 (any non-zero base raised to 0 is 1).
Recursive Call:

Calculate half as x^(n/2) recursively, effectively halving the exponent.
Even Exponent:

If n is even, return half * half (applying x^n = (x^n/2)^2).
Odd Exponent (Positive):

If n is odd and positive, return half * half * x (accounting for the extra factor of x).
Negative Exponent:

If n is negative, return half * half / x (using x^n = 1 / (x^-n) and x^-n = (x^-n/2)^2).
Time and Space Complexity:

Time: O(log n), where n is the absolute value of the exponent, due to the recursive calls halving the exponent in each step.
Space: O(log n) for the recursion stack, also due to the halving of the exponent in each call.
