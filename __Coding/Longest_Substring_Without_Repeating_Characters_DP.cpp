/*
Good example for corner cases
time: >2h

leetcode 3. Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring 
without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, 
             "pwke" is a subsequence and not a substring.
*/

/*
my solution:
three cases are possible:
1: s...k...k: k is repeated after start of last considered substr
2: k...s...k: k is repeated but before start of last considered substr
3: k is not repeated
 
*/
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int start = 0;
        int max = 0;
        int i = 0;
        for(i; i<s.size();i++){
            char ch = s[i];
            if(map.find(ch) != map.end()){//if repeatetive  
                if(map[ch]>= start) {
                    max = ((i-start)>max)?(i-start):max;// update max
                    start = map[ch]+1;
                }
                else{
                    max = ((i-start+1)>max)?(i-start+1):max;// update max
                }
            }
            map[ch] = i;
        }
        max = ((i-start)>max)?(i-start):max;// update max
        return max;        
    }
};
