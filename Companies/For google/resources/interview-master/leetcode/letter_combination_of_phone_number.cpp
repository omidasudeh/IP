class Solution {
public:
    string map[9] = {"1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void attach(string s, string d) {
        if (d == "") {
            res.push_back(s);
            return;
        }
        int n = d[0] - '1';
        int l = map[n].length();
        for (int i = 0; i < l; ++i) {
            attach(s + map[n][i], d.substr(1));    
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = vector<string>();
        attach("", digits);
        return res;
    }
};
