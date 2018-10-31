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
    int calsum(TreeNode *root, int &ans) {
        int f = 0;
        if (root == NULL) return f;
        int left = calsum(root->left, ans);
        int right = calsum(root->right, ans);
        ans = max(ans, left + right + root->val);
        ans = max(ans, left + root->val);
        ans = max(ans, right + root->val);
        f = max(0, max(left, right)) + root->val;
        return f;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        if (root) {
            ans = root->val;
            calsum(root, ans);
        }
        return ans;
    }
};
