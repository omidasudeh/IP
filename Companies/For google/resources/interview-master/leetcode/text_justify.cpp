#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
 vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            string line = "";
            int csize = 0;
            int space = 1; 
            int extra = 0;
            while (j < n && csize + words[j].length() + j - i <= L) {
                csize += words[j].length();
                ++j;
            }
            --j;
            if (j > i && j < n - 1) {
                extra = (L - csize - (j - i)) % (j - i);
                space += (L - csize - (j - i)) / (j - i);       
            }
            for (int k = i; k <= j; ++k) {
                line += words[k];
                if (k < j) {
                    line += string(space, ' ');
                    if (k - i < extra) line += ' ';
                }
            }
            if (line.length() < L) line += string(L - line.length(), ' ');
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    Solution s;
    vector<string> words;
	words.push_back("This"), words.push_back("is"), words.push_back("an"), words.push_back("example"), words.push_back("of"), words.push_back("justification");
    int l = 16;
    vector<string> ans = s.fullJustify(words, l);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}