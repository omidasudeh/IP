//////////////////////////////// data structures implementation 

class myQ
{
    private:
    int* Q;
    int size;
    int front;
    int tail;

    public:
    myQ(int size=100):size(size), front(-1), tail(-1)
    {
        Q = new int[size];
    }

    ~myQ()
    {
        delete[] Q;
    }

    bool isFull()
    {
        return (tail+1)%size == front;
    }

    bool isEmpty()
    {
        return (front == -1) && (tail == -1);
    }

    bool push_back(int item)
    {
        if(!isFull())
        {
            tail = (tail+1)%size;
            Q[tail] = item;
            if(front==-1) front++;
            return true;
        }
        return false;
    }

    int pop_front()
    {
        if(!isEmpty())
        {
            int v = Q[front];
            if (front == tail) // last element
                front = tail = -1; // reset to empty
            else
                front = (front+1)%size;

            return v;
        }
        cout<<"Err: cant remove from an empty Q\n"; // ideally we should throw err
        return -1;
    }

};

class myStack
{
    private:
    int* S;
    int size;
    int top;

    public:
    myStack(int size=100):size(size),top(-1){S = new int[size];}
    ~myStack()
    {
        delete[] S;
    }
    bool isEmpty()
    {
        return(top==-1);
    }

    bool isFull()
    {
        return (top==(size-1));
    }

    bool push(int item)
    {
        if(!isFull())
        {
            top++;
            S[top] = item;
            return true;
        }
        return false;
    }

    bool pop(int& item)
    {
        if(!isEmpty())
        {
            item = S[top];
            top--;
            return true;
        }
        return false;
    }

};

class myMinHeap
{
    private:
    vector<int> mh;
    void heapify(int i)
    {
        int c1 = 2*i+1; 
        int c2 = 2*i+2; 
        if(c1 >= mh.size()) return; // no child
        if(c2 >= mh.size()) // only one child
        {
            if(mh[c1] < mh[i])
            {
                int t = mh[i];
                mh[i] = mh[c1];
                mh[c1] = t;
                return;
            }
            else return;
        } 
        int minC = c1;
        if(mh[c2] < mh[c1]) minC = c2;
        if(mh[minC] < mh[i])
        {
            int t = mh[i];
            mh[i] = mh[minC];
            mh[minC] = t;
            heapify(minC);
        } 
    }
    public:
    myMinHeap(){}

    ~myMinHeap()
    {}

    bool get_min(int& min)
    {
        if(mh.size())
        {
            min = mh[0];
            return true;
        }
        return false;
    }

    bool delete_min()
    {
        if(mh.size())
        {
            mh[0] = mh[mh.size()-1];
            mh.pop_back();
            heapify(0);
            return true;
        }
        return false;
    }

    void insert(int item)
    {
        mh.push_back(item);
        int i = mh.size()-1;
        int p = ceil(i/2.0)-1;
        while(p>=0 && mh[i] < mh[p])
        {
            int t = mh[p];
            mh[p] = mh[i];
            mh[i] = t;
            i = p;
            p = ceil(i/2.0)-1;
        }
    }
};

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

class myHT
{
    // open addressing linear probing
    private:
    int* container;
    int* keys;
    int capacity;
    int size;
    float loadFactor;
    void rehash()
    {
        int newCap = capacity*2;
        int* newCon = new int[newCap];
        int* newKeys = new int[newCap];
        for(int i = 0; i< newCap; i++) newKeys[i]=-1;// -1 means not occupied
        
        int* old_cont = container;
        int* old_keys = keys;
        int old_capacity = capacity;

        container = newCon;
        keys = newKeys;
        size = 0;
        capacity = newCap;
        
        for(int i = 0; i<old_capacity; i++)
        {
            if(old_keys[i]>=0)      
                Insert(old_keys[i], old_cont[i]);
        }

        delete[] old_cont;
        delete[] old_keys;
    }
    public:
    myHT(int c =100, float lf=1.0):capacity(c), size(0), loadFactor(lf)
    {
        assert(loadFactor <= 1.0);
        container = new int[capacity]; 
        keys = new int[capacity];
        for(int i = 0; i< capacity; i++) keys[i]=-1;// -1 means not occupied
    }
    ~myHT(){delete[] container;delete[] keys;}

