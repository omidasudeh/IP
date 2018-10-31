#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printout(vector<string> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> v(1, "");
        int head = 0, back = 0;
        int l = path.length();
        for (int i = 0; i < l; ++i) {
            int j = i;
            while (j < l && path[j] != '/') ++j;
            if (j == i) continue;
            string dir = path.substr(i, j - i);
            if (dir == ".") continue;
            else if (dir == ".." && back > 0) --back;
            else if (dir == "..") continue;
            else {
                if (back < v.size() - 1) v[++back] = dir;
                else {
                    v.push_back(dir);
                    ++back;
                }
            }
            i = j;
        }
        string ans = "";
        for (; head <= back; ++head) {
    		if (v[head] == "") continue;
            ans += '/';
            ans += v[head];
        }
		if (ans == "") ans += '/';
        return ans;
    }
};

int main() {
	string path = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
	Solution s;
	cout << s.simplifyPath(path) << endl;
	return 0;
}