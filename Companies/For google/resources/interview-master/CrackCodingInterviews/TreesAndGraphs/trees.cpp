#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left, *right;
    TreeNode(int v, TreeNode *l = NULL, TreeNode *r = NULL) : value(v), left(l), right(r) {}
};

int height(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root) {
    if (!root) return true;
    return abs(height(root->left) - height(root->right)) <= 1;
}

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    cout << isBalanced(root) << endl;
    cout << height(root) << endl;
    return 0;
}
