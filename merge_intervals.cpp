Statement 49) Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

-----------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end()); // Sort by starting points

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& current = merged.back();
            vector<int>& next = intervals[i];

            if (current[1] >= next[0]) { // Overlap
                current[1] = max(current[1], next[1]); // Merge
            } else {
                merged.push_back(next); // No overlap, add as a new interval
            }
        }

        return merged;
    }
};
