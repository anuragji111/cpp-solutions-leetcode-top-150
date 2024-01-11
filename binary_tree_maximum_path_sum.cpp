**Binary Tree Maximum Path Sum**

Problem Statement 78) A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000

-------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Initialize with minimum possible value
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;  // Base case: empty tree
        }

        int leftGain = max(0, maxGain(root->left, maxSum));  // Consider only non-negative gains
        int rightGain = max(0, maxGain(root->right, maxSum));

        // Update maxSum if the path including the current node is better
        maxSum = max(maxSum, root->val + leftGain + rightGain);

        // Return the maximum gain from either subtree (not both)
        return root->val + max(leftGain, rightGain);
    }
};

--------------------------------------Explanation:

Helper Function: The maxPathSumHelper function takes the current node and a reference to the maximum path sum found so far.
Base Case: Handle empty subtrees by returning 0.
Recursively Calculate Subtree Sums: Recursively call maxPathSumHelper on both the left and right subtrees to get their maximum path sums. Store these sums in leftSum and rightSum.
Ensure Non-Negative Path Sums: If either leftSum or rightSum is negative, set it to 0 to avoid decreasing the overall path sum.
Update Maximum Path Sum: If the sum of the current node, leftSum, and rightSum is greater than the current maxSum, update maxSum. This accounts for paths that include the current node and its subtrees.
Return Local Maximum Path Sum: Return the maximum path sum that includes the current node and either the left or right subtree (not both, as that would create a path with a cycle).
