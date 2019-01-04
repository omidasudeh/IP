/*
Implements randomized MergeSort and its testing
 - Recursive:
    - Space Complexity: best: average: worst:
    - Time Complexity : best: average: worst:
*/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../quickSort/quickSort.cpp"
using namespace std;
// =============================== Implementation ===========================
void Merge(vector<int>&array, int left,int right){
    if (array.size()<1)
        __throw_length_error("empty input array!");
    if(left<right){
        vector<int> temp(right-left+1);
        int mid = (left+right)/2;
        int i = left, j=mid+1;
        int k = 0;
        while(i<mid+1 && j<right+1){
            if(array[i]<=array[j]){
                temp[k] = array[i];
                i++;
                k++;
            }
            else{
                temp[k] = array[j];
                j++;
                k++;
            }
        }
        while(i<mid+1){
            temp[k] = array[i];
            i++;
            k++;
        }
        while(j<right+1){
            temp[k] = array[j];
            j++;
            k++;
        }
        for(int k = 0;k<temp.size();k++)
            array[left+k] = temp[k];
    }
    else if(left == right) return; 
    else
        __throw_invalid_argument("left should be >= right");

}
void MyMergeSort(vector<int>& array, int left, int right){
    if(left<right){ 
        int mid = (left+right)/2;
        MyMergeSort(array,left, mid);
        MyMergeSort(array,mid+1,right);
        Merge(array,left,right);
    }
    else if(left == right) return; 
    else
        __throw_invalid_argument("left should be >= right");
}
void MyMergeSort(vector<int>& array)
{
    if (array.size()<1)
        __throw_length_error("empty input array!");
    MyMergeSort(array,0,array.size()-1);
}
// =============================== testing ==================================
TEST(MergeSort, Merge_emptyArray){
    //expect length exception if array is empty
    vector<int> arr;
    ASSERT_THROW(Merge(arr,0,10), std::length_error);
}
TEST(MergeSort, Merge_oneElementArray){
    //expect sort of one element equal itself
    vector<int> arr = {1};
    Merge(arr,0,0);
    ASSERT_EQ(arr[0], 1);
}
TEST(MergeSort, Merge_incorrectLeftRightArgs){
    //expect invalid_args exception if wrong boundaries
    vector<int> arr = {13,6,20};
    ASSERT_THROW(Merge(arr,2,0), std::invalid_argument);
}
TEST(MergeSort, Merge_working){
    // 1. Given an even sized array with both halves sorted, merge the first half to the second
    // 2. Sort another copy of the input with quick sort
    // 3. expect result of 1. equal to 2.
    // 4. do the same for odd sized array    
    vector<int> arrEven = {13,15,22,33,35,44,1,2,3,4,5,6};
    vector<int> arrEven1 = {13,15,22,33,35,44,1,2,3,4,5,6};
    Merge(arrEven,0,arrEven.size()-1);
    myQSort(arrEven1);
    for(int i = 0;i<arrEven.size();i++){
        ASSERT_EQ(arrEven[i],arrEven1[i]);
    }

    vector<int> arrOdd = {13,15,22,33,35,44,1,2,3,4,5};
    vector<int> arrOdd1 = {13,15,22,33,35,44,1,2,3,4,5};
    Merge(arrOdd,0,arrOdd.size()-1);
    myQSort(arrOdd1);
    for(int i = 0;i<arrOdd.size();i++){
        ASSERT_EQ(arrOdd[i],arrOdd1[i]);
    }
}
TEST(MergeSort, emptyArray){
    //expect length exception if empty array
    vector<int> arr;
    ASSERT_THROW(MyMergeSort(arr), std::length_error);
}
TEST(MergeSort, oneElementArray){
    //expect sort of one element equal itself
    vector<int> arr = {1};
    MyMergeSort(arr);
    ASSERT_EQ(arr[0],1);
}
TEST(MergeSort, working){
    // expect the array to be sorted
    // 1. sort a given even sized array usin mergesort
    // 2. Sort another copy of the input with quick sort
    // 3. expect result of 1. equal to 2.
    // 4. do the same for odd sized array    
    vector<int> arrEven  = {2,4,3,7,4,-6,5,89,2,4,5,55,6,78};
    vector<int> arrEven1 = {2,4,3,7,4,-6,5,89,2,4,5,55,6,78};
    MyMergeSort(arrEven);
    myQSort(arrEven1);
    for(int i = 0;i<arrEven.size();i++){
        ASSERT_EQ(arrEven[i],arrEven1[i]);
    }

    vector<int> arrOdd  = {2,4,3,7,4,-6,5,89,4,5,55,6,78};
    vector<int> arrOdd1 = {2,4,3,7,4,-6,5,89,4,5,55,6,78};
    MyMergeSort(arrOdd);
    myQSort(arrOdd1);
    for(int i = 0;i<arrOdd.size();i++){
        ASSERT_EQ(arrOdd[i],arrOdd1[i]);
    }
}