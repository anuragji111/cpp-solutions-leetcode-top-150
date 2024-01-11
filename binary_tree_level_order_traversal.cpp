**Binary Tree Level Order Traversal** 

Problem Statement 84) Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

-----------------------------------------------------------------
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;  // Empty tree
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};

-----------------------------------------------------------Key Points:

Level Order Traversal: Visits nodes level by level, starting from the root.
Queue Implementation: Uses a queue to manage the nodes during traversal.
Explanation:

Base Case: If the root is nullptr, return an empty result vector (no nodes).
Initialize Queue: Create a queue to store nodes for traversal.
Enqueue Root Node: Add the root node to the queue to start the traversal.
Iterate Levels:
While the queue is not empty:
Get the number of nodes (levelSize) in the current level (number of nodes in the queue).
Create a vector currentLevel to store nodes of the current level.
Iterate through the nodes in the current level:
Dequeue the front node.
Add its value to currentLevel.
Enqueue its left and right children (if any) for the next level.
Add the currentLevel vector to the result vector.
Return Result: Return the result vector containing level-wise node values.
Time Complexity:

O(n), where n is the number of nodes in the tree, as each node is visited exactly once.
Space Complexity:

O(w), where w is the maximum width of the tree (number of nodes at the widest level), due to the queue potentially storing nodes up to the width of the tree.
