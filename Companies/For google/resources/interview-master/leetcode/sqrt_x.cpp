#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long l = 1, r = x;
        long long ans = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (mid * mid == x) return mid;
            if (mid * mid < x) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};

int main() {
	cout << INT_MAX << endl;
	return 0;
}