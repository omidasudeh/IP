/*
this is to do a iterative post-order traversal on a binary tree
the difference is that it first pushes the left child instead of the right child and also 
reverses the result at the end;
*/
#include <vector>
#include <iostream>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node(int v):val(v), left(NULL), right(NULL){;}
};

void post(node* t, vector<int>& solution){
    if(t == NULL) return;
    vector<node*> stk;
    stk.push_back(t);
    vector<int> result;
    while(!stk.empty()){
        node* top = stk.back();
        stk.pop_back();
        result.push_back(top->val);
        if(top->left)
            stk.push_back(top->right);
        if(top->right)
            stk.push_back(top->left);
    }
    // solution = reverse(result); // the result has the post order in a reverse order
}
int main(){
    
    return 0;
}