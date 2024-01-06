Statement 28) You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

---------------------------------
SOLUTION = class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            if (height[left] < height[right]) {
                left++;  // Move the shorter line to explore larger areas
            } else {
                right--;
            }
        }
    
        return maxArea;
    }
};
------------------------------------
  Explanation:

Initialization:

Set left and right pointers to the start and end of the height array.
Initialize max_area to 0 to track the maximum area found.
Two-Pointer Approach:

Iterate while left is less than right:
Calculate the current area using min(height[left], height[right]) * (right - left).
Update max_area if the current area is larger.
Move the pointer with the smaller height to explore wider areas:
If height[left] is smaller, increment left.
If height[right] is smaller, decrement right.
