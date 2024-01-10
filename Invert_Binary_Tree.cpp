Problem Statement) 70) Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

-----------------------------------------------------------------------------------------------------
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;  // Base case: empty tree
        }

        TreeNode* temp = root->left;  // Swap left and right subtrees
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

--------------------------------------------------------------------
  Explanation:

Handle Empty Tree: Check for an empty tree and return nullptr.
Swap Children:
Store the left subtree in a temporary variable temp.
Swap the left and right subtrees of the current node using root->left = root->right and root->right = temp.
Recursive Inversion:
Recursively invert the left subtree using invertTree(root->left).
Recursively invert the right subtree using invertTree(root->right).
Return Root: Return the inverted tree's root.
