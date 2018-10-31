class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        int l = 0, r = n - 1;
        int area = min(height[l], height[r]) * (r - l);
        while (l < r) {
            while (l < r && height[l] <= height[r]) {
                ++l;
                area = max(min(height[l], height[r]) * (r - l), area);
            }
            while (l < r && height[r] <= height[l]) {
                --r;
                area = max(min(height[l], height[r]) * (r - l), area);
            }
        }
        return area;
    }
};
