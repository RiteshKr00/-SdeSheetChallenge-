//DFS
bool isCyclic(vector<int> adj[],vector<int> &vis,int v,int parent){

	vis[v] =1;

	for(int child : adj[v]){

		if(!vis[child]){

			if(isCyclic(adj,vis,child,v)) return true;

		}

		else if(child != parent){

			return true;

		}

	}

	return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)

{

    // Write your code here.

	vector<int> adj[n+1];

	for(int i = 0;i<m;i++){

		adj[edges[i][0]].push_back(edges[i][1]);

		adj[edges[i][1]].push_back(edges[i][0]);

	}

	vector<int> vis(n+1,0);

	for(int i =1;i<=n;i++){

		if(!vis[i] && isCyclic(adj,vis,i,-1)){

			return "Yes";

		}

	}

	return "No";
}

//BFS
bool isCyclic(vector<int> adj[],vector<bool> &vis,int N,int s){
        queue<pair<int,int>> q;
        q.push({s,-1});
        vis[s]=true;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=true;
                }else{
                    if(par!=it){
                        return true;
                    }
                }
            }
        }
        return false;
        
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] &&isCyclic(adj,vis,V,i)){
               return true;
            }
            
        }
        return false;
        
    }