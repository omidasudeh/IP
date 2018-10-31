// Sum root to leaf numbers
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
int sum;

void previsit(TreeNode *p, int n) {
    int num = n * 10 + p->val;
    if (p->left) previsit(p->left, num);
    if (p->right) previsit(p->right, num);
    if (!(p->left) && !(p->right)) {
        sum += num;
    }
}

    int sumNumbers(TreeNode *root) {
        sum = 0;
       if (root) {
           previsit(root, 0);
       }
       return sum;
    }
};
