Statement 25) A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

  ------------------------------------------------------------------------------
SOLUTION= class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            // Find the next alphanumeric character from the left
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            // Find the next alphanumeric character from the right
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            // Compare the characters after converting to lowercase
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
--------------------------------------
  Explanation:

Preprocessing:

Convert all characters to lowercase using tolower.
Remove non-alphanumeric characters using isalnum.
Store the processed string in clean_str.
Palindrome Check:

Use two pointers, left and right, starting at the beginning and end of clean_str.
Iterate while left is less than right:
Compare the characters at left and right.
If they don't match, return false (not a palindrome).
Otherwise, move left to the right and right to the left.
Palindrome Found:

If the loop completes without finding any mismatches, return true (palindrome).
