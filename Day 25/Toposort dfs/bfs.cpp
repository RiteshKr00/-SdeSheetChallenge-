/*dfs
t.c-:O(V+E)
intution is first print those no which are parent then its child
use stack and travese the graph and push first child in stack then do dfs and then push
the node in stack.This ensures child always comes after parent 
during stack pop and print
*/
#include<bits/stdc++.h>
void findTopsort(vector<int>adj[],stack<int>& s,vector<int>&vis,int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])
        findTopsort(adj,s,vis,it);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //build adjacency list
    vector<int> visited(v,0);
    //create the adjacency list
    vector<int>adj[v];
    for(int i=0; i<e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
//         adj[edges[i][1]].push_back(edges[i][0]);
    }
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
          findTopsort(adj,s,visited,i);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}