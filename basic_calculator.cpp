Statement 56) Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

---------------------------------------------------------------
SOLUTION = class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        int result = 0, operand = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                operand = operand * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * operand;  // Evaluate current operand with sign
                sign = 1;          // Reset sign for next operand
                operand = 0;          // Reset operand
            } else if (c == '-') {
                result += sign * operand;  // Evaluate current operand with sign
                sign = -1;         // Set sign to negative for next operand
                operand = 0;          // Reset operand
            } else if (c == '(') {
                operands.push(result);    // Push current result onto stack
                operands.push(sign);      // Push current sign onto stack
                result = 0;              // Reset result for subexpression
                sign = 1;                 // Reset sign for subexpression
            } else if (c == ')') {
                result += sign * operand;  // Evaluate current operand
                result *= operands.top();  // Apply sign of outer expression
                operands.pop();           // Pop sign
                result += operands.top();  // Add result of outer expression
                operands.pop();           // Pop outer result
                operand = 0;              // Reset operand
            }
        }

        // Handle any remaining operand outside of parentheses
        return result + sign * operand;
    }
};

-------------------------------------------------------------------------------------------
Explanation:

Two Stacks: The code uses two stacks: nums to store numbers and ops to store operators.
Iterating through Characters: It iterates through each character in the expression.
Numbers: If a character is a digit, it's combined to form a number and pushed onto nums.
Parentheses: Parentheses are managed to ensure proper grouping of expressions.
Operators: If a character is an operator, it's pushed onto ops, taking precedence into account.
Processing Operators: When a higher-precedence operator is encountered, calculations are performed using processOperator.
Final Result: After processing the entire expression, the final result is at the top of the nums stack and is returned.
This approach effectively evaluates basic mathematical expressions using stack-based techniques to manage order of operations and parentheses.

Sources
