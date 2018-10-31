class Solution {
public:
    vector<string> combination;
    vector<string> append(vector<string> com) {
        vector<string> app;
        for (string s : com) {
            string s1 = '(' + s + ')';
            string s2 = "()" + s;
            string s3 = s + "()";
            if (s1 == s2 && s2 == s3) app.push_back(s1);
            else if (s2 == s3) {
                app.push_back(s1);
                app.push_back(s2);
            }
            else {
                app.push_back(s1);
                app.push_back(s2);
                app.push_back(s3);
            }
        }
        return app;
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        combination = vector<string>{""};
        for (int i = 0; i < n; ++i) {
            combination = append(combination);
        }
        sort(combination.begin(), combination.end());
        return combination;
    }
};
