/*
67. Add Binary
Easy

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


 */
/*
cba s c
000 0 0  ai&bi
001 1 0
010 1 0
011 0 1
100 1 0  ai|bi
101 0 1
110 0 1
111 1 1
 si =  XNOR  
 ci = ~c&(ai&bi)|c&(ai|bi)
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        if(m == 0)
            return b;
        if(n == 0)
            return a;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string result = "";
        bool ci = false;
        int i = 0;
        for(;i<min(m,n);i++){
            bool ai = a[i]-'0';
            bool bi = b[i]-'0';
            bool si = (ai != (bi != ci));
            ci = (!ci&&(ai&&bi))||(ci&&(ai||bi));  
            result+=(si+'0');
        }
        if(m == n){
            result+=(ci?"1":"");
            reverse(result.begin(),result.end());
            return result;
        }
        else if(m<n){
            for(;i<b.size();i++){
                bool bi = b[i]-'0';
                bool si =( bi != ci);
                ci = (bi && ci);    
                result+=(si+'0');
            }
            result+=(ci?"1":"");
            reverse(result.begin(),result.end());
            return result;
        }
        else{
            for(;i<a.size();i++){
                bool ai = a[i]-'0';
                bool si = ( ai != ci);
                ci = (ai && ci);
                result+=(si+'0');
            }
            result+=(ci?"1":"");
            reverse(result.begin(),result.end());
            return result;
        }
    }
};