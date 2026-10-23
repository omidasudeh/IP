#include <iostream>
#include <vector>
using namespace std;
// Disjoint sets 

struct node{
    node* parent;
    int value;
    int height;
    node(node* p=NULL,  int v = 0, int h = 0):parent(p), value(v), height(h){;}
};

class DS
{
    private:
    public:
    DS(){;}
    node* find(node* a)
    {
        if(a && a->parent)
        {
            node* aStar = find(a->parent);
            a->parent = aStar;
            return aStar;
        }
        return a;
    }

    node*  Union(node* a, node* b)
    {
        if(!connected(a,b))
        {
            node* a_ = find(a);
            node* b_ = find(b);
            if(a_->height > b_->height)
            {
                b_->parent = a_;
                return a_;
            }
            else if (b_->height > a_->height)
            {
                a_->parent = b_;
                return b_;
            }
            else
            {
                b_->parent = a_;
                a_->height++ ;
                return a_;
            }
        }
    }

    bool connected(node* a, node* b)
    {
        return (find(a) == find(b));
    }
};

class solution{
    private:
    DS ds;
    vector<node> nodes;

    void check(int a, int b, bool expected)
    {
        bool got = ds.connected(&nodes[a], &nodes[b]);
        cout<<"connected("<<a<<","<<b<<") = "<<got<<"  expected "<<expected
            <<(got == expected ? "  OK" : "  WRONG")<<"\n";
    }

    // steps from a up to its root, without changing anything
    int depth(node* a)
    {
        int d = 0;
        while(a->parent)
        {
            a = a->parent;
            d++;
        }
        return d;
    }

    void printDepths()
    {
        for(int i = 0; i<nodes.size(); i++)
            cout<<i<<":"<<depth(&nodes[i])<<" ";
        cout<<"\n";
    }

    public:
    solution()
    {
        cout<<boolalpha;
        int n = 8;
        for(int i = 0; i<n; i++)
            nodes.push_back(node(NULL, i)); // no pointers taken until all are pushed

        vector<pair<int,int>> unions{{0,1},{2,3},{1,3},{4,5},{6,7},{5,7},{0,2}};
        for(auto& [a, b] : unions)
        {
            cout<<"Union("<<a<<","<<b<<")\n";
            ds.Union(&nodes[a], &nodes[b]);
        }

        check(0, 3, true);
        check(0, 4, false);
        check(4, 6, true);
        check(3, 7, false);

        cout<<"Union(3,4)\n";
        ds.Union(&nodes[3], &nodes[4]);
        check(0, 7, true);

        // path compression: after find on every node, every depth should be 0 or 1
        cout<<"depths before find: ";
        printDepths();
        for(int i = 0; i<n; i++)
            ds.find(&nodes[i]);
        cout<<"depths after find:  ";
        printDepths();
    }
};


int main(int argc, char* argv[]) {
    solution* s = new solution();
    return 0;
}