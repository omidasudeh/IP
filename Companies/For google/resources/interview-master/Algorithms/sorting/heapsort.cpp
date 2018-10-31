#include <iostream>

using namespace std;

// O(log n)
void percolatedown(int A[], int p, int n) {
	int tmp = A[p];
	for (int child = 2 * p + 1; child < n; p = child, child = 2 * p + 1) {
		if (child + 1 < n && A[child + 1] > A[child]) child++;
		if (A[child] > tmp) A[p] = A[child];
		else break;
	}
	A[p] = tmp;
}

// O(n)
void buildheap(int A[], int n) {
	for (int i = n / 2; i >= 0; --i) {
		percolatedown(A, i, n);
	}
}

void heapsort(int A[], int n) {
	for (int i = n - 1; i > 0; --i) {
		swap(A[0], A[i]);
		percolatedown(A, 0, i);
	}
}
int main() {
	const int n = 10;
	int A[n] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	buildheap(A, n);
	heapsort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << endl;
	}
	return 0;
}