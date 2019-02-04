/*
3sum 
Time: O(n^2)
Space: O(1)
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
============ Solution ===========
This famous problem has been proven to be unsolvable in less than O(n^2) time, 
so don't bother trying to do better. The idea is based on the 2Sum on an ordered list,
which can be solved in O(n) time. This is done by starting with two indexes, at either
end of the list (lower and upper). Comparing the target value with the two values
produces three possible cases;
    - lower + upper is less than target. This means we need to increase the sum,
      increaing lower index will achieve this.

    - lower + upper is greater than target. This means we need to decrease the sum,
      decreasing upper index will achieve this.

    - lower + upper equals target we're done.
These simple steps continue so long as lower is below upper. 
Thus we will only process the list once to find a target if it exists.

To solve 3Sum, we just expand on this idea, fix a first value,then perform 2Sum
on the remaining numbers. Thus For each n numbers, we perform the O(n) 2Sum
solution for an overall solution of O(n^2).
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        if(nums.size()<3)
            return r;
        // cout<<"here";
        for(int i=0;i<nums.size()-2;i++){
            if (i && nums[i - 1] == nums[i]) {
                // Ensure no duplicates using the same first number
                // from index 1 skip repeatitive numbers
                continue;
              }
            int target = -nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                vector<int> partial;
                if(nums[left]+nums[right] == target){
                    partial.push_back(-target);
                    partial.push_back(nums[left]);
                    partial.push_back(nums[right]);
                    r.push_back(partial);
                    // Ensure we don't try and reuse the same value for the
                    // left while we keep searching for more solutions
                    do {
                        ++left;
                      } while (left < right && nums[left - 1] == nums[left]);
                }
                else if(nums[left]+nums[right] < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return r;
    }
};