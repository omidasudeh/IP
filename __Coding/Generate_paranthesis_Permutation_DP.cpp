/*
22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n==0)
            return result;
        if(n==1)
        {
            result.push_back("()");
            return result;
        }
        vector<string> pre = generateParenthesis(n-1);
        unordered_set<string> map;
        for(int j = 0;j<pre.size();j++)
        {
            string elem = pre[j];
            int n = elem.size();
            for(int i = 0;i<n;i++)
            {
                string new_elem = elem;
                new_elem.insert(i,"()");
                if(map.find(new_elem)==map.end()){
                    map.insert(new_elem);
                    result.push_back(new_elem);
                }
            }
        }
        return result;
    }
};