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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode*> q;
        queue<int> depth;
        vector<vector<int> > ans;
        if (!root) return ans;
        q.push(root);
        depth.push(0);
        while (!q.empty()) {
            TreeNode *c = q.front();
            q.pop();
            int dep = depth.front();
            depth.pop();
            if (dep >= ans.size()) ans.push_back(vector<int>());
            ans[dep].push_back(c->val);
            if (c->left) {
                q.push(c->left);
                depth.push(dep + 1);
            }
            if (c->right) {
                q.push(c->right);
                depth.push(dep + 1);
            }
        }
        int d = ans.size();
        for (int i = 0; i < d / 2; ++i) {
            swap(ans[i], ans[d - 1- i]);
        }
        return ans;
    }
};
