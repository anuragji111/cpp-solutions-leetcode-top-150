**Edit Distance**

Problem Statement 146) Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

-----------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases: empty strings
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],  // Insert
                                      dp[i][j - 1],   // Delete
                                      dp[i - 1][j - 1]}); // Replace
                }
            }
        }

        return dp[m][n];
    }
};

------------------------------------Explanation:-
Problem:

Given two strings word1 and word2, determine the minimum number of single-character edits (insertions, deletions, or replacements) required to transform word1 into word2.
Key Idea:

Utilize dynamic programming to efficiently compute the edit distance by building upon solutions for smaller subproblems.
Code Breakdown:

Initialization:

Get the lengths of the two strings (m and n).
Create a dp vector of vectors (size m + 1 by n + 1) to store edit distances.
Base Cases:

Fill the first row (dp[i][0]) and first column (dp[0][j]) to represent transformations to empty strings:
The edit distance to an empty string is equal to the length of the other string.
Build DP Table:

Iterate through the remaining cells of dp:
If the current characters in word1 and word2 match, no edit is needed, so:
dp[i][j] = dp[i - 1][j - 1]
Otherwise, consider the minimum edit distance from three possible options:
Insert: dp[i - 1][j] + 1
Delete: dp[i][j - 1] + 1
Replace: dp[i - 1][j - 1] + 1
Return Result:

The final value dp[m][n] represents the minimum edit distance between the entire word1 and word2.
Time and Space Complexity:

Time: O(m * n), where m and n are the lengths of the strings, due to filling the DP table.
Space: O(m * n) for the dp table.
