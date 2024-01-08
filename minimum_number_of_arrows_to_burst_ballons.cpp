Statement 51) There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

-----------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end points
        });

        int arrows = 1;  // Count the first arrow
        int currentEnd = points[0][1];  // Track the end point of the last burst balloon

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > currentEnd) {  // No overlap, need a new arrow
                arrows++;
                currentEnd = points[i][1];  // Update end point
            }
        }

        return arrows;
    }
};

---------------------------
Explanation:

We sort the balloons based on their ending coordinates in ascending order. This helps minimize the overlap between balloons that can be burst by a single arrow.
We initialize an arrows counter to 1, assuming one arrow will be needed initially.
We iterate through each balloon.
If the current balloon's starting coordinate is beyond the reach of the current arrow (determined by the previous balloon's end), we increment the arrows counter and update the current end to the current balloon's end. This signifies a new arrow is needed.
Otherwise, if the current balloon's end is closer than the current arrow's reach, we update the current end to the closer value. This allows the current arrow to potentially burst this balloon and any with closer end coordinates.
After iterating through all balloons, the arrows counter holds the minimum number needed to burst all balloons.
This solution runs in O(n log n) time due to sorting and O(n) space complexity.
