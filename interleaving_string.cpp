**Interleaving String**

Problem Statement 145) Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

---------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;  // Lengths must match
        }

        // dp[i][j] indicates whether s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;  // Empty strings are interleavings

        // Fill the first row: consider interleavings with empty s2
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the first column: consider interleavings with empty s1
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[n1][n2];
    }
};

--------------------------------------Explanation:-
Here's a concise explanation of the C++ code for checking if a string s3 is an interleaving of two other strings s1 and s2 using dynamic programming:

Problem:

Given three strings s1, s2, and s3, determine whether s3 can be formed by interleaving the characters of s1 and s2 in a way that preserves their relative order.
Key Idea:

Utilize dynamic programming to efficiently check for interleaving by building upon smaller subproblems.
Code Breakdown:

Initialization:

Get the lengths of the three strings (n1, n2, n3).
If the combined lengths of s1 and s2 don't match the length of s3, return false immediately (not possible).
Create a dp vector of vectors (size n1 + 1 by n2 + 1) to store boolean values indicating whether interleavings are possible.
Set dp[0][0] to true (empty strings are interleavings of each other).
Fill First Row and Column:

Fill the first row (dp[i][0]) by checking if s3's prefix matches s1's prefix.
Fill the first column (dp[0][j]) by checking if s3's prefix matches s2's prefix.
Fill Rest of DP Table:

Iterate through the remaining cells of dp:
Set dp[i][j] to true if either of these conditions holds:
dp[i - 1][j] is true and the current character in s3 matches the last character in s1.
dp[i][j - 1] is true and the current character in s3 matches the last character in s2.
Return Result:

The final value dp[n1][n2] indicates whether s3 is a valid interleaving of s1 and s2.
Time and Space Complexity:

Time: O(n1 * n2), where n1 and n2 are the lengths of s1 and s2, due to filling the DP table.
Space: O(n1 * n2) for the dp table.
