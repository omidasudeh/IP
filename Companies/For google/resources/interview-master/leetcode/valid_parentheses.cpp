class Solution {
public:
    enum token {lparent, lbracket, lbrace, rparent, rbracket, rbrace};
    token gettoken(char c) {
        switch (c) {
            case '(': return lparent; 
            case '[': return lbracket;
            case '{': return lbrace;
            case ')': return rparent;
            case ']': return rbracket;
            case '}': return rbrace;
        }
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            int t = gettoken(s[i]);
            if (t > 2) {
                if (st.empty()) return false;
                else {
                    int p = st.top();
                    st.pop();
                    if (t - p != 3) return false;
                }
            }
            else st.push(t);
        }
        if (!st.empty()) return false;
        return true;
    }
};
