**Median of Two Sorted Array**

Problem Statement 119) Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

---------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;

        // Ensure nums1 is always the shorter array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int iMin = 0, iMax = m, half = (total + 1) / 2;

        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = half - i;

            // Partitions are invalid
            if (i < iMin || i > iMax) {
                break;
            }

            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == m) ? INT_MAX : nums1[i];
            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == n) ? INT_MAX : nums2[j];

            // Valid partition found
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if (total % 2 == 1) {
                    return max(maxLeftX, maxLeftY); // Odd, return the middle element
                } else {
                    // Even, return the average of the middle two elements
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }
            } else if (maxLeftX > minRightY) {
                iMax = i - 1; // Search left
            } else {
                iMin = i + 1; // Search right
            }
        }

        // Should never reach here
        return -1;
    }
};

-------------------------------------------------Explanation:-
Problem:

Given two sorted arrays of integers, find the median of the combined array (the middle value if the total number of elements is odd, or the average of the middle two values if even).
Key Features:

Divide and Conquer: Employs a binary search-like approach to efficiently find the median without merging the arrays.
Optimized Partitioning: Identifies the optimal partition between the arrays to locate the median elements.
Code Breakdown:

1. findMedianSortedArrays Function:

Gets the lengths of the two arrays and calculates the total number of elements.
Ensures nums1 is the shorter array for convenience (swaps if necessary).
Initializes variables for binary search-like partitioning:
iMin: Lower bound for the partition in nums1.
iMax: Upper bound for the partition in nums1.
half: Index of the median element in the combined array (rounded up).
Iterates using a loop until iMin is less than or equal to iMax:
Calculates the middle partition index (i) in nums1.
Determines the corresponding partition index (j) in nums2.
Handles invalid partitions (breaks the loop if necessary).
Identifies key elements at the boundaries of the partitions:
maxLeftX: Maximum element in the left partition of nums1.
minRightX: Minimum element in the right partition of nums1.
maxLeftY: Maximum element in the left partition of nums2.
minRightY: Minimum element in the right partition of nums2.
Checks for a valid partition (where the left partitions are less than or equal to the right partitions of both arrays):
If a valid partition is found, calculates and returns the median based on whether the total number of elements is odd or even.
If not a valid partition, adjusts iMin or iMax to continue the search.
Returns -1 if the loop completes without finding a valid partition (should not occur).
Time and Space Complexity:

Time: O(log (min(m, n))), where m and n are the lengths of the arrays, due to the binary search-like approach.
Space: O(1), as it uses a constant amount of extra space for variables, independent of the input size.
