#include <iostream>
using namespace std;
// binary tree and traversals
// find the topk in a bst
class treenode
{
    private:
    treenode* left;
    treenode* right;
    int val;

    public:
    treenode(treenode* left, treenode* right, int v)
    {
        this->left = left; 
        this->right = right; 
        this->val=v;
    }

    void preorder()
    {
        cout<<val<<",";
        if(left) left->preorder();
        if(right) right->preorder();
    }
    void inorder()
    {
        if(left) left->inorder();
        cout<<val<<",";
        if(right) right->inorder();
    }
    void postorder()
    {
        if(left) left->postorder();
        if(right) right->postorder();
        cout<<val<<",";
    }

    void inorder(int& k)
    {
        if(k>0)
        {
            if(right) right->inorder(k);
            if(k>0)
            {
                cout<<val<<",";
                k--;
            }
            if(left) left->inorder(k);
        }
    }
};

class solution{
    private:
    public:
    solution(vector<int>& T, int& k)
    {
        treenode* root = makeTree(T,0);
        if(k>0 && root)
        {
            cout<<"run the topk:\n";
            // we need to do inorder k times
            root->inorder(k);
            cout<<endl;
        }
        else
        {
            if(root)
            {
                cout<<"run the traversals:\n";
                root->preorder();
                cout<<"\n=======\n";

                root->inorder();
                cout<<"\n=======\n";
                
                root->postorder();
                cout<<"\n=======\n";
            }
        }
    }  
    treenode* makeTree(vector<int> & T, int my_index)
    {
        treenode* root = NULL;
        if(T.size() && my_index < T.size())
        {
            treenode* left  = NULL;
            treenode* right = NULL;
            if(T[2*my_index+1]!=-1)
            {
                left = makeTree(T, 2*my_index+1);
            }
            if(T[2*my_index+2]!=-1)
            {
                right = makeTree(T, 2*my_index+2);
            }
            root = new treenode(left,right,T[my_index]);
        }
        return root;
    }
};


int main(int argc, char* argv[]) {
    vector<int> T = {0,1,2,3,4,-1,-1,-1,-1,5,6,-1,-1,-1,-1};
    int k = -1;
    solution* s = new solution(T,k);

    /* BST in heap layout: children of i are 2i+1, 2i+2; -1 = no node
                 50
              /      \
            30        70
           /  \      /  \
         20    40  60    80
        /        \         \
       10        45         90
    */
    vector<int> bst = {50,30,70,20,40,60,80,10,-1,-1,45,-1,-1,-1,90};
    k = 5; // for top-k
    cout<<"======================\n";
    solution* s1 = new solution(bst,k);
    return 0;
}