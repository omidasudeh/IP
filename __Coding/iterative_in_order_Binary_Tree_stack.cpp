/*this is to do a iterative in-order traversal on a binary tree*/
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

void in(node* t){
    if(t == NULL) return;
    vector<node*> stk;
    stk.push_back(t);
    node* cur = stk.back();
    while(cur!= NULL || !stk.empty()){
        while(cur!=NULL){
            cur = cur->left;
            stk.push_back(cur);
        }
        cur = stk.back();
        cout<<cur->val<<" ";

        stk.pop_back();
        cur = cur->right;
    }
}
int main(){
    
    return 0;
}