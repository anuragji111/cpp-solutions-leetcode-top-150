**Palindrome Number**

Problem Statement 130) Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

--------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;  // Negative numbers or numbers ending in 0 (except 0 itself) can't be palindromes
        }

        int revertedNum = 0;
        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNum || x == revertedNum / 10;  // Handle cases with even and odd digits
    }
};

-----------------------------------------------Explanation:- 
Problem:

Given an integer x, determine whether it's a palindrome (reads the same backward as forward).
Key Idea:

Reverse the integer and compare it to the original.
Handle cases with even and odd digits separately.
Code Breakdown:

isPalindrome Function:
Early returns false for:
Negative numbers (which can't be palindromes).
Numbers ending in 0 (except 0 itself), as they can't be palindromes either.
Initializes revertedNum to 0 to store the reversed integer.
Iterates while x is greater than revertedNum:
Appends the last digit of x to revertedNum.
Removes the last digit from x.
Returns true if x and revertedNum are equal (even number of digits) or if x is half of revertedNum (odd number of digits).
Time and Space Complexity:

Time: O(log n), where n is the absolute value of x, due to the number of divisions and modulo operations.
Space: O(1), as it uses a constant amount of extra space for variables.
