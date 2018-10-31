#include <iostream>
#include <vector>

using namespace std;

int maxpartition(int num) {
	vector<int> sumproduct(num + 1, 0);
	for (int i = 1; i <= num; ++i) {
		int maxproduct = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int k = i - j;
			int p;
			if ((p = sumproduct[j] + sumproduct[k] + k * j) > maxproduct) maxproduct = p;
		}
		sumproduct[i] = maxproduct;
		cout << i << '\t' << sumproduct[i] << endl;
	}
	return sumproduct[num];
}

int main() {
	maxpartition(100);
	return 0;
}
