**Letter Combination of a Phone Number**

Problem Statement 101) Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> combinations;
        string combination;
        unordered_map<char, string> digitLetters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        backtrack(combinations, combination, digits, digitLetters, 0);
        return combinations;
    }

private:
    void backtrack(vector<string>& combinations, string& combination, string& digits, 
                    unordered_map<char, string>& digitLetters, int index) {
        if (index == digits.size()) {
            combinations.push_back(combination);
            return;
        }

        for (char letter : digitLetters[digits[index]]) {
            combination.push_back(letter);
            backtrack(combinations, combination, digits, digitLetters, index + 1);
            combination.pop_back();
        }
    }
};

--------------------------

letterCombinations Function:

Handles empty input case.
Initializes data structures:
combinations: To store the generated combinations.
combination: To build a single combination during exploration.
digitLetters: Maps digits to letters.
Calls the backtrack function to initiate the backtracking process.
backtrack Function:

Base Case: If index reaches the end of digits, add the current combination to combinations and return.
Iterate through the letters corresponding to the current digit:
Append the letter to combination.
Recursively call backtrack for the next digit.
Backtrack (remove the letter from combination).
Time and Space Complexity:

Time: O(4^N), where N is the number of digits (due to branching factor of 4 for most digits).
Space: O(N) for combination string and recursion stack depth.
