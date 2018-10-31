#include <iostream>
#include <vector>

using namespace std;
// One pass
class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0, right = n - 1;
        for (int i = left; i <= right && left < right; ++i) {
            if (A[i] < 1) swap(A[i], A[left++]);
            if (A[i] > 1) swap(A[i--], A[right--]);
        }
    }
};
// Two Pass
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> colorcount(3, 0);
        for (int i = 0; i < n; ++i) {
            colorcount[A[i]]++;
        }
        int start = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = start; j < start + colorcount[i]; ++j) {
                A[j] = i;
            }
            start += colorcount[i];
        }
    }
};

int main() {
	const int n = 8;
	int A[n] = {2, 1, 2, 0, 1, 0, 2, 0};
	Solution s;
	s.sortColors(A, n);
	for (int i = 0; i < n; ++i) cout << A[i] << " ";
	cout << endl;
	return 0;
}