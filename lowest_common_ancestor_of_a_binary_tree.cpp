**Lowest Common Ancestor of a Binary Tree**

Problem Statement 81) Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

----------------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;  // Base cases: empty tree or one of the targets found
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;  // Both targets found in subtrees, current node is LCA
        } else if (left != nullptr) {
            return left;  // Target found only in left subtree
        } else {
            return right; // Target found only in right subtree
        }
    }
};

-----------------------------------------------------Key Points:

Lowest Common Ancestor: The deepest node in a tree that has both p and q as descendants (where nodes can be descendants of themselves).
Recursive Approach: The code uses a recursive strategy to traverse the tree and identify the LCA.
Explanation:

Base Cases:
If the root is nullptr, there's no LCA, so return nullptr.
If the root is either p or q, it's the LCA of itself and the other node, so return the root.
Recursive Descent:
Recursively call lowestCommonAncestor on both the left and right subtrees to search for p and q in those subtrees.
LCA Identification:
If both recursive calls return non-null nodes, it means p and q were found in different subtrees, so the current node (root) is the LCA.
If only one recursive call returns a non-null node, it means both p and q were found in that subtree, so the LCA is in that subtree.
Return LCA:
Return the appropriate node based on the LCA identification logic.
Time Complexity:

O(n), where n is the number of nodes in the tree, as the code potentially visits every node in the worst case.
Space Complexity:

O(h), where h is the height of the tree, due to the recursive calls on the stack.
