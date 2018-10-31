#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] >= A[l]) {
                if (target >= A[l] && target <= A[mid]) r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (target >= A[mid] && target <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
int main() {
	const int n = 7;
	int target = 1;
	int A[n] = {4, 5, 6, 7, 0, 1, 2};
	Solution s;
	cout << s.search(A, n, target) << endl;
	return 0;
}
