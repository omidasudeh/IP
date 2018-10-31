class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_multiset<string> anagrams;
        vector<string> ans;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            anagrams.insert(key(strs[i]));
        }
        for (string x : strs) {
            if (anagrams.count(key(x)) > 1)
                ans.push_back(x);
        }
        return ans;
    }
    
    string key(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};
