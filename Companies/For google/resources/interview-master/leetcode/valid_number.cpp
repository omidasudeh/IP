class Solution {
public:
    bool isInteger(const char *s, int l, int r) {
        if (l >= r) return false;
        if (s[l] == '+' || s[l] == '-') ++l;
        bool hasDigit = false;
        for (int i = l; i < r; ++i) {
            if (s[i] < '0' || s[i] > '9') return false;
            else hasDigit = true;
        }
        return hasDigit;
    }
    bool isFloat(const char *s, int l, int r) {
        if (l >= r) return false;
        if (s[l] == '+' || s[l] == '-') ++l;
        bool hasDigit = false;
        bool hasDot = false;
        for (int i = l; i < r; ++i) {
            if (s[i] == '.' && !hasDot) {
                hasDot = true;
                continue;
            }
            if (s[i] <= '9' && s[i] >= '0') hasDigit = true;
            else return false;
        }
        return hasDigit;
    }
    bool isScientific(const char *s, int l, int r) {
        if (s[l] == '+' || s[l] == '-') ++l;
        bool hasDigit = false;
        int e = l;
        for (int i = l; i < r; ++i) {
            if (s[i] == 'e') {
                e = i;
                break;
            }
        }
        return isFloat(s, l, e) && isInteger(s, e + 1, r);
    }

    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = strlen(s);
        while (l < r && s[l] == ' ') ++l;
        while (l < r && s[r - 1] == ' ') --r;
        if (l >= r) return false;
        if (isInteger(s, l, r)) return true;
        if (isFloat(s, l, r)) return true;
        if (isScientific(s, l, r)) return true;
        return false;
    }
};
