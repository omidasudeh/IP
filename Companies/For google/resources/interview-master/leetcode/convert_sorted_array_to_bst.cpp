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
    TreeNode *balancedBST(vector<int>&num, int l, int r) {
        if (l > r) return NULL;
        int m = (l + r) / 2;
        TreeNode *root = new TreeNode(num[m]);
        root->left = balancedBST(num, l, m - 1);
        root->right = balancedBST(num, m + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = num.size() - 1;
        return balancedBST(num, l, r);
    }
};
