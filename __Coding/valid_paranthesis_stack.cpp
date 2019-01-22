/* 
Given a string containing just the characters
 '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/
// version 1
class Solution {
public:
    char open(char ch)
    {
        if(ch == '}')
            return '{';
        if(ch == ']')
            return '[';
        if(ch == ')')
            return '(';
        return -1;//invalid input
    }
    bool isValid(string s) {
        string stk ="";
        int i = 0;
        for(;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '['||ch=='{'||ch=='(')
                stk.push_back(ch);
            else
            {
                if(stk[stk.size()-1]!=open(chy))
                   return false;
                else
                    stk.pop_back();
            }
        }
        return (stk.size()== 0);
    }
};

// version 2

class Solution {
public:
    char open(char ch)
    {
        if(ch == '}')
            return '{';
        if(ch == ']')
            return '[';
        if(ch == ')')
            return '(';
        return -1;//invalid input
    }
    bool isValid(string s) {
        string stk ="";
        int i = 0;
        for(;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '['||ch=='{'||ch=='(')
                stk.push_back(ch);
            else
            {
                bool match = stk.back()==open(ch);
                while(!match && stk.size()>0)
                    stk.pop_back();
                if(!match)
                   return false;
                else
                    stk.pop_back();
            }
        }
        return (stk.size()== 0 && i == s.size());
    }
};