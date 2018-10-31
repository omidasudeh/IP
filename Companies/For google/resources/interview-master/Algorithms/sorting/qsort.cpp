#include <iostream>

using namespace std;

void quicksort(int A[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	int pivot = A[m];
	swap(A[m], A[r]);
	int partitation = 0;
	for (int i = l; i < r; ++i) {
		if (A[i] < pivot) {
			swap(A[i], A[partitation++]);
		}
	}
	swap(A[partitation], A[r]);
	quicksort(A, l, partitation - 1);
	quicksort(A, partitation + 1, r);
}

int main() {
	const int n = 10;
	int A[n] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	quicksort(A, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << endl;
	}
	return 0;
}