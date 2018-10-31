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
    TreeNode *build(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2) {
        if (l1 > r1) return NULL;
        if (l1 == r1) {
            TreeNode *root = new TreeNode(postorder[r2]);
            return root;
        }
        TreeNode *root = new TreeNode(postorder[r2]);
        for (int i = r1; i >= l1; --i) {
            if (inorder[i] == postorder[r2]) {
                int right = r1 - i;
                root->right = build(inorder, i + 1, r1, postorder, r2 - right, r2 - 1);
                root->left = build(inorder, l1, i - 1, postorder, l2, r2 - right - 1);
                break;
            }
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
