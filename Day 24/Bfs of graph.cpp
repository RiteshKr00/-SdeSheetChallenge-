// T.C: O(V+E) to  visit nodes and traversel all edges 
//S.C : O(V+E)+O(N)
#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
     vector<int> ans;
    vector<int> visited(vertex,0);
    //create the adjacency list
    vector<int>adj[vertex];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    //sort to get answer in ascending order
    for(int i = 0; i < vertex; i++)
           sort(adj[i].begin(),adj[i].end());
    
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        }        
    }
    return ans;
    
    
}