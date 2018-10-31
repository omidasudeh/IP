class Solution {
public:
    vector<string> combination;
    
    void generate(string s, int l, int r) {
        if (!l && !r) {
            combination.push_back(s);
            return;
        }
        if (r > l) generate(s + ')', l, r - 1);
        if (l > 0) generate(s + '(', l - 1, r);
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        combination = vector<string>();
        generate("", n, n);
        return combination;
    }
};
