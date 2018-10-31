class Solution {
public:
    char getchar(int num) {
        return num + '0';
    }
    
    string multi(string num1, string num2) {
        int l1 = num1.length();
        vector<string> med(l1);
        int c = 0;
        for (int i = l1 - 1; i >= 0; --i) {
            med[i] = "";
            int mul = 0;
            c = 0;
            for (int j = num2.length() - 1; j >= 0; --j) {
                mul = num2[j] - '0';
                mul *= num1[i] - '0';
                mul += c;
                c = mul / 10;
                mul -= c * 10;
                med[i] = string("") + getchar(mul) + med[i];
            }
            while (c / 10) {
                med[i] = string("") + getchar(c % 10) + med[i];
                c /= 10;
            }
            if (c) med[i] = string("") + getchar(c) + med[i];
            for (int k = 0; k < l1 - 1 - i; ++k) {
                med[i] += '0';
            }
        }
        string ans = "";
        c = 0;
        for (int i = 0; i < med[0].length(); ++i) {
            int bitsum = 0;
            for (int j = 0; j < l1; ++j) {
                if (i < med[j].length()) bitsum += med[j][med[j].length() - i - 1] - '0';
            }
            bitsum += c;
            c = bitsum / 10;
            bitsum -= c * 10;
            
            ans = string("") + getchar(bitsum) + ans;
        }
        while (c / 10) {
            ans = string("") + getchar(c % 10) + ans;
            c /= 10;
        }
        if (c) ans = string("") + getchar(c) + ans;
        int rm = 0;
        while (ans[rm] == '0' && rm < ans.length() - 1) ++rm;
        return ans.substr(rm);
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = num1.length(), l2 = num2.length();
        if (l1 <= l2) return multi(num1, num2);
        return multi(num2, num1);
    }
};
