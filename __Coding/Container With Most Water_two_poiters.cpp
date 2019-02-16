/*
11. Container With Most Water
Medium

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
/*
- a greedy approach with 2 pointers each at one end point at the beginning
- keep the size of the current water that is the distance of the bars * min bar height
- then I release the min bar with a hope to get a higher bar next; If the max increased update the min.
- keep releasing the min bars till finish
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int i = 0; 
        int j = height.size()-1;
        int max = 0;
        while(i<j){
            int water = (j-i)*min(height[i], height[j]);
            if(water>max){
                max = water; 
            }
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return max;
    }
};