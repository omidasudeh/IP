/*
127. Word Ladder
Medium

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */
class Solution {
public:
    bool neighbor(string s1, string s2){
        int distance = 0;
        for(int i = 0;distance<2 && i<s1.size();i++){
            if(s1[i]-s2[i]!=0)
                distance++;
        }
        return distance<2;
    }
    int bfs(vector<vector<int>>& graph, int src, int dist){
        queue<pair<int,int>> q; // pair<node,level>
        unordered_set<int> visited;
        q.push(pair<int, int>(src,1));
        visited.insert(src); 
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            vector<int> adj = graph[cur.first];
            for(int neighbor:adj){
                if(neighbor == dist)
                    return cur.second+1;//found
                if(visited.find(neighbor) == visited.end()){//not already visited
                    visited.insert(neighbor);
                    q.push(pair<int,int>(neighbor,cur.second+1));
                }
            }
        }
        return 0;//not found
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // this is sssd shortest path problem
        // graph = to_graph(wordlist)
        int src  = -1;
        int dist = -1;
        for(int i = 0 ;i<wordList.size();i++){
            if(wordList[i] == beginWord){
                src = i;
            }
            if(wordList[i] == endWord){
                dist = i;
            } 
        }
        if(dist == -1)
            return 0;
        if(src == -1){
            wordList.push_back(beginWord);
            src = wordList.size()-1;
        }
            
        vector<vector<int>> graph(wordList.size(), vector<int>(0,0));
        for(int i = 0; i<wordList.size();i++)
            for(int j = 0;j<wordList.size();j++){
                if(i!=j && neighbor(wordList[i],wordList[j])){
                    if(graph[i].size() > 0){
                        graph[i].push_back(j);
                    }
                    else{
                        vector<int> t;
                        t.push_back(j);
                        graph[i] = t;
                    }
                }
            }
        return bfs(graph,src,dist);
    }
};