// Longest concecutive sequence
class Solution {
public:
    vector<vector<pair<int, pair<int, int> > > > m;
    const int MOD = 9877;
    
    int find(int index, int x) {
        for (int i = 0; i < m[index].size(); ++i) {
            if (m[index][i].first == x) return i;
        }
        return -1;
    }
    
    inline int f(int x) {
        while (x < 0) x += MOD;
        return x % MOD;
    }
    
    int hash(int n) {
        int k = f(n);
        
        if (find(k, n) != -1) return 0;
        
        int begin = n, end = n;
        
        int next = f(k + 1);
        int prev = f(k - 1);
        
        int i , j;
        if ((i = find(next, n + 1)) != -1) end = m[next][i].second.second;              
        if ((i = find(prev, n - 1)) != -1) begin = m[prev][i].second.first;
        
        int b = f(begin), e = f(end);
        if ((j = find(b, begin)) != -1) m[b][j].second.second = end;
        if ((j = find(e, end)) != -1) m[e][j].second.first = begin;
   
        m[k].push_back(make_pair(n, make_pair(begin, end)));
        return end - begin + 1;
    }
    
    int longestConsecutive(vector<int> &num) {
        m = vector<vector<pair<int, pair<int, int> > > >(MOD, vector<pair<int, pair<int, int> > >());
        
        int longest = 0;
        int lcs;
        for (int i = 0; i < num.size(); ++i) {
           if ((lcs = hash(num[i])) > longest) longest = lcs;
        }
        return longest;
    }
};
//Solution from Xiao
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,int> left, right;

        for (int i = 0; i < num.size(); i++) {
            int x = num[i];
            if (left.find(x) != left.end()) continue;

            int l = x, r = x;
            if (left.find(x - 1) != left.end()) {
                l = left[x - 1];
            }
            if (right.find(x + 1) != right.end()) {
                r = right[x + 1];
            }

            left[x] = l;
            right[x] = r;

            if (left.find(x - 1) != left.end()) {
                int prevLeft = left[x - 1];
                left[prevLeft] = l;
                right[prevLeft] = r;
            }

            if (right.find(x + 1) != right.end()) {
                int nextRight = right[x + 1];
                left[nextRight] = l;
                right[nextRight ] = r;
            }
        }

        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            int x = num[i];
            int l = left[x];
            int r = right[x];
            if (r - l + 1 > ans) {
                ans = r - l + 1;
            }
        }
        return ans;
    }
};



// Distroint set method
class Solution {
public:

    vector<int> parent, rank, size;

    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);
        if (xRoot == yRoot) return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        }
        else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        }
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }

        int newSize = size[xRoot] + size[yRoot];
        size[xRoot] = size[yRoot] = newSize;
    }

    int longestConsecutive(vector<int> &num) {
        parent = vector<int>(num.size());
        rank = vector<int>(num.size());
        size = vector<int>(num.size());

        for (int i = 0; i < num.size(); i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }

        unordered_map<int,int> valueToIndex;
        for (int i = 0; i < num.size(); i++) {
            int value = num[i];
            if (valueToIndex.find(value) != valueToIndex.end()) continue;
            valueToIndex[value] = i;

            if (valueToIndex.find(value - 1) != valueToIndex.end()) {
                Union(valueToIndex[value - 1], i);
            }
            if (valueToIndex.find(value + 1) != valueToIndex.end()) {
                Union(valueToIndex[value + 1], i);
            }
        }

        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            int root = Find(i);
            if (size[root] > ans) {
                ans = size[root];
            }
        }
        return ans;
    }
};
