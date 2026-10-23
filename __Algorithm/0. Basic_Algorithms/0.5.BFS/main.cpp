#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
// bfs and level order
class solution{
    private:
    unordered_set<int> visited;
    queue<int> Q;

    public:
    solution( vector<vector<int>>& graph)
    {
        for(int i = 0; i<graph.size(); i++)
        {
            if(visited.find(i)==visited.end())
            {
                Q.push(i);
                visited.insert(i);
                BFS(graph);
            }
        }
    }
    void BFS(vector<vector<int>>& graph)
    {
        while(Q.size())
        {
            int level_size = Q.size();
            for(int li = 0; li<level_size; li++)
            {
                int head = Q.front();
                Q.pop();            
                cout<<head<<",";
                for(int i : graph[head])
                {
                    if(visited.find(i)==visited.end())
                    {
                        Q.push(i);
                        visited.insert(i);
                    }
                }
            }
            cout<<"\n";
        }
    }    
};


int main(int argc, char* argv[]) {
    vector<vector<int>> graph{{1,2,4},{3,4},{5},{},{},{},{7,8},{8},{}};
    solution* s = new solution(graph);
    cout<<endl;
    return 0;
}