#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() < 2) return s;
        string S = "^#";
        for (int i = 0; i < s.length(); ++i) {
            S = S + s[i] + "#";
        }
        S += "$";
        int n =  S.length();
        int *p = new int[n];
        int c = 0, r = 0;
        int longest = 0, center = 0;
        for (int i = 1; i < n - 1 - longest; ++i) {
            int i_mirror = 2 * c - i;
            p[i] = (i < r) ? min(p[i_mirror], r - i) : 0;
            while (S[i + p[i] + 1] == S[i - p[i] - 1]) p[i]++;
            if (p[i] + i > r) {
                c = i;
                r = p[i] + i;
            }
            if (p[i] > longest) {
                longest = p[i];
                center = i;
            }
        }
        return s.substr((center - 1) / 2 - longest / 2, longest);
    }
};

int main() {
	string str = "abcddcba";
	Solution s;
	cout << s.longestPalindrome(str) << endl;
	return 0;
}
