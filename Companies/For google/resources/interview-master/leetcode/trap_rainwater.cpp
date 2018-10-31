#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int water = 0;
        int highest = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > highest) highest = A[i];
        }
        int height = 1;
        for (int i = 1; i <= highest; ++i) {
            int left = -1;
            int lowest = highest;
            for (int j = 0; j < n; ++j) {
                if (A[j] >= i) {
                    if (left >= 0)
                        water += (j - left - 1) * height;
                    left = j;
                }
                if (A[j] < lowest && A[j] > i) lowest = A[j];
            }
            height = lowest - i;
            if (height) i += height - 1;       
        }
        return water;
    }
};

