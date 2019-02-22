/*
49. Group Anagrams
Medium

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams; 
        for(string str:strs){
            string t(str);
            sort(t.begin(), t.end());
            if(anagrams.find(t) == anagrams.end()){
                vector<string>temp;
                temp.push_back(str);
                anagrams[t] = temp;
            }
            else{
                anagrams[t].push_back(str);
            }
        }
        vector<vector<string>> ans;
        for(auto keyVal:anagrams){
            ans.push_back(keyVal.second);
        }
        return ans;
    }
};