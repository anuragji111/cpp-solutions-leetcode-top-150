**Course Schedule II**

Problem Statement 94) There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

-------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // Adjacency list
        vector<int> inDegree(numCourses, 0);   // In-degree of each course
        vector<int> order;                    // Resulting course order

        // Build the graph and in-degree counts
        for (const auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        queue<int> q;
        // Enqueue courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If topological sort is not possible (cycle detected), return empty array
        return order.size() == numCourses ? order : vector<int>();
    }
};

----------------------
Here's a breakdown of the C++ code for finding a valid course schedule order using topological sorting:

Problem:

Given a set of courses and prerequisites as pairs (course, prerequisite), find a valid order in which to take the courses, respecting dependencies.
Key Points:

Graph Representation: Courses are represented as nodes, and prerequisites as directed edges.
In-Degree Tracking: The inDegree array stores the number of incoming edges for each course, indicating its dependencies.
Topological Sorting: The algorithm finds a valid course order by repeatedly removing nodes with no incoming edges (no remaining dependencies).
Cycle Detection: A cycle in the graph indicates an unresolvable dependency, making a valid order impossible.
Explanation:

Graph and In-Degree Construction:

Creates an adjacency list graph to model course relationships.
Initializes inDegree to track course dependencies.
Builds the graph and in-degree counts based on prerequisites.
Topological Sorting:

Enqueues courses with no prerequisites (in-degree 0) into a queue.
While the queue is not empty:
Dequeues a course (it has no remaining dependencies).
Adds it to the order vector.
Decrements in-degrees of its neighboring courses (prerequisites).
Enqueues neighboring courses with in-degree 0 (now ready to be taken).
Cycle Detection and Result:

If all courses have been added to the order (no cycles), returns the valid course order.
Otherwise, a cycle exists, and no valid order is possible, so an empty vector is returned.
Time Complexity:

O(N + E), where N is the number of courses and E is the number of prerequisites (edges), due to graph construction and queue-based traversal.
Space Complexity:

O(N) for the graph, in-degree array, queue, and result vector.
