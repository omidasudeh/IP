/*
560. Subarray Sum Equals K
Medium

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // solution1: brute force: get all pairs of indexes and compute sum(i,j) ==> O(n3) time and O(1) space
        // solution2: we can keep prefix-sum to be able to compute sum(i,j) = prefix-sum(j)-prefix-sum(i) in o(1) resulting in o(n^2) with O(n) space complexity; this can be modified to get O(1) space
        // solution3: hashmap O(n) time O(n) space
        vector<int>prefix_sum(nums.size(), 0);
        int count = 0;
        prefix_sum[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
           prefix_sum[i] = prefix_sum[i-1]+nums[i];
        for(int i = 0;i<nums.size();i++)
            for(int j = i;j<nums.size();j++){
                int t = prefix_sum[j]; 
                if(i > 0)
                    t -= prefix_sum[i-1];
                if( t == k)
                    count++;
            }
        return count;
    }
};