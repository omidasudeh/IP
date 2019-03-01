/*
283. Move Zeroes
Easy

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //  ?   l        r   zeros         
        //-----0xasdasdasy000000000000 
        // string has 3 portions:
        // 1 unknown:   0 to l-1
        // 2 non-zeros: l to r:
        // 3 zeros:     r+1 to s.size-1: 
        int right = nums.size()-1;
        int left = right;
        while(left>=0 && right>=0){
            while(right>=0 && nums[right] == 0)
                right--;
            if(right<0)
                return;
            left = right;
            
            while(left>=0 && nums[left] != 0)
                left--;
            
            if(left<0)
                return;
            
            // at this point l point to a zero item
            int zi = left;
            while(zi<right){
                swap(nums[zi], nums[zi+1]);
                zi++;
            }
            right--;
        }
    }
};