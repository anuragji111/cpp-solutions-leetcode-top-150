Statement 23) Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

--------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
   int strStr(string haystack, string needle) {
       if (needle.empty()) {
           return 0;  // Empty needle is always found at the beginning
       }

       int m = haystack.length(), n = needle.length();

       for (int i = 0; i <= m - n; i++) {  // Iterate through potential starting positions in haystack
           int j = 0;
           while (j < n && haystack[i + j] == needle[j]) {  // Check for a match
               j++;
           }
           if (j == n) {
               return i;  // Match found
           }
       }
       
       return -1;  // Needle not found
   }
};
--------------------------------------------
