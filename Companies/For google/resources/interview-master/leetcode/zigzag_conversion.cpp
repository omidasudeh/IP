class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<string> v(nRows, "");
        int n = s.length();
        if (nRows <= 1) return s;
        int t = 0;
        int mod = nRows + nRows - 2;
        for (int m = 0; t * mod + m < n; ++m) {
            if (m >= nRows) {
                v[mod - m] += s[t * mod + m];
            }
            else v[m] += s[t * mod + m];
            if (m == mod - 1) {
                m = -1;
                ++t;
            }
        }
        
        string r = "";
        for (int i = 0; i < nRows; ++i) {
            r = r + v[i];
        }
        return r;
    }
};
