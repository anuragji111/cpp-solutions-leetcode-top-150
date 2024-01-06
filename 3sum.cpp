Statement 29) Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation: 

nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.

nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.

nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

The distinct triplets are [-1,0,1] and [-1,-1,2].

Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]

Output: []

Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]

Output: [[0,0,0]]

Explanation: The only possible triplet sums up to 0.

-----------------------------------------------
SOLUTION = class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());  // Sort for two-pointer technique and duplicate handling
       vector<vector<int>> triplets;

       for (int i = 0; i < nums.size() - 2; i++) {
           if (i > 0 && nums[i] == nums[i - 1]) {  // Skip duplicates for the first element
               continue;
           }

           int left = i + 1, right = nums.size() - 1;
           while (left < right) {
               int sum = nums[i] + nums[left] + nums[right];
               if (sum == 0) {
                   triplets.push_back({nums[i], nums[left], nums[right]});
                   left++;
                   right--;
                   while (left < right && nums[left] == nums[left - 1]) {  // Skip duplicates for the second element
                       left++;
                   }
                   while (left < right && nums[right] == nums[right + 1]) {  // Skip duplicates for the third element
                       right--;
                   }
               } else if (sum < 0) {
                   left++;
               } else {
                   right--;
               }
           }
       }

       return triplets;
   }
};
