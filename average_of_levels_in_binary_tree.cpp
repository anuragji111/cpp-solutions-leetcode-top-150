**Average of Levels in Binary Tree**

Problem Statement 83) Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

----------------------------------------------------------------------------------------------------
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (root == nullptr) {
            return result;  // Empty tree
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double levelSum = 0.0;
            int levelCount = q.size();

            for (int i = 0; i < levelCount; i++) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(levelSum / levelCount);  // Calculate and store average
        }

        return result;
    }
};

--------------------------------------------------------------------Key Points:

Level-Wise Averages: The code computes the average value of nodes at each level of the tree.
Level Order Traversal: It uses a level-order traversal (breadth-first search) to visit nodes level by level.
Explanation:

Base Case: If the root is nullptr, return an empty result vector (no levels).
Initialize Queue: Create a queue to store nodes for level-order traversal.
Enqueue Root Node: Add the root node to the queue to start the traversal.
Iterate Levels:
While the queue is not empty:
Initialize levelSum to 0 and levelCount to the current level's size (number of nodes in the queue).
Iterate through the nodes in the current level:
Dequeue the front node.
Add its value to levelSum.
Enqueue its left and right children (if any) for the next level.
Calculate the average for the current level (levelSum / levelCount) and add it to the result vector.
Return Result: Return the result vector containing the average of each level.
Time Complexity:

O(n), where n is the number of nodes in the tree, as each node is visited exactly once.
Space Complexity:

O(w), where w is the maximum width of the tree (number of nodes at the widest level), due to the queue potentially storing nodes up to the width of the tree.
