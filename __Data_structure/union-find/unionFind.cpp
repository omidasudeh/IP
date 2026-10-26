#include <iostream>
#include <vector>
using namespace std;

class UFNode
{
    private:
        UFNode* p;
        int val;
        int h;
    public:
    UFNode(int v=0, int h = 0):p(0), val(v), h(h) {}
    ~UFNode() {}
    bool connected(UFNode* b)
    {
        return (this->find()==b->find());
    }
    UFNode* uni(UFNode* b)
    {
        if(this->connected(b)) return this->find();
        UFNode* as = this->find();
        UFNode* bs = b->find();

        if(as->h > bs->h)
        {
            bs->p = as;
            return as;
        }
        else if (bs->h > as->h)
        {
            as->p = bs;
            return bs;
        }
        else
        {
            as->p = bs;
            bs->h++;
            return bs;
        }
    }

    UFNode* find()
    {
        if(!this || !this->p) return this;
        UFNode* star = this->p->find();
        this->p = star;
        return star; // path compression
    }

};

void check(vector<UFNode>& nodes, int a, int b, bool expected)
{
    bool got = nodes[a].connected(&nodes[b]);
    cout<<"connected("<<a<<","<<b<<") = "<<got<<"  expected "<<expected
        <<(got == expected ? "  OK" : "  WRONG")<<"\n";
}

int main(int argc, char* argv[]) {
    cout<<boolalpha;
    int n = 8;
    vector<UFNode> nodes;
    for(int i = 0; i<n; i++)
        nodes.push_back(UFNode(i)); // no pointers taken until all are pushed

    vector<pair<int,int>> unions{{0,1},{2,3},{1,3},{4,5},{6,7},{5,7},{0,2}};
    for(auto& [a, b] : unions)
    {
        cout<<"uni("<<a<<","<<b<<")\n";
        nodes[a].uni(&nodes[b]);
    }

    check(nodes, 0, 3, true);
    check(nodes, 0, 4, false);
    check(nodes, 4, 6, true);
    check(nodes, 3, 7, false);

    cout<<"uni(3,4)\n";
    nodes[3].uni(&nodes[4]);
    check(nodes, 0, 7, true);
    return 0;
}
