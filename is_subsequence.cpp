Statement 26) Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;  // Move to the next character in s only if a match is found
            }
            j++;  // Always move to the next character in t
        }

        return i == s.size();  // True if all characters in s were matched
    }
};

-------------------------------------------------------------------------------------------------
Explanation:

Initialization:

Set two pointers, i and j, to the beginning of s and t, respectively.
Matching Characters:

Iterate while i is less than the length of s and j is less than the length of t:
If the current characters at s[i] and t[j] match:
Increment i to move to the next character in s.
Increment j to move to the next character in t regardless of whether there was a match.
Subsequence Check:

If the loop completes and i has reached the end of s (meaning all characters of s have been matched), return true (subsequence found).
Otherwise, return false (not a subsequence).
Output:

abc is a subsequence of ahbgdc: true
axc is a subsequence of ahbgdc: false
