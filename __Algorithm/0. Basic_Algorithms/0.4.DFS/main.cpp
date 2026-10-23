#include <iostream>
#include <unordered_set>
using namespace std;
// dfs and topological sort
class solution{
    private:
    unordered_set<int> visited;

    public:
    solution( vector<vector<int>>& graph)
    {
        for(int i = 0; i<graph.size(); i++)
        {
            if(visited.find(i)==visited.end()) // if not visited
                dfs(graph, i);
        }
    }
    void dfs(vector<vector<int>>& graph, int i)
    {
        visited.insert(i);
        for(int j:graph[i])
        {
            if(visited.find(j)==visited.end()) // if j not visited 
                dfs(graph,j);
        }
        cout<<i<<"<--";
    }    
    
};


int main(int argc, char* argv[]) {
    vector<vector<int>> graph{{4,5,1},{5,3},{},{2},{5},{}};
    solution* s = new solution(graph);
    cout<<endl;
    return 0;
}