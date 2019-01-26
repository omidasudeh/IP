/*this is to do a iterative pre-order traversal on a binary tree*/
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

void pre(node* t){
    if(t == NULL) return;
    vector<node*> stk;
    stk.push_back(t);
    while(!stk.empty()){
        node* top = stk.back();
        stk.pop_back();
        cout<<top->val<<" ";
        if(top->right)
            stk.push_back(top->right);
        if(top->left)
            stk.push_back(top->left);
    }
}
int main(){
    
    return 0;
}