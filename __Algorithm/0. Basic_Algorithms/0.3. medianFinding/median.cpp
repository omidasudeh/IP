/*
Implements randomized kth element ( and specifically median) and its testing
 - Recursive:
    - Space Complexity: best: average:log(n) stack worst:
    - Time Complexity : best: average:O(n) worst: 
*/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
// =============================== Implementation ===========================
int partition_helper(vector<int>&array, int left,int right){
    if (array.size()<1)
        __throw_length_error("empty input array!");
    if(left<=right){
        int i = left-1, j = left;
        while(j<right){
            if(array[j] > array[right]){
                j++;
            }
            else{
                i++;
                // swap array[i] <==> array[i]
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                j++;
            }
        }
        i++;
        // swap array[i] <==> array[right]
        int temp = array[right];
        array[right] = array[i];
        array[i] = temp;
        return i;
    }
    else
        __throw_invalid_argument("left should be >= right");

}
int randomizedPartition(vector<int>&array, int left,int right){
    // srand(time(0));
    int r = rand()%(right-left+1)+left;
    int temp = array[right];
    array[right] = array[r];
    array[r] = temp;
    return partition_helper(array,left,right);
}
int Kth_element(vector<int>&array, int left,int right, int k){
    if (array.size()<1)
        __throw_length_error("empty input array!");
    int p = randomizedPartition(array,left,right);
    // cout<<left<<":"<<right<<" k:"<<k<<" p:"<<p<<endl;

    if(p == (k-1)) return array[p];//kth element found
    if(p > k-1)
        return Kth_element(array,left,p-1,k);
    else //if(p<k)
        return Kth_element(array,p+1,right,k);
}
int Kth_element(vector<int>&array, int k){
    return Kth_element(array, 0, array.size()-1, k);
}
int Median(vector<int>&array){
    int mid = (array.size()+1)>>1;
   return Kth_element(array,mid);
}
// =============================== testing ==================================
TEST(Median, Median_emptyArray){
    //expect length exception if array is empty
    vector<int> arr;
    ASSERT_THROW(Median(arr), std::length_error);
}
TEST(Median, Median_oneElementArray){
    //expect 0th element if array size is 1
    vector<int> arr = {1};
    ASSERT_EQ(Median(arr), 1);
}
TEST(Median, brutal_test){
    // 1. get kth element from the kth-element algorithm
    // 2. get kth element from the sorted version of input array
    // 3. expect 1. and 2. to be equal
    // 4. test for both even and odd sized vectors
    vector<int> arrEven  = {2,4,3,7,4,-6,5,89,2,4,5,55,6,78};
    vector<int> arrEven1 = {2,4,3,7,4,-6,5,89,2,4,5,55,6,78};
    std::sort(arrEven1.begin(),arrEven1.end());
    for(int k = 1;k<=arrEven.size();k++){
        ASSERT_EQ(Kth_element(arrEven,k),arrEven1[k-1]);
    }

    vector<int> arrOdd  = {2,4,3,7,4,-6,5,89,4,5,55,6,78};
    vector<int> arrOdd1 = {2,4,3,7,4,-6,5,89,4,5,55,6,78};
    std::sort(arrOdd1.begin(),arrOdd1.end());
    for(int k = 1;k<=arrOdd.size();k++){
        ASSERT_EQ(Kth_element(arrOdd,k),arrOdd1[k-1]);
    }

}