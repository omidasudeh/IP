/*
2 sum 
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Note:
    Your returned answers (both index1 and index2) are not zero-based.
    You may assume that each input would have exactly one solution and you may not use the same element twice.

input: sorted array, int target 
- Given a sorted array find if there is a pair summing up to a target value
Time: O(n)
Space: O(1)
=================
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right] == target){
                vector<int> result;
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            if(numbers[left]+numbers[right] < target){
                left++;
            }
            else{
                right--;
            }
        }      
        vector<int> not_found;
        return not_found;
    }
};