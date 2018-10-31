//Parlidrome I
class Solution {
public:
    bool checkpa(const string &s, const int i, const int j) {
        if (i >= (j - 1)) return true;
        if (s[i] == s[j - 1]) return checkpa(s, i + 1, j - 1);
        return false;
    }
    
    int n;
    vector<vector<int>> G;
    vector<vector<int>> P;
    
    void dfs(const int u, vector<int> p) {
        p.push_back(u);
        if (u == n) {
            P.push_back(p);
        }
        else {
            for (int i = 0; i < G[u].size(); ++i) {
                const int v = G[u][i];
                dfs(v, p);
            }
        }
    }
    
    vector<string> mkpartition(const vector<int> &indexes, const string &s) {
        vector<string> v;
        for (int i = 0; i + 1 < indexes.size(); ++i) {
            const int begin = indexes[i];
            const int end = indexes[i+1];
            v.push_back(s.substr(begin, end - begin));
        }
        return v;
    }
    
    vector<vector<string>> partition(string s) {
        n = s.size();
        
        G = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < n; ++i)     
            for (int j = i + 1; j <= n; ++j)
                if (checkpa(s, i, j))
                    G[i].push_back(j);
        
        P = vector<vector<int>>();
        dfs(0, vector<int>());
        
        vector<vector<string>> R;
        for (int i = 0; i < P.size(); ++i) {
            R.push_back(mkpartition(P[i], s));
        }
        return R;
    }
};

