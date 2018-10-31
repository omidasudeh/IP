#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
vector<int> q;
int head, tail;

void init() {
	head = tail = 0;
	q = vector<int>(n);
}

void push(int e) {
	q[tail++] = e;
}

void pop_back() {
	--tail;
}

void pop_front() {
	++head;
}

int front() {
	return q[head];
}

int back() {
	return q[tail - 1];
}

bool empty() {
	return (tail - head) == 0;
}

void printout(vector<int> a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

vector<int> minimumValues() {
	vector<int> ans;
	init();
	for (int i = 0; i < n; ++i) {
		if (i >= k && a[i - k] == front()) pop_front();
		while (!empty() && a[i] < back()) pop_back();
		push(a[i]);
		if (i >= k - 1) ans.push_back(front()); 
	}
	return ans;
}

vector<int> maximumValues() {
	vector<int> ans;
	init();
	for (int i = 0; i < n; ++i) {
		if (i >= k && a[i - k] == front()) pop_front();
		while (!empty() && a[i] > back()) pop_back();
		push(a[i]);
		if (i >= k - 1) ans.push_back(front());
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	printout(minimumValues(), n - k + 1);
	printout(maximumValues(), n - k + 1);
	return 0;
}