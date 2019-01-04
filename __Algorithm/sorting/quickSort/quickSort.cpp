/*
Implements randomized quickSort and its testing
 - Recursive:
    - Space Complexity: Best:O(log(n)) Average:O(log(n)) worst:O(n)
    - Time  Complexity: Best:O(nlog(n)) Average:O(nlog(n)) worst:O(n^2)
*/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
int randomizedpartition_helper(vector<int>&array, int left,int right){
    int r = rand()%(right-left+1)+left;
    int temp = array[right];
    array[right] = array[r];
    array[r] = temp;
    return partition_helper(array,left,right);
}
void myQSort(vector<int>& array, int left, int right){
    if(left<right){ 
        int p = randomizedpartition_helper(array,left,right);
        myQSort(array,left, p-1);
        myQSort(array,p+1, right);
    }
}
void myQSort(vector<int>& array)
{
    srand(time(0)); 
    if (array.size()<1)
        __throw_length_error("empty input array!");
    myQSort(array,0,array.size()-1);
}
// =============================== testing ==================================
TEST(quickSort, partition_emptyArray){
    //expect length exception if array is empty
    vector<int> arr;
    ASSERT_THROW(partition_helper(arr,0,10), std::length_error);
}
TEST(quickSort, partition_oneElementArray){
    //expect 0 if array size is 1
    vector<int> arr = {1};
    ASSERT_EQ(partition_helper(arr,0,0), 0);
}
TEST(quickSort, partition_incorrectLeftRightArgs){
    //expect invalid_args exception if array is empty
    vector<int> arr = {13,6,20};
    ASSERT_THROW(partition_helper(arr,2,0), std::invalid_argument);
}
TEST(quickSort, partition_working){
    // expect all the elements before the computed pivot <= pivot itself
    // expect all the elements after the computed pivot >= pivot itself
    
    vector<int> arr = {2,4,3,4,-6,5,89,2,4,5,55,6,78,7};
    int pivot = partition_helper(arr,0,arr.size()-1);
    for(int i = 0;i<arr.size();i++){
        if(i<pivot)
            ASSERT_LE(arr[i],arr[pivot]);
        else
            ASSERT_GE(arr[i],arr[pivot]);
    }
}
TEST(quickSort, emptyArray){
    //expect length exception if empty array
    vector<int> arr;
    ASSERT_THROW(myQSort(arr), std::length_error);
}
TEST(quickSort, oneElementArray){
    //expect length exception if empty array
    vector<int> arr = {1};
    myQSort(arr);
    ASSERT_EQ(arr[0],1);
}
TEST(quickSort, working){
    // expect the array to be sorted
    vector<int> arr = {2,4,3,7,4,-6,5,89,2,4,5,55,6,78};
    vector<int> arr_= {-6,2,2,3,4,4,4,5,5,6,7,55,78,89};
    myQSort(arr);
    for(int i = 0;i<arr.size();i++){
        ASSERT_EQ(arr[i], arr_[i]);
    }
}