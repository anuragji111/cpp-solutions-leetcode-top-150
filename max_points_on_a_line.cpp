**Max Points on a line**

Problem Statement 135) Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:


Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

-----------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;  // Base case: 2 or fewer points always lie on a line
        }

        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            int duplicate = 1;  // Count the point itself
            int vertical = 0;  // Number of points with the same x-coordinate
            unordered_map<double, int> slopes;

            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    if (points[i][1] == points[j][1]) {
                        duplicate++;  // Handle duplicate points
                    } else {
                        vertical++;  // Handle vertical lines
                    }
                } else {
                    double slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    slopes[slope]++;
                }
            }

            maxCount = max(maxCount, duplicate + vertical);  // Include vertical points
            for (auto& [slope, count] : slopes) {
                maxCount = max(maxCount, count + duplicate);  // Include points on a non-vertical line
            }
        }

        return maxCount;
    }
};

---------------------------------------------Explanation:- 
Problem:

Given a vector of 2D points points, determine the maximum number of points that are collinear (lie on the same line).
Key Idea:

Iterate through each point and count the maximum number of points that share a line with it.
Handle duplicate points, vertical lines, and non-vertical lines separately.
Code Breakdown:

Base Case:

If there are 2 or fewer points, return the total number of points (they always lie on a line).
Iterate Through Points:

For each point points[i]:
Initialize duplicate to 1 (counting the point itself).
Initialize vertical to 0 (counting points with the same x-coordinate).
Create a slopes map to store the count of points with different slopes.
For each point points[j] after points[i]:
If they have the same x-coordinate:
If they also have the same y-coordinate, increment duplicate (duplicate point).
Otherwise, increment vertical (vertical line).
Otherwise, calculate the slope and increment the count in the slopes map.
Update maxCount with the maximum of:
duplicate + vertical (for vertical lines).
count + duplicate for each slope in the slopes map (for non-vertical lines).
Return Result:

Return the final maxCount, representing the maximum number of collinear points.
Time and Space Complexity:

Time: O(n^2), where n is the number of points, due to the nested loops.
Space: O(n) for the slopes map in the worst case.
