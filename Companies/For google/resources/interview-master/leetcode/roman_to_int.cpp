class Solution {
public:
    
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<char, int> rom2int({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}
        , {'M', 1000}});
        unordered_map<string, int> subrom2int({{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}
        , {"CM", 900}});
        int n = s.length();
        string t;
        int num = 0, cn = 0;
        for (int i = 0; i < n; ++i) {
            if (i != n - 1 && rom2int[s[i]] < rom2int[s[i + 1]]) {
                t = "";
                t = t + s[i] + s[i + 1];
                cn = subrom2int[t];
                ++i;
            }
            else {
                cn = rom2int[s[i]];
            }
            num += cn;
        }
        return num;
    }
};
