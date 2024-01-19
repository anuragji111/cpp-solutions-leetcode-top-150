**Word Break**

Problem Statement 138) Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

-------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // dp vector to store whether a substring ending at each index is breakable
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Base case: empty string is always breakable

        // Iterate through substring lengths
        for (int i = 1; i <= n; i++) {
            // Iterate through possible word lengths ending at index i
            for (int j = 0; j < i; j++) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;  // Breakable if a prefix is breakable and the remaining suffix is a word
                    break;         // No need to check further prefixes for this index
                }
            }
        }

        return dp[n];  // True if the entire string is breakable
    }
};

-------------------------Explanation:-
Problem:

Given a string s and a vector of strings wordDict representing a dictionary, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Key Idea:

Use dynamic programming to efficiently check if substrings of s are breakable, building upon the solutions for smaller substrings.
Code Breakdown:

Initialization:

Create a dp vector of size n + 1 filled with false to store whether substrings ending at each index are breakable.
Set dp[0] to true, as the empty string is always breakable.
Dynamic Programming:

Iterate through substring lengths from 1 to n:
Iterate through possible word lengths ending at index i:
If a prefix ending at index j is breakable (dp[j] is true) and the remaining suffix s.substr(j, i - j) is a word in the dictionary:
Set dp[i] to true (the substring ending at i is breakable).
Break the inner loop (no need to check further prefixes for this index).
Return Result:

Return dp[n], which indicates whether the entire string s is breakable.
Time and Space Complexity:

Time: O(n^2), where n is the length of s, due to the nested loops.
Space: O(n) for the dp vector.
