**IPO**

Problem Statement 121) Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109

---------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects; // Store projects as (capital, profit) pairs
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end()); // Sort by capital

        priority_queue<int> pq; // Max-heap to store available profits
        int i = 0;

        while (k > 0) {
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second); // Add available projects to the heap
                i++;
            }

            if (!pq.empty()) {
                w += pq.top(); // Invest in the most profitable project
                pq.pop();
                k--;
            } else {
                break; // No more projects can be started
            }
        }

        return w;
    }
};
----------------------------------------------------------------Explanations:-
Problem:

Given a list of projects with their required capital and potential profits, an initial capital w, and a maximum number of projects k that can be invested in, find the maximum capital that can be accumulated after investing in k projects.
Key Features:

Sorting and Prioritization: Combines sorting projects by capital with a max-heap to prioritize high-profit projects.
Maintaining Available Projects: Uses a loop and an index to track available projects based on current capital.
Code Breakdown:

1. findMaximizedCapital Function:

Stores project information as pairs of capital and profit in the projects vector.
Sorts projects based on capital to prioritize affordable projects.
Creates a max-heap named pq to store available project profits.
Iterates while k (number of projects to invest in) is greater than 0:
Adds available projects (those with capital less than or equal to current capital w) to the heap.
If the heap is not empty:
Invests in the most profitable project by adding its profit to w.
Removes the project from the heap and decrements k.
If the heap is empty, breaks the loop (no more projects can be started).
Returns the final accumulated capital w.
Time and Space Complexity:

Time: O(n log n) due to sorting, plus O(n log k) for heap operations, resulting in O(n log n) overall.
Space: O(n) for storing projects and the priority queue. Auety Quer post phase 
