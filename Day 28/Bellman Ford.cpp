int bellmonFord(int N, int M, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(N+1,1e9);
    dist[src]=0;
    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            int u=edges[j][0];
                int v=edges[j][1];
                int weight=edges[j][2];
            //if source is itself at infinity then no need to cheeck
            if(dist[u]!=1e9 &&dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
            }
        }
    }
    
    return dist[dest];
    
}
// /T.C->O(E*V)