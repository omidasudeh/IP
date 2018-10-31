class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *star_s = NULL, *star_p = NULL;
        while (*s) {
            while (*p == '*') {
                star_s = s;
                star_p = p++;
            }
            if (*p && (*s == *p || *p == '?')) {
                ++s;
                ++p;
            }
            else if (star_p) {
                s = ++star_s;
                p = star_p + 1;
            }
            else return false;
        }
        while (*p == '*') ++p;
        return *p == 0;
    }
};
