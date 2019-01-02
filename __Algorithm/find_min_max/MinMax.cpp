/*
Implements finding minimum and maximum
 - Iterative:
    - Space Complexity: O(1)
    - Time Complexity: 3n/2 +constant
*/
//=========================== Implementation =======================
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int,int> FindMinMax(vector<int>& array)
{
    if(array.size()<=0)
        __throw_length_error("the input Array is empty!");
    if(array.size()==1)
    {
        return pair<int,int>(array[0],array[0]); 
    }
    int min = array[0];
    int max = array[1];
    if(array[0]>array[1]){//    one comparison
        min = array[1];
        max = array[0];
    }  
    int size = array.size();
    bool odd = false;
    if(size%2 == 1) // if array size is odd
    {
        size--;
        odd = true;
    }
    for(int i = 2;i<size;i+=2){// (n/2) iterations
        if(array[i]>array[i+1]){//    3 comparison per iteration
            if(array[i]>max){
                max = array[i];
            }
            if(array[i+1]<min){
                min = array[i+1];
            }
        }
        else{
            if(array[i+1]>max){
                max = array[i+1];
            }
            if(array[i]<min){
                min = array[i];
            }
        }
    }
    if(odd){ // 2 comparison for the odd case
        cout<<array[size+1]<<" "<<min<<" "<<max<<endl;
        min = (min<array[size])?min:array[size];
        max = (max<array[size])?array[size]:max;
    }
    return pair<int,int>(min,max);
}
//// ========================  testing ============================
TEST(MinmaxTest, emptyArray){
    //expect length exception if empty array
    vector<int> arr;
    ASSERT_THROW(FindMinMax(arr),std::length_error);
}
TEST(MinmaxTest, oneElementArray){
    //test for array with one element
    vector<int> arr = {-3};
    pair<int,int> minMax = FindMinMax(arr);
    ASSERT_EQ(minMax.first,-3);
    ASSERT_EQ(minMax.second,-3);
}
TEST(MinmaxTest, twoElementArray){
    //test for array with 2 element
    vector<int> arr = {-3,5};
    pair<int,int> minMax = FindMinMax(arr);
    ASSERT_EQ(minMax.first,-3);
    ASSERT_EQ(minMax.second,5);
}
TEST(MinmaxTest, oddElementArray){
    //test for array with odd element
    vector<int> arr = {-3,4,5,-13,12,-14,15};
    pair<int,int> minMax = FindMinMax(arr);
    ASSERT_EQ(minMax.first,-14);
    ASSERT_EQ(minMax.second,15);
}
TEST(MinmaxTest, evenElementArray){
    //test for array with even element
    vector<int> arr = {-3,5,-13,12,-14,15};
    pair<int,int> minMax = FindMinMax(arr);
    ASSERT_EQ(minMax.first,-14);
    ASSERT_EQ(minMax.second,15);
}