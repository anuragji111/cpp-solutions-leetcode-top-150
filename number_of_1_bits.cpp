Number of 1 Bits**

Problem Statement 126) Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

Constraints:

The input must be a binary string of length 32.

----------------------------------------------------------------------------------------------------------
SOLUTION :- class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            // Check the rightmost bit and count it if it's 1
            count += n & 1;
            // Shift right to examine the next bit
            n >>= 1;
        }
        return count;
    }
};

-----------------------------------------------------Explanation:-
Problem:

Given a 32-bit unsigned integer n, calculate its Hamming weight, which is the number of 1 bits in its binary representation.
Key Features:

Bitwise Operations: Uses bitwise AND and right shift to isolate and examine individual bits.
Iterative Counting: Processes each bit from right to left, counting the 1 bits.
Code Breakdown:

1. hammingWeight Function:

Initializes count to 0 to store the number of 1 bits.
Iterates while n is greater than 0 (meaning there are still bits to check):
Checks the rightmost bit using n & 1. If it's 1, adds 1 to count.
Shifts n right by one bit using n >>= 1 to move to the next bit.
Returns the final count of 1 bits.
Time and Space Complexity:

Time: O(log n), where n is the input integer, as it processes at most 32 bits (the number of bits in a 32-bit integer).
Space: O(1), as it uses a constant amount of extra space for variables.
