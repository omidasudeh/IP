/*
238. Product of Array Except Self
Medium

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
        //O(n) time O(1) space two passes one from left to right and then one from right to left
        ans.push_back(1);
        for(int i = 1;i<nums.size();i++)
            ans.push_back(ans.back()*nums[i-1]);
        int right = 1;
        for(int i = nums.size()-1;i>=0;i--){
            ans[i] *= right;
            right*=nums[i];
        }
        return ans;
    }
};