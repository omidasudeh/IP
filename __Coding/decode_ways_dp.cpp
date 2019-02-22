/*
91. Decode Ways
Medium

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
        //DP: let F[i] denote the number of decodings for a1 a2 ... ai_1 ai
        // F[i] = F[i-1]+F[i-2]  a[i-1]a[i]<27
        // F[i] = F[i-1]            O.W.
        //GOAL: F[s.size()-1]
        //Boundary: F[0] is ""
        if(s.size() == 0)
            return 0;
        vector<int> F(s.size(),0);// the number of ways we can decode a1 a2...aiai-1
        if(s[0]>='1' && s[0]<='9')
            F[0] = 1;
        else // error: cannot start with zero
            return 0;
        if(s[1]>='1' && s[1]<='9'){
            F[1] = 1;
        }
        int sub  = stoi(s.substr(0,2));
        if(sub >=10 && sub <27){
            F[1]++;
        }
        for(int i = 2;i<s.size();i++){
            if(s[i]>='1' && s[i]<='9')
                F[i] = F[i-1];   
            sub = stoi(s.substr(i-1,2));
            if(sub>=10 && sub<27)
                F[i]+=F[i-2];
        }
        return F[s.size()-1];
    }
};