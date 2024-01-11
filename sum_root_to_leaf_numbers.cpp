**Sum Root to Leaf Numbers**

Problem Statement 77)You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

-----------------------------------------------------------
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
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }

private:
    void dfs(TreeNode* root, int currentPathSum, int& totalSum) {
        if (root == nullptr) {
            return;  // Base case: empty tree
        }

        currentPathSum = currentPathSum * 10 + root->val;  // Update path sum

        if (root->left == nullptr && root->right == nullptr) {
            totalSum += currentPathSum;  // Leaf node: add to total sum
        } else {
            dfs(root->left, currentPathSum, totalSum);
            dfs(root->right, currentPathSum, totalSum);
        }
    }
};

-------------------------------------Explanation:

Helper Function: The sumNumbersHelper function takes the current node, the current path value, and a reference to the total sum.
Base Case: Handle empty subtrees by returning.
Update Current Path Value: Multiply the current path value by 10 and add the node's value to form a new partial number.
Add Leaf Node's Value: If the current node is a leaf, add its value (the complete path number) to the total sum.
Recursively Explore Subtrees: Recursively call sumNumbersHelper on both the left and right subtrees to accumulate the sums from all possible paths.
