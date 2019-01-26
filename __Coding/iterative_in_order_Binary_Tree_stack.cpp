/*this is to do a iterative in-order traversal on a binary tree*/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        vector<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur!= NULL || !stk.empty()){
            while(cur!=NULL){
                stk.push_back(cur);
                cur = cur->left;
            }
            cur = stk.back();
            result.push_back(cur->val);
            stk.pop_back();
            cur = cur->right;
        }
        return result;
    }
};