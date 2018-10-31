class Solution {
public:
    bool checkpar(string s) {
        int l = s.length();
        for (int i = 0; i < l / 2; ++i) {
            if (s[i] != s[l - i - 1]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int longest = 1;
        int left = 0, right = 0;
        if (s.length() == 1) return s;
        for (int l = 0; l < s.length() - longest; ++l) {
            for (int r = s.length() - l; r > 0; --r) {
                if (checkpar(s.substr(l, r))) {
                    if (longest < r){
                        longest = r;
                        left = l;
                        right = r;
                    }
                    break;
                }
            }
        }
        return s.substr(left, right);
    }
};
