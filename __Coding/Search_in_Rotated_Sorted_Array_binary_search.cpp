/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:
    int find_drop(vector<int>& nums){//finds the index of step down in O( log(n) )
        int l = 0;
        int r = nums.size()-1;
        if(nums[l]<nums[r])
            return -1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[l]>= nums[m])
                r = m;
            else if(nums[r]<= nums[m])
                l = m;
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int p = find_drop(nums);
        int l = 0;
        int r = nums.size()-1;
        int r1 = p;
        int l1 = p+1;
        if(p>= 0){
            while(l<=r1){
                int m = (l+r1)/2;
                if(nums[m]== target)
                   return m;
                else if(nums[m]< target)
                    l = m+1;
                else if(nums[m]> target)
                    r1 = m-1;
            }
            while(l1<=r){
                int m = (l1+r)/2;
                if(nums[m]== target)
                   return m;
                else if(nums[m]< target)
                    l1 = m+1;
                else if(nums[m]> target)
                    r = m-1;
            }
        }
        else{
            while(l<=r){
                int m = (l+r)/2;
                if(nums[m]== target)
                   return m;
                else if(nums[m]< target)
                    l = m+1;
                else if(nums[m]> target)
                    r = m-1;
            }
        }
        return -1;
    }
};