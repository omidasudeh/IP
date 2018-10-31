class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 1;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            digits[n - 1 - i] += c;
            if (digits[n - 1 - i] >= 10) digits[n - 1 - i] -= 10;
            else {
                c = 0;
                break;
            }
        }
        if (c != 0) {
            digits.push_back(0);
            for (int i = n; i > 0; --i) {
                digits[i] = digits[i - 1];
            }
            digits[0] = 1;
        }
        return digits;
    }
};
