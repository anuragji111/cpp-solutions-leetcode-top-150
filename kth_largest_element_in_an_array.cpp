**Kth Largest Element in an Array**

Problem Statement 120) Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

-----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
        
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); // Maintain only k largest elements
            }
        }
        
        return pq.top(); // kth largest element will be at the top
    }
};


------------------------------------------------------Explanation:-
Problem:

Given an array of integers and a value k, find the kth largest element in the array (where the largest element is the 1st largest).
Key Features:

Min-Heap: Uses a min-heap data structure to efficiently track the k largest elements seen so far.
Heap Size Management: Keeps the heap size limited to k to ensure it always holds only the relevant largest elements.
Code Breakdown:

1. findKthLargest Function:

Creates a min-heap named pq using priority_queue and a custom comparator (greater<int>) to ensure it's a min-heap.
Iterates through each element num in the input array nums:
Pushes num onto the min-heap.
If the heap size exceeds k, pops the smallest element from the heap (maintaining only the k largest elements).
Returns the top element of the heap (pq.top()), which is the kth largest element in the array.
Time and Space Complexity:

Time: O(n log k), where n is the number of elements in the array, due to the heap operations (push and pop) being logarithmic in the heap size (which is limited to k).
Space: O(k), as the heap stores a maximum of k elements.
