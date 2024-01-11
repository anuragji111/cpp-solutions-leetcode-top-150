**Binary Tree Right Side View**

Problem Statement 82) Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

  -------------------------------------------------------------------
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;  // Empty tree
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Add the rightmost node of each level to the result
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return result;
    }
};

---------------------------------------------------Key Points:

Right Side View: The nodes visible when the tree is viewed from the right side, meaning the rightmost node at each level.
Level Order Traversal: The code uses a level-order traversal (breadth-first search) to visit nodes level by level.
Explanation:

Base Case: If the root is nullptr, return an empty result vector (no nodes).
Initialize Queue: Create a queue to store nodes for level-order traversal.
Enqueue Root Node: Add the root node to the queue to initiate traversal.
Iterate Levels:
While the queue is not empty:
Get the number of nodes (levelSize) in the current level.
Iterate through the nodes in the current level:
Dequeue the front node.
If it's the last node in the current level (rightmost node):
Add its value to the result vector.
Enqueue its left and right children (if any) for the next level.
Return Result: Return the result vector containing the right side view.
Time Complexity:

O(n), where n is the number of nodes in the tree, as each node is visited exactly once.
Space Complexity:

O(w), where w is the maximum width of the tree (number of nodes at the widest level), due to the queue potentially storing nodes up to the width of the tree.
