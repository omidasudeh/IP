/*
10. Regular Expression Matching
Hard

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        //time: o(n^2) space:O(n^2)
        //recursion
        //f[i][j] = f[i-1][j-1]                 if s[i]== p[j] || p[j] == '.'
        //f[i][j] = f[i-1][j] || f[i][j-2]      if p[j] == '*' && (p[j-1] == s[i] || p[j-1] == '.')
        //f[i][j] = f[i][j-2]                   if p[j] == '*' && p[j-1] != s[i] && p[j-1] != '.'
        //f[i][j] = false       o.w.
        
        //boundary
        //f[i][0] = false; 
        //f[0][j] = (p[j] == '*' && f[0][j-2]);
        
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool>> f (m+1, vector<bool>(n+1,0));
       
        // empty pattern => not match
        //f[i][0] = false; 
        for(int i = 0; i<=m;i++)
            f[i][0]=false;

        //empty string and pattern == match
        f[0][0] = true;
        
        //empty string
        //f[0][j] = (p[j] == '*' && f[0][j-2]);
        for(int j = 2; j<=n;j++)
            f[0][j]= (p[j-1] == '*' && f[0][j-2]);
        
        for(int i = 1;i<=m;i++)
            for(int j = 1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    f[i][j] = f[i-1][j-1];
                else if(p[j-1] == '*'){
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        f[i][j] = f[i-1][j]||f[i][j-2];
                    else
                        f[i][j] = f[i][j-2];
                } 
                else
                    f[i][j] = false;
            }
        return f[m][n];
    }
};  
