/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
// approach 1: uses c++ insert function   O(n!) time and space
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0){
            vector<vector<int> > ans;
            vector<int> t;
            ans.push_back(t);
            return ans;
        }
        return permute_help(nums,0);
    }
    vector<vector<int> > permute_help(vector<int> &A, int ind) {
        vector<vector<int> > ans;
        if(ind == (A.size()-1)){ //base
            vector<int> t;
            t.push_back(A[ind]);
            ans.push_back(t);
            return ans;
        }// recurrance
        vector<vector<int> > pre = permute_help(A, ind+1);
        for(vector<int> item : pre){
            for(int i = 0;i<=item.size();i++){
                vector<int> t = item;
                t.insert(t.begin()+i,A[ind]);
                ans.push_back(t);
            }
        }
        return ans;
    }
};
// approach 2 swap based
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permuteRecursive(num, 0, result);
        return result;
    }
 
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin == num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
 
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};