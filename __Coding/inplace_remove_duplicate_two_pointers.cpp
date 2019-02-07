/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //baseline
        int r = nums.size()-1;
        int l = nums.size()-1;
        while(l>0){
            if(nums[l-1] == nums[l]){
                //shift l-r one to right
                for(int k = l;k<=r;k++){
                    nums[k-1] = nums[k];
                }
                r--;
            }
            l--;
        }
        return r+1;
    }
    int removeDuplicates1(vector<int>& nums) {// improvement multiple shift at once
        int r = nums.size()-1;
        int l = nums.size()-1;
        int j = l;
        while(l>0){
            int j = l;
            while(j>=1 && nums[j] == nums[j-1]) j--;
            int shift = l-j;
            if(shift>0)
            {
                for(int k = l;k<=r;k++){
                    nums[k-shift] = nums[k];
                }
                r-=shift;
                l-=shift;
            }
            else{
                l--;
            }
        }
        return r+1;
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int j = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
            
        }
        return j+1;
    }
};