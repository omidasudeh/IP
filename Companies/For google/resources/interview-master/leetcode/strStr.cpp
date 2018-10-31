ass Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strlen(haystack);
        int m = strlen(needle);
        for (int i = 0; i <= n - m; ++i) {
            if (strncmp(haystack, needle, m) == 0) return haystack;
            ++haystack;
        }
        return NULL;
    }
};
