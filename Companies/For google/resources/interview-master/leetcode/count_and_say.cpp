class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string last = "1";
        string next = "";
        for (int i = 1; i < n; ++i) {
            int l = last.length();
            for (int j = 0; j < l; ++j) {
                char c = last[j];
                int t = 1;
                while (last[j + t] == c) ++t;
                next += ('0' + t);
                next += c;
                j += t - 1;
            }
            last = next;
            next = "";
        }
        return last;
    }
};
