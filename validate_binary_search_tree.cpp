**Validate Binary Search Tree**

Problem Statement 88) Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

--------------------------------------------------------------------------------------------
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);  // Call helper with initial bounds
    }

private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) return true;  // Empty subtree is valid

        // Check node value against bounds
        if ((minNode != nullptr && node->val <= minNode->val) ||
            (maxNode != nullptr && node->val >= maxNode->val)) {
            return false;  // Violates BST property
        }

        // Recursively check subtrees with updated bounds
        return isValidBSTHelper(node->left, minNode, node) &&
               isValidBSTHelper(node->right, node, maxNode);
    }
};

------------Key Points:

Recursive Approach: It uses a recursive helper function to validate subtrees.
Bounds Checking: It enforces BST properties by passing upper and lower bounds to each subtree.
Explanation:

isValidBST Function:

Calls the isValidBSTHelper helper function with initial bounds (nullptr, nullptr) to start validation from the root.
Returns the result of the helper function.
isValidBSTHelper Function (Recursive):

Takes the current node, a minimum bound (minNode), and a maximum bound (maxNode) as parameters.
Base Case: If the current node is nullptr, return true (empty subtree is valid).
Bounds Checking:
If the current node's value violates either the minimum or maximum bound, return false (not a valid BST).
Recursive Subtree Validation:
Recursively call isValidBSTHelper for the left subtree with minNode unchanged and node as the new maximum bound.
Recursively call isValidBSTHelper for the right subtree with node as the new minimum bound and maxNode unchanged.
Return true only if both subtrees are valid BSTs.
Time Complexity:

O(n), where n is the number of nodes in the tree, as each node is visited once.
Space Complexity:

O(h), where h is the height of the tree, due to the recursive calls on the stack. In the worst-case scenario, the tree could be skewed, leading to a space complexity of O(n).

