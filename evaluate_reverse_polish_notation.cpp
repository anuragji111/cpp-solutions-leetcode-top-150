Statement 55) You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

----------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                int result = performOperation(operand1, operand2, token);
                operands.push(result);
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top(); // Final result is at the top of the stack
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int performOperation(int operand1, int operand2, const string& operatorToken) {
        switch (operatorToken[0]) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2; // Integer division (truncates towards zero)
            default:  return 0; // Should never reach here
        }
    }
};

-----------------------------------------------------------------------------------------------
Explanation:

Using a Stack: The code utilizes a stack to store operands and perform calculations in the correct order based on RPN's postfix nature.
Iterating through Tokens: It iterates through each token in the expression.
Operands: If a token is an operand (number), it's pushed onto the stack.
Operators: If a token is an operator:
It pops the top two operands from the stack.
It performs the corresponding operation based on the operator.
It pushes the result back onto the stack.
Final Result: After processing all tokens, the final result will be the only value remaining on the stack, and it's returned.
This approach effectively evaluates RPN expressions by taking advantage of the stack's LIFO (Last-In, First-Out) property, ensuring correct calculation order.
