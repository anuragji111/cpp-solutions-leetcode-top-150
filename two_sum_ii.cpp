Statement 27) Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

--------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};  // Add 1 to indices for 1-based indexing
            } else if (sum < target) {
                left++;  // Increase sum by moving left pointer
            } else {
                right--;  // Decrease sum by moving right pointer
            }
        }

        // No solution found
        return {};
    }
};

----------------------------------------------------------------------------------------------
Explanation:

Two Pointers:

Initialize two pointers, left and right, at the beginning and end of the array, respectively.
Sum Check:

Iterate while left is less than right:
Calculate the current sum of numbers[left] and numbers[right].
If the sum equals the target:
Return the indices left + 1 and right + 1 (adding 1 for 1-based indexing).
If the sum is less than the target:
Increment left to move towards a larger value.
If the sum is greater than the target:
Decrement right to move towards a smaller value.
