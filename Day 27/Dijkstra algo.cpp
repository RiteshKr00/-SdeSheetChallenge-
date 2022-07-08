/*
T.C:O((E+V)logV) in case of matrices O(V^2)
S.C->O(N)+O(N)+O(v+E)
simple shortest path with weight but to find  shortest path to a node 
from current node optimally we use a priority queue.
____BFS____way
1 push src in queue
2 iterate adjacent node of front of queue
3 Update the node dist to min possible and push updated node in pq;

*/


#include<bits/stdc++.h>
typedef pair<int, int> pi;
void dijkstra(vector<pair<int,int>>adj[],vector<int>&dist,priority_queue<pi, vector<pi>, greater<pi> > pq,int v,int src){
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto it:adj[u]){
            int node=it.first;
            int weight=it.second;
            if(dist[node]>weight+dist[u]){
                dist[node]=weight+dist[u];
                pq.push(make_pair(dist[node],node));
            }
        }
    }
    
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
     vector<pair<int,int>>adj[vertices];
    for(int i=0;i<edges;i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    vector<int>dist(vertices,INT_MAX);
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    
    dijkstra(adj,dist,pq,vertices,0);
    
    
    return dist;
}
