class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *end = s;
        int length = 0;
        while (*end) ++end;
        --end;
        while (*end && *end == ' ') --end;
        while (*end && *end != ' ') {
            --end;
            ++length;
        }
        return length;
    }
};
