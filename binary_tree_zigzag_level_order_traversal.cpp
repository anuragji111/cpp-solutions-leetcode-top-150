**Binary Tree Zigzag Level Order Traversal**

Problem Statement 85) Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

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
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i =0; i<n; i++){
                TreeNode *x = q.front();
                q.pop();
                if(x->left!=nullptr) q.push(x->left);
                if(x->right!=nullptr) q.push(x->right);
                level.push_back(x->val);
            }
            ans.push_back(level);
        }
        return ans;
}
void reverse(vector<int> &v){
     int n = v.size();
     for(int i=0; i<n/2; i++){
         swap(v[i],v[n-1-i]);
     }
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans = levelOrder(root);
        int n = ans.size();
        for(int i=0; i<n; i++){
            if(i&1) reverse(ans[i]);
        }
    return ans;
    }
};

---------------Key Points:

Zigzag Traversal: Visits nodes level by level, but alternates the direction of traversal (left-to-right, then right-to-left, and so on).
Level Order Base: Uses a standard level order traversal as a foundation.
Explanation:
levelOrder Function:

Performs a standard level order traversal using a queue.
Returns a 2D vector result where each inner vector represents a level.
reverse Function:

Reverses the elements of a given vector.
zigzagLevelOrder Function:

Calls levelOrder to get the level-wise node values.
Iterates through the levels:
If the level index is odd, reverses the elements of that level's vector using reverse.
Returns the final result vector with zigzagged levels.
Time Complexity:

O(n), where n is the number of nodes in the tree, due to the level order traversal.
Space Complexity:

O(w), where w is the maximum width of the tree, due to the queue and the result vector potentially storing nodes up to the width of the tree.
