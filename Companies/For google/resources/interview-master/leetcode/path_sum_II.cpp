/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pathSum(TreeNode *root, int c, int target, vector<int> cur, vector<vector<int> > &ans) {
        if (!root) return;
        c += root->val;
        cur.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (c == target) ans.push_back(cur);
            else return;
        }
        pathSum(root->left, c, target, cur, ans);
        pathSum(root->right, c, target, cur, ans);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> cur;
        if (root) {
            pathSum(root, 0, sum, cur, ans);
        }
        return ans;
    }
};
