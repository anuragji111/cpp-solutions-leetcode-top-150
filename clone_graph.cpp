**Clone Graph**

Problem Statement 91) Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

--------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;  // Handle empty graph

        unordered_map<Node*, Node*> visited;  // Map for original nodes to clones
        return dfsClone(node, visited);
    }

private:
    Node* dfsClone(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.count(node)) return visited[node];  // Already visited, return clone

        Node* clone = new Node(node->val);  // Create clone node
        visited[node] = clone;  // Store mapping

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfsClone(neighbor, visited));  // Clone neighbors recursively
        }

        return clone;
    }
};

---------------------------------Key Points:

Node Structure: Each Node has a value (val) and a list of neighbors (neighbors).
Visited Map: An unordered_map tracks visited nodes and their corresponding clones to avoid cycles and redundant cloning.
Recursive Exploration: DFS recursively clones individual nodes and their neighbors, preserving the graph structure.
Explanation:

cloneGraph Function:

Handles empty graph case.
Initializes a visited map to track node mappings.
Calls dfsClone to start cloning from the given node.
Returns the cloned graph's root node.
dfsClone Function (Recursive):

Base Case: If the node is already visited, return its existing clone from the visited map.
Create a new clone node with the same value as the original node.
Store the node-clone mapping in the visited map.
Recursively clone each neighbor:
Call dfsClone for the neighbor.
Add the returned clone to the clone node's neighbors list.
Return the created clone node.
Time Complexity:

O(N + E), where N is the number of nodes and E is the number of edges, as it visits each node and edge once.
Space Complexity:

O(N) for the visited map and recursion stack, assuming a connected graph.
