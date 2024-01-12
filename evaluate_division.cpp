

Problem Statement 92) You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

-----------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;  // Graph representation

        // Build the graph from equations
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];  // Store reciprocal for backtracking
        }

        vector<double> results;
        for (const auto& query : queries) {
            string start = query[0], end = query[1];
            if (!graph.count(start) || !graph.count(end)) {  // Handle undefined variables
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(graph, start, end, visited);
                results.push_back(result);
            }
        }

        return results;
    }

private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string start, string end, unordered_set<string>& visited) {
        if (start == end) return 1.0;  // Reached the end
        visited.insert(start);  // Mark as visited

        for (const auto& neighbor : graph[start]) {
            if (!visited.count(neighbor.first)) {
                double result = dfs(graph, neighbor.first, end, visited);
                if (result != -1.0) {
                    return result * neighbor.second;  // Backtrack and multiply
                }
            }
        }

        return -1.0;  // Path not found
    }
};

-----------------Problem:

Given equations and values as (u/v = k), calculate the value of (start/end) for multiple queries.
Key Points:

Graph Representation: Equations are modeled as a graph where nodes are variables and edges represent relationships with values.
DFS Pathfinding: DFS is used to traverse the graph and find paths between variables, calculating values along the way.
Backtracking and Multiplication: When a path is found, values are multiplied back through the path to obtain the final result.
Explanation:

calcEquation Function:

Builds the graph from equations and values.
Processes each query:
Handles undefined variables.
Calls dfs to find a path and calculate the result for valid queries.
Returns a vector of calculated values for all queries.
dfs Function (Recursive):

Base Case: If the start variable is found, return 1.0.
Mark the current variable as visited.
Recursively explore each neighbor:
If a path is found to the end variable, backtrack and multiply the result by the edge value.
Return -1.0 if no path is found.
Time Complexity:

O(N * E), where N is the number of variables and E is the number of equations (edges), due to DFS calls and potential repeated exploration of edges.
Space Complexity:

O(N) for the graph and visited set, assuming a connected graph.
