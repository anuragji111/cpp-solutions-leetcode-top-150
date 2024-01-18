**Sqrt(x)

Problem Statement 133) Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

-------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int mySqrt(int x) {
        // For special cases when x is 0 or 1, return x.
        if (x == 0 || x == 1)
            return x;
        
        // Initialize the search range for the square root.
        int start = 1;
        int end = x;
        int mid = -1;
        
        // Perform binary search to find the square root of x.
        while (start <= end) {
            // Calculate the middle point using "start + (end - start) / 2" to avoid integer overflow.
            mid = start + (end - start) / 2;
            
            // Convert mid to long to handle large values without overflow.
            long long square = static_cast<long long>(mid) * mid;
            
            // If the square of the middle value is greater than x, move the "end" to the left (mid - 1).
            if (square > x)
                end = mid - 1;
            else if (square == x)
                // If the square of the middle value is equal to x, we found the square root.
                return mid;
            else
                // If the square of the middle value is less than x, move the "start" to the right (mid + 1).
                start = mid + 1;
        }
        
        // The loop ends when "start" becomes greater than "end", and "end" is the integer value of the square root.
        // However, since we might have been using integer division in the calculations,
        // we round down the value of "end" to the nearest integer to get the correct square root.
        return static_cast<int>(std::round(end));
    }
};

--------------------------------------------------Explanation:-
Problem:

Given a non-negative integer x, find its integer square root, which is the largest integer y such that y * y <= x.
Key Idea:

Employ binary search to efficiently find the square root within the range of possible values.
Code Breakdown:

Special Cases:

Returns x if x is 0 or 1 (their square roots are themselves).
Binary Search:

Sets start to 1 and end to x to initiate the search range.
Iterates while start is less than or equal to end:
Calculates mid as the middle point using start + (end - start) / 2 to prevent integer overflow.
Calculates square as mid * mid while converting mid to long long to handle large values.
If square > x, updates end to mid - 1 to focus on smaller numbers.
If square == x, returns mid as the square root.
Otherwise, updates start to mid + 1 to explore larger numbers.
Return Result:

After the loop, end holds the integer part of the square root.
Returns end rounded down to the nearest integer for final accuracy.
Time and Space Complexity:

Time: O(log n), where n is the input integer, due to the logarithmic nature of binary search.
Space: O(1), as it uses a constant amount of extra space for variables.
