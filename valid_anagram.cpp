Statement 42) Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

---------------------------------------
SOLUTION = class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false; // Different lengths, not anagrams
        }

        int charCount[26] = {0}; // Array to store character frequencies

        for (int i = 0; i < s.length(); i++) {
            charCount[s[i] - 'a']++; // Increment count for characters in s
            charCount[t[i] - 'a']--; // Decrement count for characters in t
        }

        for (int count : charCount) {
            if (count != 0) {
                return false; // Mismatch in character frequencies
            }
        }

        return true; // All character frequencies match
    }
};

--------------------------------------------
