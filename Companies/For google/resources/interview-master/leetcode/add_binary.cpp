class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int la = a.length(), lb = b.length();
        int l = min(la, lb);
        string ans = "";
        int c = 0, s = 0, i = 0;
        for (; i < l; ++i) {
            s = c;
            s += a[la - 1 - i] - '0' + b[lb - 1 - i] - '0';
            c = s >> 1;
            s -= c << 1;
            ans = string("") + char(s + '0') + ans;
        }
        for (; i < la; ++i) {
            s = c;
            s += a[la - 1 - i] - '0';
            c = s >> 1;
            s -= c << 1;
            ans = string("") + char(s + '0') + ans;
        }
        for (; i < lb; ++i) {
            s = c;
            s += b[lb - 1 - i] - '0';
            c = s >> 1;
            s -= c << 1;
            ans = string("") + char(s + '0') + ans;
        }
        if (c) ans = string("") + char(c + '0') + ans;
        return ans;
    }
};
