**Count Complete Tree Nodes**

Problem Statement 80) Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

----------------------------------------------------------------------
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;  // Base case: empty tree
        }

        int leftHeight = 0, rightHeight = 0;
        TreeNode* left = root, *right = root;

        // Get heights of left and right subtrees
        while (left != nullptr) {
            leftHeight++;
            left = left->left;
        }
        while (right != nullptr) {
            rightHeight++;
            right = right->right;
        }

        // If heights are equal, it's a full complete binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;  // 2^height - 1
        } else {
            // Otherwise, count nodes recursively in subtrees
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

------------------------------------------------------------------------------------Key Points:

Complete Binary Tree: A binary tree where all levels are completely filled except possibly the last level, and all nodes in the last level are as far left as possible.
Optimized Approach: The code leverages the characteristics of complete binary trees to achieve a more efficient solution than a simple full traversal.
Explanation:

Base Case: If the root is nullptr, return 0 (no nodes).
Calculate Heights:
Get the heights of the left and right subtrees by following left and right child pointers until reaching nullptr.
Check for Completeness:
If the left and right subtree heights are equal, the tree is complete.
Calculate the total number of nodes using the formula 2^height - 1.
Recursive Count:
If the subtrees have different heights, the tree is not complete.
Recursively count nodes in the left and right subtrees and add 1 for the root node.
Time Complexity:

Average Case: O(log n), where n is the number of nodes, due to the efficient height-checking approach.
Worst Case: O(n), when the tree is skewed and resembles a linked list, forcing full traversals.
Space Complexity:

O(h), where h is the height of the tree, due to the recursive calls on the stack.
