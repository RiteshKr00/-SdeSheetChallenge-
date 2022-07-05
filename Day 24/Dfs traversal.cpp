// T.C: O(V+E) to  visit nodes and traversel all edges 
//S.C : O(V+E)+O(N)

void dfs(vector<int> &temp,int node,vector<int>& visited,vector<int> adj[]){
    temp.push_back(node);
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it])
            dfs(temp,it,visited,adj);
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<int> visited(V,0);
    //create the adjacency list
    vector<int>adj[V];
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
           vector<int> temp;
            dfs(temp,i,visited,adj);
            ans.push_back(temp);
        }
    }
    return ans;
}