**Construct Quad Tree

Problem Statement 109) Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing the Quad-Tree.

Example 2:



Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:

 

Constraints:

n == grid.length == grid[i].length
n == 2x where 0 <= x <= 6

-------------------------------------------------------------------------------------------------------
SOLUTION = /*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int val = grid[0][0];
        //cout << "val check: " << val << endl;
        bool splitQuad = false;
        for(vector<int>& v : grid){
            for(int& i : v){
                cout << i << ", ";
                if(i == val) continue;
                splitQuad = true;
                break;
            }
            cout << endl;
            if(splitQuad) break;
        }
        //if(splitQuad) cout << "splitting grid" << endl;
        //else cout << "leaf found, not splitting" << endl;
        Node * root = new Node(splitQuad ? 1 : val, !splitQuad);
        //cout << "node isLeaf: " << root->isLeaf << " node val: " << root-> val << endl;
        if(splitQuad){
            //split grid
            vector<vector<int>> topLeft;
            for(int i = 0; i < grid.size()/2; i++){
                vector<int> v;
                for(int j = 0; j < grid.size()/2; j++){
                    //cout << grid[i][j] << ", ";
                    v.push_back(grid[i][j]);
                }
                //cout << endl;
                topLeft.push_back(v);
            }
            root->topLeft = construct(topLeft);
            vector<vector<int>> topRight;
            for(int i = 0; i < grid.size()/2; i++){
                vector<int> v;
                for(int j = grid.size()/2; j < grid.size(); j++){
                    v.push_back(grid[i][j]);
                }
                topRight.push_back(v);
            }
            root->topRight = construct(topRight);
            vector<vector<int>> bottomLeft;
            for(int i = grid.size()/2; i < grid.size(); i++){
                vector<int> v;
                for(int j = 0; j < grid.size()/2; j++){
                    v.push_back(grid[i][j]);
                }
                bottomLeft.push_back(v);
            }
            root->bottomLeft = construct(bottomLeft);
            vector<vector<int>> bottomRight;
            for(int i = grid.size()/2; i < grid.size(); i++){
                vector<int> v;
                for(int j = grid.size()/2; j < grid.size(); j++){
                    v.push_back(grid[i][j]);
                }
                bottomRight.push_back(v);
            }
            root->bottomRight = construct(bottomRight);
        }
        return root;
    }
};

--------------------------------------Explanation:-
  Problem:

Given a 2D grid of 0s and 1s, create a QuadTree representation, where each node represents a subgrid and stores a single value if all elements in the subgrid are the same.
Key Features:

QuadTree Data Structure: A tree with four children per node, representing four quadrants of a grid.
Recursive Construction: Builds the QuadTree by recursively dividing subgrids into quadrants.
Code Breakdown:

1. construct Function:

Checks if the grid is already a leaf node (all elements identical):
If so, creates a leaf node with the value and returns it.
Otherwise, creates a non-leaf node and recursively constructs its children:
Divides the grid into four quadrants (topLeft, topRight, bottomLeft, bottomRight).
Recursively calls construct for each quadrant, creating child nodes.
Assigns the constructed child nodes to the appropriate child pointers of the current node.
Returns the root node of the constructed QuadTree.
2. Node Class:

Represents a node in the QuadTree:
val: Stores the value (0 or 1) if it's a leaf node.
isLeaf: Indicates whether it's a leaf node or not.
topLeft, topRight, bottomLeft, bottomRight: Pointers to child nodes (for non-leaf nodes).
Time and Space Complexity:

Time: O(N log N), where N is the number of grid elements (due to recursive calls and grid divisions).
Space: O(N) in the worst case for a fully unbalanced tree, but typically closer to O(N log N) in practice.
