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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<vector<TreeNode *> > > trees(n + 1, vector<vector<TreeNode*> >(n + 1, vector<TreeNode*>(0)));
        trees[0][0].push_back(NULL);
        if (n == 0) return trees[0][0];
        for (int i = 1; i <= n; ++i) {
            TreeNode *root = new TreeNode(i);
            trees[i][i].push_back(root);
        }
        for (int step = 1; step < n; ++step) {
            int left = 1, right = left + step;
            for (; right <= n; ++left, ++right) {
                for (int x = left; x <= right; ++x) {
                    if (x == left) {
                        for (int j = 0; j < trees[x + 1][right].size(); ++j) {
                            TreeNode* root = new TreeNode(x);
                            root->right = trees[x + 1][right][j];
                            trees[left][right].push_back(root); 
                        }
                        continue;
                    }
                    if (x == right) {
                        for (int i = 0; i < trees[left][x - 1].size(); ++i) {
                            TreeNode *root = new TreeNode(x);
                            root->left = trees[left][x - 1][i];
                            trees[left][right].push_back(root);
                        }
                        continue;
                    }
                    for (int i = 0; i < trees[left][x - 1].size(); ++i) {
                        for (int j = 0; j < trees[x + 1][right].size(); ++j) {
                            TreeNode* root = new TreeNode(x);
                            root->left = trees[left][x - 1][i];
                            root->right = trees[x + 1][right][j];
                            trees[left][right].push_back(root);
                        }
                    }
                }
            }
        }
        return trees[1][n];
    }
};
