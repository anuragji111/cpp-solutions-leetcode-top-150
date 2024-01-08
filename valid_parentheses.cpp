Statement 52) Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

-----------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c); // Push opening brackets onto the stack
            } else {
                if (stk.empty() || !matches(stk.top(), c)) {
                    return false; // No matching opening bracket or incorrect type
                }
                stk.pop(); // Pop the matching opening bracket
            }
        }

        return stk.empty(); // All opening brackets must have a closing counterpart
    }

private:
    bool matches(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

----------------------------------------------------------------------------------
  Explanation:

Stack for Tracking: We use a stack to keep track of opening brackets as we encounter them.
Mapping for Matches: We use a matches map to quickly check for corresponding closing brackets.
Iterating through Characters:
If the character is a closing bracket:
Check if the top of the stack is its matching opening bracket.
If not, there's a mismatch, so return false.
If it matches, pop the opening bracket from the stack.
If the character is an opening bracket:
Push it onto the stack to wait for its closing counterpart.
Checking for Completeness: After processing the entire string, return true only if the stack is empty, indicating all opening brackets have been matched.
