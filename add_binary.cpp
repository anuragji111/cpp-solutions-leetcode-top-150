**Add Binary**

Problem Statement 124) Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

-----------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};

------------------------------------------Explanation:-
Problem:

Given two binary strings a and b, calculate their sum as a binary string.
Key Features:

Right-to-Left Iteration: Processes digits from right to left, similar to manual addition.
Carry Handling: Uses a carry variable to track overflow from each addition.
Character-to-Integer Conversion: Subtracts '0' from characters to get their integer values.
Code Breakdown:

1. addBinary Function:

Initializes variables:
ans: An empty string to store the sum.
carry: An integer to track carry-overs (initially 0).
i and j: Indices to traverse a and b from the right.
Iterates while both strings have digits or there's a carry:
If i is valid, adds the current digit of a to carry.
If j is valid, adds the current digit of b to carry.
Appends the remainder of carry modulo 2 (0 or 1) to ans.
Divides carry by 2 to propagate carry-overs.
Reverses ans to get the correct order of digits.
Returns the resulting sum string.
Time and Space Complexity:

Time: O(max(m, n)), where m and n are the lengths of the input strings, due to iterating through the longer string.
Space: O(max(m, n)), as the maximum length of the sum string is bounded by the longer input string.
