**Minimum Absolute Difference in BST**

Problem Statement 86) Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105

--------------------------------------------------------------
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
    int getMinimumDifference(TreeNode* root) {
        int prev = -1, minDiff = INT_MAX;  // Initialize prev and minDiff
        inorderTraversal(root, prev, minDiff);
        return minDiff;  // Return the minimum difference found
    }

private:
    void inorderTraversal(TreeNode* node, int& prev, int& minDiff) {
        if (node == nullptr) return;

        inorderTraversal(node->left, prev, minDiff);

        if (prev != -1) {  // Update minDiff if prev is valid
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;  // Update prev for the next comparison

        inorderTraversal(node->right, prev, minDiff);
    }
};

----------Key Points:

Inorder Traversal: It leverages the fact that inorder traversal of a BST yields nodes in sorted order.
Iterative Difference Calculation: It tracks the previous node's value during traversal to compute differences.
Explanation:

getMinimumDifference Function:

Initializes prev to -1 (no previous node yet) and minDiff to INT_MAX (initially assume a large difference).
Calls the inorderTraversal helper function to traverse the tree and update minDiff.
Returns the final minDiff value.
inorderTraversal Function (Recursive):

Base Case: If the current node is nullptr, return.
Recursively traverse the left subtree to process nodes in ascending order.
If prev is not -1 (meaning a previous node exists):
Calculate the difference between the current node's value and prev.
Update minDiff if the calculated difference is smaller.
Update prev to the current node's value for the next comparison.
Recursively traverse the right subtree.
Time Complexity:

O(n), where n is the number of nodes in the tree, as each node is visited exactly once during the inorder traversal.
Space Complexity:

O(h), where h is the height of the tree, due to the recursive calls on the stack. In the worst-case scenario, the tree could be skewed, leading to a space complexity of O(n).
