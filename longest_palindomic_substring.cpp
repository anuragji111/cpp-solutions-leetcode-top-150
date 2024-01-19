**Longest Palindromic Substring**

Problem Statement 144) Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

-----------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string longest = "";  // Initialize longest palindrome found so far

        // Iterate through all possible centers of palindromes
        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2;
            int right = left + (center % 2);

            // Expand around the center to find the longest palindrome
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > longest.length()) {
                    longest = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }

        return longest;
    }
};

------------------------------------------Code Explanation:-
Problem:

Given a string s, identify the longest substring within it that is a palindrome (reads the same backward as forward).
Key Idea:

Expand around potential centers of palindromes to efficiently find the longest one.
Code Breakdown:

Initialization:

Get the length of the string (n).
Initialize an empty string longest to store the longest palindrome found so far.
Iterate Through Potential Centers:

Iterate through all possible centers of palindromes (center from 0 to 2 * n - 1):
Calculate the corresponding left and right indices for the potential palindrome:
left = center / 2
right = left + (center % 2)
Expand Around Center:

While both left and right indices are within bounds and the characters at those indices match:
If the current palindrome is longer than the longest found so far, update longest.
Expand the palindrome by moving left one position to the left and right one position to the right.
Return Result:

Return the longest palindrome found during the process.
Time and Space Complexity:

Time: O(n^2), where n is the length of the string, due to expanding around all potential centers.
Space: O(1) for extra variables, as the longest string doesn't exceed the input string's length.
