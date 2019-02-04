/*
Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that 
a + b + c + d = target? Find all unique quadruplets in 
the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplet
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        if(nums.size()<4)
            return r;
        for(int i=0;i<nums.size()-3;i++){  
            if (i>0 && nums[i - 1] == nums[i]) {
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if (j>i+1 && nums[j - 1] == nums[j]) {
                    continue;
                }
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){                    
                    int s = nums[i]+nums[left]+nums[right]+nums[j];
                    if(s==target){
                        r.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // Ensure we don't try and reuse the same value for the
                        // lower while we keep searching for more solutions
                        do {
                            ++left;
                          } while (left < right && nums[left - 1] == nums[left]);
                    }
                    else if(s < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
            
        }
        return r;
    }
};