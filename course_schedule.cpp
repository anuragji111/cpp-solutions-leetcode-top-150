**Course Schedule**

Problem Statement 93) There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

-------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // Adjacency list
        vector<int> inDegree(numCourses, 0);  // In-degree of each course

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

        int count = 0;  // Count of courses taken
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int neighbor : graph[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;  // True if all courses can be taken
    }
};

--------------------------Problem:

Given a set of courses and prerequisites as pairs (course, prerequisite), determine if it's possible to complete all courses without encountering a cyclic dependency.
Key Points:

Graph Representation: Courses are represented as nodes, and prerequisites as directed edges.
In-Degree Tracking: The inDegree array stores the number of incoming edges for each course, indicating its dependencies.
Topological Sorting: A topological sort ensures courses are taken in a valid order, respecting prerequisites.
Cycle Detection: A cycle in the graph indicates an unresolvable dependency, making the course schedule impossible.
Explanation:

Graph and In-Degree Construction:

Creates an adjacency list graph to model course relationships.
Initializes inDegree to track course dependencies.
Builds the graph and in-degree counts based on prerequisites.
Course Scheduling:

Enqueues courses with no prerequisites (in-degree 0) into a queue.
While the queue is not empty:
Dequeues a course (it has no remaining dependencies).
Increments the count of courses taken.
Decrements in-degrees of its neighboring courses (prerequisites).
Enqueues neighboring courses with in-degree 0 (now ready to be taken).
Cycle Detection and Result:

If all courses have been taken (count equals numCourses), there's no cycle, and the schedule is possible.
Otherwise, a cycle exists, making the schedule impossible.
Time Complexity:

O(N + E), where N is the number of courses and E is the number of prerequisites (edges), due to graph construction and queue-based traversal.
Space Complexity:

O(N) for the graph, in-degree array, and queue.
