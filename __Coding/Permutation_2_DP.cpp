/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

// 
class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        if (i == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (k!=i && num[i] == num[k]) continue; // skip duplicates
            swap(num[i], num[k]);
            recursion(num, i+1, res);
            // why don't we swap back?
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end()); // why do we sort?
        vector<vector<int>>res;
        recursion(num, 0, res);
        return res;
    }
};