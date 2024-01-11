**Flatten Binary Tree to Linked Lists**

Problem Statement 75) Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

---------------------------------------------------------------
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;  // Base case: empty tree
        }

        // Recursively flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree temporarily
        TreeNode* tempRight = root->right;

        // Connect the left subtree as the right subtree
        root->right = root->left;
        root->left = nullptr;  // Set left child to null

        // Find the end of the new right subtree (previously left subtree)
        TreeNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }

        // Append the original right subtree to the end
        current->right = tempRight;
    }
};

----------------------------------------------------------------------------

  Explanation:

Base Case: Handle empty trees by returning.
Recursive Flattening: Recursively flatten the left and right subtrees to ensure they are already in linked list form.
Append Left Subtree:
If the left subtree exists:
Temporarily store the original right subtree in temp.
Move the left subtree to the right of the root.
Set the left child of the root to nullptr.
Find the end of the appended left subtree.
Append the original right subtree to the end of the left subtree.
