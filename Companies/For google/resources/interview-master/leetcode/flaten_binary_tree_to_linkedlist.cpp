/*
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *flat(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) return root;
        TreeNode *r;
        if (root->left) {
            TreeNode *flatleft = flat(root->left);
            flatleft->right = root->right;
            if (root->right) r = flat(root->right);
            else r = flatleft;
            root->right = root->left;
            root->left = NULL;
            return r;
        }
        if (root->right) return flat(root->right);
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        flat(root);
    }
};
