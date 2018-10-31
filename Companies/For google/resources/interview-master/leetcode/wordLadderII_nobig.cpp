// Word LadderII
// graph based method
class Solution {

public:
    int n;
    vector<vector<int>> g;
    vector<vector<int>> p;
    vector<vector<vector<int>>> pt;
    
    int trans(string a, string b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) ++diff;
        }
        return diff;
    }
    
    
    void bfs(int s, int e) {
       queue<int> q;
       vector<bool> visited = vector<bool>(n, false);
       q.push(s);
       pt[s].push_back(vector<int>(1, s));
       vector<int> depth = vector<int>(n, 0);
       
       int min_depth = 0;
       int num = 0;
       bool find = false;
       
       while (!q.empty()) {
           int current = q.front();
           q.pop();
           if (visited[current]) continue;
           visited[current] = true;
           
           for (int i = 0; i < g[current].size(); ++i) {
               if (!visited[g[current][i]]) {
                    
                    if (pt[g[current][i]].size() > 0 && pt[g[current][i]][0].size() < pt[current][0].size() + 1) continue;                   
                    depth[g[current][i]] = depth[current] + 1;             
                    for (int j = 0; j < pt[current].size(); ++j) {
                        vector<int> newp = pt[current][j];
                        newp.push_back(g[current][i]);
                        pt[g[current][i]].push_back(newp);
                    }
                    
                    if (g[current][i] == e) {
                        if (!find) {
                            min_depth = depth[g[current][i]];
                            find = true;
                        }
                        else if (depth[g[current][i]] > min_depth) continue;
                        for (int j = 0; j < pt[current].size(); ++j) {
                            vector<int> newp = pt[current][j];
                            newp.push_back(g[current][i]);
                            p.push_back(newp);
                        }
                    }
                    else q.push(g[current][i]);
               }
           }
       }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ans = vector<vector<string>>();
        n = dict.size();
        vector<string> d = vector<string>();
        g = vector<vector<int>>(n, vector<int>());
        p = vector<vector<int>>();
        pt = vector<vector<vector<int> > >(n, vector<vector<int>>());
        
        int s, e;
        unordered_set<string>::iterator iter = dict.begin();
        for (int i = 0; i < n; ++i) {
            d.push_back(*iter);
            if ((*iter) == start) s = i;
            if ((*iter) == end) e = i;
            ++iter;
        }
        
        vector<int> difflevel;
        
        for (int i = 0; i < n; ++i) {
            difflevel.push_back(trans(start, d[i]));
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (trans(d[i], d[j]) == 1) {
                    if (difflevel[i] < difflevel[j]) g[i].push_back(j);
                    else if (difflevel[j] < difflevel[i]) g[j].push_back(i);
                    else {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                
                }
            }
        }
        bfs(s, e);
        
        for (int i = 0; i < p.size(); ++i) {
            vector<string> ladder = vector<string>();
            for (int j = 0; j < p[i].size(); ++j) {
                ladder.push_back(d[p[i][j]]);
            }
            ans.push_back(ladder);
        }
        return ans;
    }
};
// Large Data method
