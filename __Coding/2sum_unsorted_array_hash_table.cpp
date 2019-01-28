/*
2-sum 
time: O(n)
space: O(n)
=================
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            int key = target - nums[i];
            if(map.find(key)!= map.end() )
            {                   
                    result.push_back(map[key]);
                    result.push_back(i);
                    return result;
            }
            map[nums[i]] = i;
        }
        return result;
    }
    /*vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i = 0;i<n; i++)
            for (int j = i+1; j<n; j++ )
                if(nums[i]+nums[j]==target)
                {   
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        
    }*/
};