    void Insert(int key, int val)
    {
        float nextDensity = (size+1)/(float)capacity;
        if(nextDensity > loadFactor)
            rehash();
        int id = key%capacity;
        // because we checked the density we are sure there is room so the while loop exits and not infintely running
        while(keys[id]>=0) 
        {
            if(keys[id]!=key)
                id = (id+1)%capacity;
            else
            {
                container[id] = val;        
                return; 
            }
        }
        keys[id] = key;
        container[id] = val;        
        size++;
    }
    bool find(int key, int& val)
    {
        int id = key%capacity;
        if(keys[id]==-1) return false; // not found
        int i = 0;
        while(i < size && keys[id]>=0) 
        {
            if(keys[id]!=key)
                id = (id+1)%capacity;
            else
            {
                val = container[id];
                return true;
            }
            i++;
        }
        return false; 
    }

    void Delete(int key)
    {
        int id = key%capacity;
        if(keys[id]==-1) return; // not found
        int i = 0;
        while(i < size && keys[id]>=0) 
        {
            if(keys[id]!=key)
                id = (id+1)%capacity;
            else
            {
                keys[id]=-1;
                size--;
                return;
            }
            i++;
        }
    }

};


class BST
{

};

//////////////////////////////// basic Graph algorithms 
// dfs, bfs/level-order
class graph
{
    private:
    unordered_set<int> visited;
    queue<int> Q;
    public:
    void dfs(vector<vector<int>>& edges)
    {
        for(int i=0; i<edges.size(); i++)
        {
            if(visited.find(i) == visited.end()) // not visited
                dfs(edges, i);
        }
    }

    void dfs(vector<vector<int>>& edges, int node)
    {
        visited.insert(node);
        for(int i : edges[node]) // for i in adj(node)
        {
            if(visited.find(i) == visited.end()) // not visited
                dfs(edges, i);
        }
    }

    void bfs(vector<vector<int>>& edges)
    {
        for(int i=0; i<edges.size(); i++)
        {
            if(visited.find(i) == visited.end()) // not visited
            {
                Q.push(i);
                bfs(edges, i);
            }
        }
    }

    void bfs(vector<vector<int>>& edges, int node)
    {
        while(!Q.empty())
        {
            int level_size = Q.size();
            for(int i = 0; i<level_size; i++)
            {
                int head = Q.front();
                Q.pop();
                for(int j : edges[head])
                {
                    if(visited.find(j) == visited.end()) // not visited
                    {
                        Q.push(j);
                        visited.insert(i);
                    }
                }
            }
        }
    }
};
//////////////////////////////// data structures application via CPP libraries
// minheap
struct cmp
{
    bool operator()(pair<int,int> left, pair<int,int> right)
    {
        // makes a descending sort (makes sense a>b>c...>x x is smallest); this makes a minheap (in PQ, righthandside is always prior both in a<b and a>b)
        return left.second > right.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> min_heap;

//////////////////////////////// CPP OOP practice
// practice: 
    //1. inheretence, virtual and friend, 
    //2. function and operator overloading

    class parent
    {
        private:
            int p;
        public:
            parent(int p=1):p(p){}
            virtual void work(int x=13){p=3*x;}
            // virtual void work()=0; // parent work being a pure method makes it abstract class; work does nothing but make work overridable; once pure function is enough to make it abstract and non-instantitable
            virtual ~parent(){}
    };
    class myFriend;
    class child:public parent
    {
        private:
            int c1;
        public:
            child(int x=12):c1(x){}
            void work(int x=18){c1=10*x;} // overridding the work
            ~child(){}
            friend myFriend;

    };
    class myFriend
    {
        private:
            int f1;
        public:
            myFriend(){}
            void test()
            {
                child chi(11);
                chi.c1 = 10;
            }
    };

    int main(int argc, char** argv)
    {
        parent* p;
        p = new child(22);
        p->work(); // this should run child work
        delete p; // first child destructor then parent destructor; 
        myFriend f;
        f.test();
        return 0;
    }
//////////////////////////////// basic binary search and sorts
struct cmp1
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {        
        return a.second < b.second;
    }
};
vector<pair<int,int>> items{{1,2},{3,4},{2,1}};
sort(items.begin(), items.end(), cmp1()); // sorts ascending