/*695. Max Area of Island
Medium

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/
class Solution {
public:
    int dfs(vector<vector<int>>& grid,unordered_set<int>& visited, int i, int j){
        cout<<i<<":"<<j<<endl;
        int m = grid.size();
        int n = grid[0].size();
        visited.insert(i*n+j);
        int area = 0;
        if(i-1 >= 0 && grid[i-1][j] && visited.find((i-1)*n+j) == visited.end())
            area+= dfs(grid,visited,i-1, j);
        if(j-1 >= 0 && grid[i][j-1] && visited.find(i*n+j-1) == visited.end())
            area+= dfs(grid,visited,i, j-1);
        if(i+1 < m && grid[i+1][j] && visited.find((i+1)*n+j) == visited.end())
            area+= dfs(grid,visited,i+1, j);
        if(j+1 < n && grid[i][j+1] && visited.find(i*n+j+1) == visited.end())
            area+= dfs(grid,visited,i, j+1);
        return 1+area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // does dfs and keep track of the visited cells avoiding revisiting an island
        // keep track of max area
        // O(n2) time and space
        unordered_set<int> visited;
        int m = grid.size();
        int n = grid[0].size();
        int Max_area = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                // cout<<i<<":"<<j<<endl;
                if(grid[i][j] && visited.find(i*n+j) == visited.end()){// if found a new island
                    // cout<<"here\n";
                    int area = dfs(grid, visited,i,j);
                    Max_area = max(area, Max_area);
                }
            }
        }
        return Max_area;
    }
};