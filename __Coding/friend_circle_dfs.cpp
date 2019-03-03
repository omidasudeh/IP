/*
/home/omid/Dropbox/Interview_practice/__Coding/merge_intervals.cpp
 */

class Solution {
public:
    void dfs(vector<vector<int>>& grid,unordered_set<int>& visited, int& i){
        visited.insert(i);
        for(int j = 0;j<grid[0].size();j++)
            if(grid[i][j] && visited.find(j) == visited.end())
                dfs(grid, visited,j);
    }
    int findCircleNum(vector<vector<int>>& grid) {
       // run dfs and count the circles 
        unordered_set<int> visited;
        int m = grid.size();
        int count = 0;
        for(int i = 0;i<m;i++)
            if(visited.find(i) == visited.end()){// if found a new circle
                    dfs(grid, visited,i);
                    count++;
            }
        return count;
    }
};