//PalindromeII:
class Solution {
public:
    bool checkpa(const string &s, int i, int j) {
        if (i >= (j - 1)) return true;
        if (s[i] == s[j - 1]) return checkpa(s, i + 1, j - 1);
        return false;
    }
    const int infinity = 1e9;
    int n;
    int dijis(const vector<vector<int>> &G) {
        vector<int> D(n + 1, infinity);
        vector<bool> visited(n + 1, false);
        
        D[0] = 0;
        visited[0] = true;
        for (int i = 0; i < G[0].size(); i++) {
            const int v = G[0][i];
            D[v] = 1;
        }
        
        while (true) {
            int u = -1;
            for (int v = 0; v <= n; v++)
                if (!visited[v] && (u == -1 || D[v] < D[u]))
                    u = v;
            
            if (u == -1) break;
            visited[u] = true;
            
            for (int i = 0; i < G[u].size(); i++) {
                const int v = G[u][i];
                if (D[u] + 1 < D[v])
                    D[v] = D[u] + 1;
            }
        }
        return D[n];
        
        /*
        vector<int> min(n);
        for (int i = 0; i < n; ++i) {
            m[i][i] = 0;
            for (int j = 0; j < n; ++j) {
                min[i][j] = n;
            }
        }

        for (int i = 0; i < g[0].size(); ++i) {
                int v = g[0][i];
                min[u][v] = 1;
            }
        }
        
        return min[0][n];*/
    }
    
    int minCut(string s) {
        n = s.size();
        /*
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j)
                if (checkpa(s, i, j)) g[i].push_back(j);
        }
        */
        vector<vector<bool>> B(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= n; i++)
            B[i][i] = true;
        for (int i = 0; i + 1 <= n; i++)
            B[i][i + 1] = true;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l;
                B[i][j] = s[i] == s[j-1] && B[i+1][j-1];
            }
        }
        
        vector<vector<int>> G(n + 1, vector<int>());
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (B[i][j])
                    G[i].push_back(j);
        
        return dijis(G) - 1;
    }
};

