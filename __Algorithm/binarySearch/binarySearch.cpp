/*
Implements Binary Search and its testing
 - Iterative:
    - Space Complexity: O(1)
    - Time Complexity: O(log(n))
 - Recursive:
    - Space Complexity: O(log(n)) stack
    - Time Complexity: O(log(n))
*/
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
using namespace std;
int BinarySearchRecursive(vector<int>& array , int key, int left, int right)
{
    if(left<=right){
        int m = (left+right)/2;
        if(key == array[m]){
            return m;
        }
        if(key < array[m]){
            return BinarySearchRecursive(array, key, left, m-1);
        }
        // if(key > array[m]){
        return BinarySearchRecursive(array, key, m+1, right);
        
    }    
    return -1;
}
int BinarySearch(vector<int>& array , int key, int left, int right)
{
    while(left<=right)
    {
        int m = (left+right)/2;
        if(key == array[m])
            return m;
        if(key<array[m])
            right = m-1;
        else if(key > array[m])
            left = m+1;
    }
    return -1;
}
int BinarySearch(vector<int>& array , int key)
{
    if(array.size()>0)
        return BinarySearch(array,key,0,array.size()-1);
    else
        return -1;
}

TEST(BinarySearchTest, emptyArray){
    //expect -1 if array size is less than 0
    vector<int> arr;
    ASSERT_EQ(-1, BinarySearch(arr,5));
}
TEST(BinarySearchTest, notFound){
    //expect -1 if array size is less than 0
    vector<int> arr = {1,3,4,7,10,15};
    ASSERT_EQ(-1, BinarySearch(arr,6));
}
TEST(BinarySearchTest, Found){
    //look for all items and see if the index is correct
    vector<int> arr = {0,1,2,3,4,5};
    for(int i = 0;i<arr.size();i++)
    {
        ASSERT_EQ(i, BinarySearch(arr,i));
    }
}