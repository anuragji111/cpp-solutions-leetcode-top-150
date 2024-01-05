Statement 20) Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

-----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";  // Handle empty input
        }

        string prefix = strs[0];  // Start with the first string as the potential prefix

        for (int i = 1; i < strs.size(); i++) {
            // Compare the prefix with each string, updating it as needed
            while (strs[i].find(prefix) != 0) {  // While the current string doesn't start with the prefix
                prefix = prefix.substr(0, prefix.length() - 1);  // Shorten the prefix by one character
                if (prefix.empty()) {
                    return "";  // No common prefix found
                }
            }
        }

        return prefix;  // Return the final common prefix
    }
};

-----------------------------------------------------------
