**Plus One**

Problem Statement 131) You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Iterate from right to left, incrementing digits
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;  // No carry-over, return the result
            }

            digits[i] = 0;  // Handle carry-over
        }

        // If all digits were 9, create a new array with an extra 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

-------------------------------------Explanation:-
Problem:

Given a vector of digits digits, representing a non-negative integer, add 1 to it and return the result as a vector of digits.
Key Idea:

Mimic manual addition from right to left, handling carry-overs.
Code Breakdown:

plusOne Function:
Gets the size of the vector n.
Iterates from the rightmost digit to the leftmost:
If the current digit is less than 9, increments it and returns the result (no carry-over).
If the current digit is 9, sets it to 0 (carry-over) and continues to the next digit.
If all digits were 9 (carry-over to a new digit), inserts a 1 at the beginning of the vector.
Returns the final vector representing the incremented integer.
Time and Space Complexity:

Time: O(n), where n is the size of the vector, due to iterating through the digits.
Space: O(1) in the average case, but potentially O(n) in the worst case (when a new digit is added).
