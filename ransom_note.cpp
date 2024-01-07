Statement 39) Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

-----------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        // Count character frequencies in magazine
        for (char c : magazine) {
            charCount[c]++;
        }
        // Check if ransomNote can be constructed using available characters
        for (char c : ransomNote) {
            if (charCount[c] == 0) {
                return false; // Character not found in magazine
            }
            charCount[c]--; // Decrement count to mark as used
        }
        return true;
    }
};
--------------------------------
