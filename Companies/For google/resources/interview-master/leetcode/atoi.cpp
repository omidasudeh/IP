#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        int l = 0;
        int max = 0;
        bool neg = false;
        while (strncmp(str, " ", 1) == 0 || strncmp(str, "\t", 1) == 0 || strncmp(str, "\n", 1) == 0) ++str;
        if (strncmp(str, "-", 1) == 0 || strncmp(str, "+", 1) == 0) {
            if (strncmp(str, "-", 1) == 0) neg = true;
            ++str;
        }
        for (; *str; ++str) {
            if (strncmp(str, "0", 1) >= 0 && strncmp(str, "9", 1) <= 0) l = l * 10 + ((*str) - '0');
            else break;
            if (l >= INT_MAX / 10 && *(str + 1) >= '0' && *(str + 1) <= '9') {
                if (l == INT_MAX / 10 && ((neg && *(str + 1) <= '8') || (*(str + 1) <= '7'))) {
                    l = l * 10 + (*(str + 1) - '0');
                }
                else {
                    l = INT_MAX;
                    max = 1;
                }
                break;
            }
        }
        if (neg && max) return INT_MIN;
        else if (neg) return 0 - l;
        return l;
    }
};
int main() {
	Solution s;
	const char *str = "1234";
	cout << s.atoi(str) << endl;
	return 0;
}
