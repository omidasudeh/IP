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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        queue<int> depth;
        queue<TreeNode*> q;
        q.push(root);
        depth.push(1);
        while (!q.empty()) {
            TreeNode *c = q.front();
            q.pop();
            int dep = depth.front();
            depth.pop();
            if (c->left) {
                q.push(c->left);
                depth.push(dep + 1);
            }
            if (c->right) {
                q.push(c->right);
                depth.push(dep + 1);
            }
            if (c->left == NULL && c->right == NULL) {
                return dep;
            }
        }
        return 0;
    }
};
