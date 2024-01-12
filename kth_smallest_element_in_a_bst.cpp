**Kth Smallest Element in a BST**

Problem Statement 87) Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

---------------------------------------------------------------------------
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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* result = nullptr;
        inorderTraversal(root, k, count, result);
        return result->val;  // Return the kth smallest value
    }

private:
    void inorderTraversal(TreeNode* node, int k, int& count, TreeNode*& result) {
        if (node == nullptr) return;

        inorderTraversal(node->left, k, count, result);

        count++;
        if (count == k) {
            result = node;  // Store the kth smallest value
            return;         // Stop traversal once found
        }

        inorderTraversal(node->right, k, count, result);
    }
};

--------------Key Points:

Inorder Traversal: It utilizes the fact that inorder traversal of a BST yields nodes in ascending order.
Early Termination: It stops traversal once the kth smallest element is found, improving efficiency.
Explanation:

kthSmallest Function:

Initializes count to 0 (node counter) and result to nullptr (to store the kth smallest node).
Calls the inorderTraversal helper function to traverse the tree and find the kth smallest element.
Returns the value of the result node.
inorderTraversal Function (Recursive):

Base Case: If the current node is nullptr, return.
Recursively traverse the left subtree to process nodes in ascending order.
Increment count for the current node.
If count equals k:
Store the current node in result as it's the kth smallest element.
Return to stop traversal, as we found the desired element.
Recursively traverse the right subtree.
Time Complexity:

O(h + k), where h is the height of the tree, and k is the value of k. In the average case, the time complexity is O(log n + k), where n is the number of nodes in the tree.
Space Complexity:

O(h), due to the recursive calls on the stack. In the worst-case scenario, the tree could be skewed, leading to a space complexity of O(n).
