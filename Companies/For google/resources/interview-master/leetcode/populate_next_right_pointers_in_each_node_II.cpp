#include <iostream>

using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    TreeLinkNode* findnext(TreeLinkNode *root) {
        if (!root) return NULL;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return findnext(root->next);
    }
    void connect(TreeLinkNode *r) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeLinkNode*> q;
        q.push(r);
        while (!q.empty()) {
            TreeLinkNode *root = q.front();
            q.pop();
            if (!root) continue;
            if (root->left) {
                if (root->right) {
                    root->left->next = root->right;
                }
                else root->left->next = findnext(root->next);
            }
            if (root->right) root->right->next = findnext(root->next);
            q.push(root->left);
            q.push(root->right);
        }
    }
};

void printnext(TreeLinkNode *root) {
	if (root == NULL) return;
	if (root->next) cout << root->next->val << endl;
	else cout << "NULL" << endl;
	printnext(root->left);
	printnext(root->right);
}

int main() {
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);
	Solution s;
	s.connect(root);
	printnext(root);
	return 0;
}