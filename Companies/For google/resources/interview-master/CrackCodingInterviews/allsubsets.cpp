#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subsets(vector<int> a) {
	vector<vector<int> > comb;
	comb.push_back(vector<int>());
	for (int i = 0; i < a.size(); ++i) {
		int s = comb.size();
		for (int j = 0; j < s; ++j) {
			vector<int> x = comb[j];
			x.push_back(a[i]);
			comb.push_back(x);
		}
	}
	return comb;
}

int main() {
	vector<int> a;
	a.push_back(0), a.push_back(1), a.push_back(2), a.push_back(3);
	vector<vector<int> > s = subsets(a);
	cout << s.size() << endl;
	for (int i = 0; i < s.size(); ++i) {
		cout << "[ ";
		for (int j = 0; j < s[i].size(); ++j) {
			cout << s[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}