Statement 43) Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

-----------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort characters for anagram key
            groups[sortedStr].push_back(str); // Group by sorted string
        }

        vector<vector<string>> result;
        for (auto& group : groups) {
            result.push_back(group.second); // Add each group to the result
        }

        return result;
    }
};

-------------------------------------------------------------
