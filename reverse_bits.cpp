**Reverse Bits**

Problem Statement 125) Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Constraints:

The input must be a binary string of length 32

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION:- 
class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=0;i<=31;i++)
        {
         ans=(ans<<1)|((n>>i)&1);
        }
        return ans;
    }
};

---------------------------------Explanation:- 
Problem:

Given a 32-bit unsigned integer n, return its binary representation with the bits reversed.
Key Features:

Bitwise Operations: Uses bitwise shifting and AND-ing to manipulate individual bits.
Iterative Approach: Processes each bit from left to right, building the reversed result.
Code Breakdown:

1. reverseBits Function:

Initializes ans to 0 to store the reversed result.
Iterates through each bit of n from left to right (31 to 0):
Extracts the current bit of n using (n >> i) & 1.
Shifts ans one position to the left to make space for the new bit.
ORs the extracted bit with ans to insert it into the correct position.
Returns the reversed integer ans.
Time and Space Complexity:

Time: O(1), as it performs a fixed number of operations independent of the input value.
Space: O(1), as it uses a constant amount of extra space for variables.
