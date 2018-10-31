class Solution {
public:
    char alph(char x) {
        if (x <= 'z' && x >= 'a') return x;
        else if (x <= 'Z' && x >= 'A') return x + 32;
        else if (x <= '9' && x >= '0') return x;
        else return ' ';
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = s.length() - 1;
        int l = 0;
        while (l <= r) {
            while (l < r && alph(s[l]) == ' ') ++l;
            while (l < r && alph(s[r]) == ' ') --r;
            if (alph(s[l]) == alph(s[r])) ++l, --r;
            else return false;
        }
        return true;
    }
};
