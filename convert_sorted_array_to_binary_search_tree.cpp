** Convert Sorted Array to Binary Search Tree ** 

Problem Statement 107) Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

--------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

--------------------------------Explanations:- 
  Key Features:

Divide and Conquer: Recursively constructs the BST by dividing the array into subarrays.
Midpoint as Root: Chooses the middle element of each subarray as the root of the subtree.
Code Breakdown:

1. sortedArrayToBST Function:

Calls the recursive helper function helper to initiate the BST construction.
2. helper Function (Recursive Helper):

Base Case: If left is greater than right, return nullptr (empty subtree).
Find the middle index of the current subarray: mid = left + (right - left) / 2.
Create a new TreeNode with the value at nums[mid] as its root.
Recursively construct the left subtree: root->left = helper(nums, left, mid - 1).
Recursively construct the right subtree: root->right = helper(nums, mid + 1, right).
Return the constructed root node.
Time and Space Complexity:

Time: O(N), where N is the number of elements in the array (each element is visited once).
Space: O(log N) for the recursion stack depth (due to the balanced nature of the BST).
