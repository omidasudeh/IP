/*
215. Kth Largest Element in an Array
Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        srand(time(0));
        if(l == r)
            return l;
        int p = rand()%(r-l+1)+l;//generate a random index between l and r
        swap(nums[p],nums[r]);
        int i = l;
        int j = l-1;
       while(i<r){
            if(nums[i]<nums[r]){
                j++;
                swap(nums[i],nums[j]);
                i++;
            }
           else
            i++;
        }
        j++;
        swap(nums[i],nums[j]);
        return j;
    }
    // int select(vector<int>& nums, int l, int r, int k){ // recursive
    //     int p  = partition(nums,l,r);
    //     if(p == k)
    //         return nums[k];
    //     else if(p>k){
    //         return select(nums,l,p-1,k);
    //     }
    //     else{
    //         return select(nums,p+1,r,k);
    //     }
    // }
    int select(vector<int>& nums, int l, int r, int k){ // you can write it iteratively to gain space
        while(l<r){
            int p  = partition(nums,l,r);
            if(p == k)
                return nums[k];
            else if(p>k)
                r = p-1;
            else
                l = p+1;
        }
        return nums[l];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return select(nums,0,nums.size()-1,nums.size()-k);
    }
};