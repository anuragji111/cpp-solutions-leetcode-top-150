**Find K Pairs with Smallest Sums**

Problem Statement 122) You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length

---------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;

        if (nums1.empty() || nums2.empty() || k == 0) {
            return result; // Handle empty arrays or k = 0
        }

        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1]; // Compare pairs based on sum
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        // Add initial pairs to the heap
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            pq.push({nums1[i], nums2[0], 0}); // Include index for nums2
        }

        while (k > 0 && !pq.empty()) {
            vector<int> pair = pq.top();
            pq.pop();
            result.push_back({pair[0], pair[1]});

            if (pair[2] + 1 < nums2.size()) { // Explore next element in nums2
                pq.push({pair[0], nums2[pair[2] + 1], pair[2] + 1});
            }

            k--;
        }

        return result;
    }
};

--------------------------------------Explanation:-
Problem:

Given two sorted arrays of integers and a value k, find the k smallest pairs (one element from each array) based on their sums.
Key Features:

Min-Heap: Uses a min-heap to efficiently track the potential pairs with the smallest sums.
Pair Representation: Stores pairs as 3-element vectors: (element from nums1, element from nums2, index in nums2).
Lazy Exploration: Explores elements in nums2 only when necessary to find smaller pairs.
Code Breakdown:

1. kSmallestPairs Function:

Handles empty arrays or k = 0 cases.
Creates a min-heap (pq) with a custom comparator to prioritize pairs with smaller sums.
Adds initial pairs (elements from nums1 paired with the first element of nums2) to the heap.
Iterates while k is greater than 0 and the heap is not empty:
Extracts the top pair (smallest sum) from the heap.
Adds the pair to the result vector.
If there's a next element in nums2 for the current element from nums1, adds a new pair with that element to the heap.
Decrements k.
Returns the result vector containing the k smallest pairs.
Time and Space Complexity:

Time: O(k log k) on average, due to heap operations (push and pop) being logarithmic in the heap size (which is limited to k), and each element being added to the heap at most once.
Space: O(k) for storing the pairs in the priority queue.
