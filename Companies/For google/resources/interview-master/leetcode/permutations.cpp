#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int> permu;
    typedef vector<permu> permuset;
    
    permuset addperm(permuset comb, int v, int index) {
        permuset newcomb;
        permu tmp;
        for (int x = 0; x < comb.size(); ++x) {
            for (int i = index; i >= 0; --i) {               
                tmp = comb[x];
                tmp.push_back(v);
                swap(tmp[i], tmp[index]);
                newcomb.push_back(tmp);
            }
        }
        return newcomb;
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        permuset comb;
	sort(num.begin(), num.end());
        comb.push_back(permu());
        for (int i = 0; i < num.size(); ++i) {
            comb = addperm(comb, num[i], i);
        }
        return comb;
    }
};

int main() {
	Solution s;
	vector<int> num;
	num.push_back(0);
	num.push_back(2);
	num.push_back(3);
	num.push_back(1);
	vector<vector<int> > ans = s.permute(num);
	for (int i = 0; i < ans.size(); ++i) {
		cout << "[";
		for (int j = 0; j < num.size(); ++j) {
			cout << ans[i][j] << ", ";
		}
		cout << "]\n";
	}
	return 0;
}
